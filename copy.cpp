#include <cmath>
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>  
using namespace std;
#include "dstack.h"

int main() {
    Dstack stack;
    char input;
    
    while (cin.peek() != EOF) {
        input = cin.peek();
        if (isspace(input)) {
            cin.ignore();
            continue;
        }

        // If the input is a digit or a decimal point, parse a number
        if (isdigit(input) || input == '.') {
            string number;
            bool decimal = false;

            // Read the entire number as a string
            while (isdigit(cin.peek()) || cin.peek() == '.') {
                char ch = cin.get();
                number += ch;

                if (ch == '.') {
                    if (decimal) {
                        cerr<<"Error: Invalid expression."<<endl;
                        return 1;
                    }
                    decimal = true;
                }
            }

            // Convert the string to a double
            
                double op = stod(number);  // stod converts string to double
                stack.push(op);             // Push the number to the stack
           
        }
        // If the input is an operator, perform the operation
        else if (input == '+' || input == '-' || input == '/' || input == '*' || input == '^') {   
            char opr;
            cin >> opr;

            if (stack.size() < 2) {  
                cerr << "Error: Invalid expression." << endl;
                return 1;
            }

            double op2 = stack.pop();  // First pop for the right operand
            double op1 = stack.pop();  // Second pop for the left operand
            double result = 0;

            switch (opr) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        cerr << "Error: Invalid expression." << endl;
                        return 1;
                    }
                    result = op1 / op2;
                    break;
                case '^':
                    if (op1 < 0 && op2 != int(op2)) {
                        cerr << "Error: Invalid expression." << endl;
                        return 1;
                    } else if (op1 == 0 && op2 < 0) {
                        cerr << "Error: Invalid expression." << endl;
                        return 1;
                    }
                    result = pow(op1, op2);
                    break;
                default:
                    cerr << "Error: Invalid expression." << endl;
                    return 1;
            }
            stack.push(result);  // Push the result back onto the stack
        }
        // Invalid character error
        else {
            cerr << "Error: Invalid expression." << endl;
            return 1;
        }
    }

    // Output the final result, if available
    if (!stack.empty()) {
        if (stack.size() == 1) {
            cout << stack.pop() << endl;  // Print the final result
        } else {
            cerr << "Error: Invalid expression." << endl;
            return 1;
        }
    } else {
        cerr << "Error: Invalid expression." << endl;
        return 1;
    }

    return 0;
}
