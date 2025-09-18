# Maths Expression Parser in C

This project is a **custom algorithm** written in C that parses and evaluates mathematical expressions using a **linked list–based approach**.  

It provides a lightweight parser that handles numbers, operators, and brackets with basic error detection.

---

## 🚀 Features

- **Custom parsing algorithm** (no external libraries, pure C implementation).  
- **Internally managed spaces and quotes** — input can include whitespace freely.  
- **Supported Numbers**:  
  - Positive (`5`, `123`)  
  - Negative (`-7`, `-3.5`)  
  - Decimal (`3.14`, `-2.71`)  
- **Supported Operators**:  
  - Multi-bracket expressions `( … )`, `(( … ))`, etc.  
  - Division `/`  
  - Multiplication `*`  
  - Addition `+`  
  - Subtraction `-`  
- **Error Handling**:  
  - Detects basic syntax errors (e.g., unmatched brackets, invalid operators).  

---

## 🛠️ Build Instructions

Tested on **FreeBSD (latest)** and **Debian (latest)** with `gcc`.

```bash
gcc -o evaluate evaluate.c
