#pragma once

#include <cstddef>
#include <string>

namespace patra::lexer {

enum class TokenKind {
    EndOfFile,

    Identifier,
    StringLiteral,
    IntegerLiteral,

    KeywordPrint,

    Unknown
};

struct SourceLocation {
    std::size_t line = 1;
    std::size_t column = 1;
    std::size_t offset = 0;
};

struct Token {
    TokenKind kind = TokenKind::Unknown;
    std::string lexeme;
    SourceLocation location;
};

} // namespace patra::lexer