/* CSCI 261: L2E
 *
 * Author: Carter Strate
 * Resources used: Received some help from Andrew Hett and Jordan Pettyjohn
 *
 * This file is where all the funcions are defined for L2E
 */
# include <iostream>
using namespace std;

void print_result(int a, int b, int result, char op) {
    cout << a << " " << op << " " << b << " = " << result << endl;
}

void print_options() {
    cout << "(A)dd" << endl;
    cout << "(S)ubtract" << endl;
    cout << "(M)ultiply" << endl;
    cout << "(D)ivide" << endl;
    cout << "(Q)uit" << endl;
}

void add(int a, int b) {
    int result = a + b;
    print_result(a, b, result, '+');
}


void sub(int a, int b) {
    int result = a - b;
    print_result(a, b, result, '-');
}


void mult(int a, int b) {
    int result = a * b;
    print_result(a, b, result, '*');
}


void divide(int a, int b) {
    int result = a / b;
    print_result(a, b, result, '/');
}


void turn_calculator_on() {
    cout << "Welcome to the calculator!" << endl;
    
    // prompt the user to enter our two operands
    cout << "Enter two integers: ";
    int num1, num2;
    cin >> num1 >> num2;

    // until the user decides to quit
    while(true) {
        cout << "What do you want to do?" << endl;
        print_options();

        // get users choice
        char choice;
        cin >> choice;

        switch(choice) {
        case 'A':
        case 'a':
            add(num1, num2);
            break;

        case 'S':
        case 's':
            sub(num1, num2);
            break;

        case 'M':
        case 'm':
            mult(num1, num2);
            break;

        case 'D':
        case 'd':
            divide(num1, num2);
            break;

        case 'Q':
        case 'q':
            return;

        default:
            cout << "Invalid choice" << endl;
        }
    }
}
