# PATRA Vision

## Purpose

PATRA (بيترا) is a general-purpose programming language and compiler platform for application developers and systems programmers.

## One Core, Many Written Languages

PATRA separates Language Pack, Region/Dialect Profile, Writing System, Programming Profile, and PATRA Core. Arabic, English, and Arabizi can express the same semantic operation and produce the same internal representation.

## Custom Terminology

Users, schools, and teams may define aliases such as `عددص = عدد صحيح`. Aliases map to stable PATRA identities rather than changing compiler semantics.

## From Applications to Hardware

```text
Application → Standard Library → Runtime/Platform → OS APIs → HAL → Firmware/RTOS/Bare Metal → CPU/MCU/SoC
```

## Targets

Planned families include Windows, Linux, macOS, Android, iOS where permitted by the official toolchain, WebAssembly, games, Embedded Linux, RTOS, bare metal, microcontrollers, ARM, x86/x64, and RISC-V.

Closed platforms require their official SDKs and toolchains.

## Embedded

Long-term APIs cover GPIO, UART, SPI, I2C, PWM, ADC, DAC, timers, interrupts, DMA, USB, networking, Bluetooth, storage, and watchdogs.

## Assembly

Assembly is a first-class low-level integration capability through inline assembly, external modules, architecture-specific intrinsics, and ABI-aware boundaries.

## AI

AI-assisted development remains separate from the deterministic compiler. AI may generate, explain, or transform PATRA source, while the normal compiler remains authoritative and testable.

## Self-Hosting

Build the first compiler with an established language → stabilize PATRA → implement compiler components in PATRA → compile the PATRA compiler with PATRA.

## Success Criteria

Prioritize correctness, specification, testing, reproducibility, and architectural stability over early feature count.
