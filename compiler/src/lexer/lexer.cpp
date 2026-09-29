#include "patra/lexer/lexer.hpp"

#include <cctype>
#include <stdexcept>

namespace patra::lexer {

Lexer::Lexer(std::string source)
    : source_(std::move(source)) {
}

char Lexer::current() const {
    if (position_ >= source_.size()) {
        return '\0';
    }

    return source_[position_];
}

char Lexer::peek() const {
    if (position_ + 1 >= source_.size()) {
        return '\0';
    }

    return source_[position_ + 1];
}

void Lexer::advance() {
    if (position_ >= source_.size()) {
        return;
    }

    if (source_[position_] == '\n') {
        ++location_.line;
        location_.column = 1;
    } else {
        ++location_.column;
    }

    ++position_;
}

void Lexer::skipWhitespace() {
    while (current() == ' ' ||
           current() == '\t' ||
           current() == '\r' ||
           current() == '\n') {
        advance();
    }
}

Token Lexer::makeToken(
    TokenKind kind,
    std::size_t startOffset,
    SourceLocation startLocation
) const {
    return Token{
        kind,
        source_.substr(
            startOffset,
            position_ - startOffset
        ),
        startLocation
    };
}

Token Lexer::lexIdentifier() {
    const auto startOffset = position_;
    const auto startLocation = location_;

    while (std::isalnum(
               static_cast<unsigned char>(current())) ||
           current() == '_') {
        advance();
    }

    const auto text =
        source_.substr(
            startOffset,
            position_ - startOffset
        );

    if (text == "print") {
        return Token{
            TokenKind::KeywordPrint,
            text,
            startLocation
        };
    }

    return Token{
        TokenKind::Identifier,
        text,
        startLocation
    };
}

Token Lexer::lexString() {
    const auto startOffset = position_;
    const auto startLocation = location_;

    advance();

    while (current() != '\0' && current() != '"') {
        advance();
    }

    if (current() != '"') {
        throw std::runtime_error(
            "Unterminated string literal"
        );
    }

    advance();

    return makeToken(
        TokenKind::StringLiteral,
        startOffset,
        startLocation
    );
}

Token Lexer::lexNumber() {
    const auto startOffset = position_;
    const auto startLocation = location_;

    while (std::isdigit(
        static_cast<unsigned char>(current()))) {
        advance();
    }

    return makeToken(
        TokenKind::IntegerLiteral,
        startOffset,
        startLocation
    );
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;

    while (current() != '\0') {
        skipWhitespace();

        if (current() == '\0') {
            break;
        }

        if (std::isalpha(
                static_cast<unsigned char>(current())) ||
            current() == '_') {
            tokens.push_back(lexIdentifier());
            continue;
        }

        if (current() == '"') {
            tokens.push_back(lexString());
            continue;
        }

        if (std::isdigit(
                static_cast<unsigned char>(current()))) {
            tokens.push_back(lexNumber());
            continue;
        }

        const auto startLocation = location_;
        const auto startOffset = position_;

        advance();

        tokens.push_back(
            Token{
                TokenKind::Unknown,
                source_.substr(
                    startOffset,
                    position_ - startOffset
                ),
                startLocation
            }
        );
    }

    tokens.push_back(
        Token{
            TokenKind::EndOfFile,
            "",
            location_
        }
    );

    return tokens;
}

} // namespace patra::lexer