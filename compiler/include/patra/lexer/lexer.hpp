#pragma once

#include "patra/lexer/token.hpp"

#include <string>
#include <vector>

namespace patra::lexer {

class Lexer {
public:
    explicit Lexer(std::string source);

    std::vector<Token> tokenize();

private:
    char current() const;
    char peek() const;

    void advance();

    void skipWhitespace();

    Token lexIdentifier();
    Token lexString();
    Token lexNumber();

    Token makeToken(
        TokenKind kind,
        std::size_t startOffset,
        SourceLocation startLocation
    ) const;

private:
    std::string source_;
    std::size_t position_ = 0;
    SourceLocation location_;
};

} // namespace patra::lexer