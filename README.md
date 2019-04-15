# Scorch
Flame fractal image generator

Status : bugged

![](https://i.imgur.com/8X9rPrY.jpg)

This project started as a school excercise in Java. Years later, I rewrote it in C++ so I could have a basis for future optimizations as a pet project.

## Branches
Each branch contains a different level of optimization.

### master
First port from java to C++. Everything was translated to be as close as possible to the original java code. Hence the sometimes weird class structure emphasized by the fact that this was a school excercise with the goal to use builders, interfaces, inheritance, anonymous classes, immutability, ...

### (TODO) refactored
Complete rewriting as I would have done it in C++ without instructions from a teacher.

# Future improvements
- tune compiler options
- optimize data structures
- reduce branch misprediction (loop unfolding, "if" removal, ...)
- use of intel intrinsics if possible
- multithreading with OpenMP

- feature : teach an AI how to make fractals that look better
