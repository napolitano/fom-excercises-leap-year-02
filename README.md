# FOM Excercise: Leap Year in ANSI C

This program is a homework assignment in the context of my studies of business informatics. This version of the solution goes beyond the contents of the module contents taught so far and tries to address concepts like single responsibility, testability, separation of cencerns etc. in a simple way.

## Compilation

The code was created in the programming trace C and can be compiled into an executable program with a C compiler. GCC is used in the course of the study. 

### Deviations for Windows systems

On Windows systems, it may be necessary to install an appropriate environment (e.g. MinGW) and configure the path variables. 

On Windows systems, the call of the compiler should also be adapted:

```bash
gcc leapyear02.c -o leapyear02.exe
```

Depending on the shell and environment used, it may be necessary to prefix a dot with the following backslash for execution - i.e. .\leapyear02.exe
