#include "patra/lexer/lexer.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout
            << "PATRA Compiler Bootstrap 0.1.0\n"
            << "Usage: patra <source.patra>\n";

        return 1;
    }

    const std::string filename = argv[1];

    std::ifstream file(filename);

    if (!file) {
        std::cerr
            << "Error: cannot open source file: "
            << filename
            << '\n';

        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    const std::string source = buffer.str();

    patra::lexer::Lexer lexer(source);

    const auto tokens = lexer.tokenize();

    for (const auto& token : tokens) {
        std::cout
            << static_cast<int>(token.kind)
            << " | "
            << token.lexeme
            << " | "
            << token.location.line
            << ':'
            << token.location.column
            << '\n';
    }

    return 0;
}