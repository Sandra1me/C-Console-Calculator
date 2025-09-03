# C Console Calculator

This is a simple console-based calculator written in C. It started as a basic exercise to practice control structures, input/output, and error handling. Over time, it evolved into a more complete tool with support for powers, roots, trigonometric functions, factorials, and a history of recent results. It also lets you reuse the previous result in new operations.

## Features

- Basic operations: addition, subtraction, multiplication, division
- Powers and roots
- Trigonometric functions: sine and cosine
- Factorials (only for positive integers)
- Option to reuse the previous result
- Displays the last 5 results in a history list
- Input validation to prevent crashes
- Input buffer cleaning to avoid invalid reads

## Compilation

Use `gcc` to compile the program:

```c
gcc calculator.c -o calculator -lm
```

## Usage
Run the program from the terminal:

```c
./calculator
```

Follow the menu instructions to select an operation. After each operation, you'll be able to decide whether to continue and whether to reuse the previous result. The calculator will also display a list of your last 5 results.

## Example

<img width="842" height="847" alt="Calculator Console" src="https://github.com/user-attachments/assets/4d7d81c9-6a65-4719-adcf-a3c53c76ec61" />


## Future Improvements

- Add more math functions like tangent or logarithms
- Save result history to a text file
- Improve the interface with a more visual menu system
- Create a GUI version in C++ or another language

## License

This project is licensed under the [MIT Licence](https://choosealicense.com/licenses/mit/). Feel free to use, modify, or distribute it.
