# Parallel Compiler

A multi-threaded C++ program that demonstrates parallel compilation of multiple source files.

## Overview

This project implements a parallel compiler that can compile multiple source files concurrently using threads. It's designed as an exercise to learn and practice multi-threaded programming concepts in C++.

## Project Structure

```
.
├── Compiler/           # Compiler implementation
├── CompilationManager/ # Manages compilation processes
├── CompilationJobs/    # Handles compilation job definitions
├── main.cc            # Main program entry point
├── source1.cc         # Example source file 1
├── source2.cc         # Example source file 2
├── source3.cc         # Example source file 3
├── main.ih            # Header file for main
├── Makefile           # Build configuration
└── order.txt          # Compilation order specification
```

## Features

- Parallel compilation of multiple source files
- Thread-safe compilation job management
- Promise/Future pattern for asynchronous compilation results
- Modular design with separate components for compiler, job management, and compilation process

## Building the Project

To build the project, simply run:

```bash
make
```

## Usage

The program automatically compiles the example source files (`source1.cc`, `source2.cc`, and `source3.cc`) in parallel. The compilation results are managed through a thread-safe system using promises and futures.

## Implementation Details

- Uses C++ standard library threading features
- Implements the Promise/Future pattern for asynchronous operations
- Modular design with separate components for different responsibilities
- Thread-safe compilation job management

## Requirements

- C++ compiler with C++11 or later support
- Make build system
