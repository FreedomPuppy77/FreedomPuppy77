# Speech Contest Management System

## Project Overview

The Speech Contest Management System is a C++ application designed to manage a school speech contest involving 12 participants. The contest is structured over two rounds: an elimination round and a final round. The system ensures fairness and randomness in the contest process and provides information on contestants who advance to the next round.

## Functional Description

1. **Contestant Management**: The system handles 12 contestants, each with a unique identifier (10001 to 10012).

2. **Random Grouping**: In the first round, contestants are randomly divided into two groups of six for the elimination round.

3. **Competition Process**: Contestants speak in the order of their identifiers. After each group's presentations, the bottom three contestants are eliminated.

4. **Advancement Display**: After each round, the system displays information on the contestants who have advanced.

5. **Final Round Management**: The top three contestants from each group compete in the final round to determine the ultimate winner.

## Usage Instructions

### Environment Requirements

- A C++ compiler (such as g++, clang++)
- A compilation environment that supports C++11 or higher

### Compilation and Execution

1. Save the source code as `scms.cpp`.
2. Compile the code using the command line with the following command:
   ```bash
   g++ -std=c++11 scms.cpp -o scms
   ```
3. Run the compiled program:
   ```bash
   ./scms
   ```

### Operation流程

1. Upon starting the program, it automatically proceeds with the random grouping for the first round.
2. View the results of the first round, where the system displays the top three contestants from each group who advance.
3. The system automatically conducts the final round and announces the winner.

## Code Structure

- `scms.cpp`: The main entry point of the program, responsible for initializing the contest and invoking the competition logic.

## Dependency Libraries

- Standard Template Library (STL)
- C++ Standard Library

## Copyright Information

This project is open source and follows the MIT License. You are free to use, modify, and distribute this project, but please retain the copyright information of the original author.

## Contributions

Improvements and extensions to the project are welcome. If you have any suggestions or find any issues, 



