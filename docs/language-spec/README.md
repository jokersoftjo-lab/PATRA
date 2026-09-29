# PATRA Language Specification

**Status: Draft 0.1**

## 1. Source Encoding

PATRA source files use UTF-8 and the `.patra` extension. Identifiers and language forms are Unicode-aware.

## 2. Whitespace

Multiple consecutive spaces are equivalent to one separator where grammar permits separation. Formatting does not change program meaning unless a future rule explicitly defines indentation as syntax.

## 3. Literals

Initial literals: integers, floating-point values, strings, and booleans.

```patra
25
3.14
"أهلاً بالعالم"
true
false
```

## 4. Stable Semantic Identities

Examples: `PATRA_PRINT`, `PATRA_INTEGER`, `PATRA_FLOAT`, `PATRA_STRING`, `PATRA_BOOLEAN`, `PATRA_FUNCTION`, `PATRA_RETURN`, `PATRA_IF`.

## 5. Output

Arabic: `اطبع "أهلاً بالعالم"`

English: `print "Hello World"`

Both resolve to `PATRA_PRINT(StringLiteral(...))`.

## 6. Variables

Conceptual form: `[type] [identifier] = [expression]`.

Possible Arabic spelling: `عدد صحيح العمر = 25`.

## 7. Expressions

Initial categories: literals, identifier references, parenthesized expressions, arithmetic expressions, and function calls. Operator precedence will be explicit in the grammar.

## 8. Functions

Functions are named callable units with parameters, an optional return type, and a body. Localized spellings map to the same internal construct.

## 9. Conditionals

PATRA provides conditional execution. Exact localized syntax is a front-end concern.

## 10. Aliases

User aliases may map custom spellings to approved PATRA language identities. Example: `عددص = عدد صحيح`. Arbitrary rewriting that destabilizes the grammar is not allowed.

## 11. Language Profiles

Examples: `ar`, `ar-JO`, `en`, `en-US`, `arabizi`. Profiles can define keyword spellings, type names, built-ins, operator aliases, diagnostic language, writing direction, and identifier conventions.

## 12. Determinism

Given identical source, profile, compiler version, target configuration, and options, semantic results should be deterministic.

## 13. Compatibility

Stabilized syntax and semantics require an explicit specification revision and compatibility policy for changes.

## 14. Not Yet Specified

Generics, classes, templates, ownership/borrowing, concurrency, async, unsafe memory model, pointer syntax, inline Assembly syntax, modules, macros, reflection, GPU programming, full embedded HAL API, and AI language interfaces require later specifications.

## 15. First Conformance Goal

```patra
اطبع "أهلاً بالعالم"
```

Expected semantic result: `PATRA_PRINT(StringLiteral("أهلاً بالعالم"))`.
