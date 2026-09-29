# PATRA Compiler Architecture

## Pipeline

```text
Source Text
 ↓
Language Front End
 ↓
Lexer
 ↓
Parser
 ↓
AST
 ↓
Semantic Analysis
 ↓
PATRA IR
 ↓
Optimization
 ↓
Target Lowering
 ↓
Code Generation
 ↓
Object / Executable
```

Runtime, standard libraries, target support, localization, and AI tooling are adjacent systems.

## Front End

Language packs define keywords, type names, built-ins, operator spellings, diagnostics, identifier rules, aliases, and writing-direction metadata. The lexer is Unicode-aware and preserves source locations.

## Lexer

Initial tokens: identifiers, keywords, integer/float/string/character literals, operators, punctuation, comments, and EOF.

## Parser

Initial grammar: program, variable declaration, assignment, literals, identifier references, function calls, function declarations, return, conditionals, and blocks.

## AST

AST represents meaning rather than spelling. Arabic `اطبع` and English `print` resolve to the same semantic operation such as `Call(builtin=PATRA_PRINT, ...)`.

## Semantic Analysis

Checks name resolution, scopes, types, function signatures, initialization, return rules, mutability, access rules, and target restrictions. Diagnostics use stable identifiers with localized display text.

## IR

PATRA IR is the stable representation between language semantics and target code generation. It will eventually support typed values, basic blocks, control flow, calls, memory/pointers, aggregates, atomics where supported, and target lowering hooks.

## Optimization

Begin with correctness and simple transformations such as constant folding, dead-code elimination, block simplification, value propagation, and later inlining/target optimization.

## Code Generation

Initial target: x86_64 Windows. Later: x86_64 Linux, ARM64, ARM embedded, RISC-V, and WebAssembly. Targets must define ABI, object format, calling convention, pointer width, alignment, and runtime facilities.

## Runtime and Standard Library

Runtime contains only required runtime facilities. Standard libraries provide portable APIs for IO, memory, math, strings, collections, filesystem, time, and networking.

## Embedded/HAL

```text
PATRA API → Platform Layer → HAL → MCU/SoC SDK or Registers
```

## AI and IDE

AI tools sit outside the compiler and produce source, edits, or explanations that go through the normal compiler. Future tooling includes `patra`, formatter, linter, LSP, debugger integration, package manager, build system, and documentation generator.
