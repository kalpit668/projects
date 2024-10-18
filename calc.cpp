//calc.cpp file
//Sharma, Kalpit
//ksharma12
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
    try{ 
    while (cin.peek() != EOF) {
        input = cin.peek();
        if (isspace(input)) {
            cin.ignore();
            // continue;
        }
        // If the input is a digit or a decimal point, parse a number
        else if (isdigit(input) || input == '.') {
            string number;
            bool decimal = false; //declaring flag to check for decimal

            // Read the entire number as a string
            while (isdigit(cin.peek()) || cin.peek() == '.') {
                char ch = cin.get();
                number += ch;

                if (ch == '.') { // Checking for the second decimal
                    if (decimal) {
                        throw "Error: Invalid expression."; 
                    }
                    decimal = true;
                }
            }
            if (number == ".") { // Checking for the input that is a "."
            throw "Error: Invalid expression.";
            }
            // Convert the string to a double
                double op = stod(number);  
                stack.push(op);             // Push the number to the stack
           
        }
        // If the input is an operator, perform the operation
        else if (input == '+' || input == '-' || input == '/' || input == '*' || input == '^') {   
            char opr;
            cin >> opr;
            //Checking for the availability of two operands
            if (stack.size() < 2) {  
                throw "Error: Invalid expression.";    
            }

            double op2 = stack.pop();  // First pop for the right operand
            double op1 = stack.pop();  // Second pop for the left operand
            double result = 0;
            //switch cases for operations
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
                        throw "Error: Invalid expression.";
                    }
                    result = op1 / op2;
                    break;
                case '^':
                    if (op1 < 0 && op2 != int(op2)) {
                        throw "Error: Invalid expression.";
                    } else if (op1 == 0 && op2 < 0) {
                        throw "Error: Invalid expression.";
                    }
                    result = pow(op1, op2); //using math
                    break;
                default:
                    throw "Error: Invalid expression.";
            }
            stack.push(result);  // Push the result back onto the stack
        }
        // Invalid character error
        else {
            throw "Error: Invalid expression.";
        }
    }

    // Output the final result, if available
    if (!stack.empty()) {
        if (stack.size() == 1) {
            cout << stack.pop() << endl;  // Print the final result
        } else {
            throw "Error: Invalid expression.";
        }
    } else {
        cerr << "Error: Invalid expression." << endl;
        return 1;
    }
}
    catch(const char* e) //Catching all the errors
    {
        cerr <<"Error: Invalid expression."<< endl;
        return 1;
    }
    return 0;
}
