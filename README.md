# Scorch
Flame fractal image generator

# Description
![](https://i.imgur.com/8X9rPrY.jpg)

This project started as a school excercise in Java. Years later, I rewrote it in C++ so I could have a basis for future optimizations as a pet project.

## Branches
Each branch contains a different level of optimization.

### master
Latest stable branch.

### java-style
First port from java to C++. Everything was translated to be as close as possible to the original java code. Hence the sometimes weird class structure emphasized by the fact that this was a school excercise with the goal to use builders, interfaces, inheritance, anonymous classes, immutability, ...

Performance-wise it's very close to 100% slower than the original java code.

### (WIP) refactored
Complete refactoring of java-style. The goal is to clean the code of dirty workarounds and badly transated java concepts.

# Improvements done
- image smoothing

# Future improvements
- parse fractal parameters from the command line
- tune compiler options
- optimize data structures
- reduce branch misprediction (loop unfolding, "if" removal, ...)
- use of intel intrinsics if possible
- multithreading with OpenMP

- feature : train an AI to make fractals that look good
