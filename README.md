# PATRA (بيترا)

PATRA is a universal, multilingual programming language designed to combine high-level development with systems programming, low-level programming, Assembly integration, embedded development, and AI-assisted programming.

## Vision

PATRA aims to provide one coherent programming platform that can scale from applications to games, operating systems, embedded devices, RTOS environments, firmware, and low-level targets.

Core goals include a real compiler, Unicode-first multilingual syntax, Arabic/English/Arabizi language packs, customizable terminology, C/C++-style systems programming, Assembly integration, cross-platform targets, embedded/HAL support, and long-term self-hosting.

## Core Principle

Human-language syntax is a front-end concern. PATRA Core uses stable internal semantic identities such as `PATRA_PRINT`, `PATRA_INTEGER`, `PATRA_FUNCTION`, and `PATRA_IF`. Language packs map written forms to those identities.

## First Vertical Slice

```patra
اطبع "أهلاً بالعالم"
```

Pipeline: Source → Lexer → Parser → AST → Semantic Analysis → IR → Code Generation → Windows x64 executable.

## Repository Layout

```text
compiler/ language/ localization/ runtime/ stdlib/ targets/ docs/ examples/ tests/ tools/
```

## Initial Milestones

1. Foundation
2. Lexer
3. Parser
4. AST
5. Semantic analysis
6. First executable target
7. Standard library
8. Arabic/English/Arabizi packs
9. Low-level and Assembly
10. Additional targets and embedded
11. Self-hosting
12. AI-assisted development

## Documentation

- [Vision](docs/vision.md)
- [Architecture](docs/architecture.md)
- [Language Specification](docs/language-spec/README.md)
