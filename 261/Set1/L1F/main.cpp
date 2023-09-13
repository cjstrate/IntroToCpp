/* CSCI 261: Errors
 *
 * Author: XXXX (_INSERT_YOUR_NAME_HERE_)
 *
 *    This program illustrates a variety of common errors.
 *    Fix the errors in each section.

Copyright 2022 Dr. Jeffrey Paone

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

 */

#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to Loop World" << endl;

// SECTION I: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = change ci to cin. I also changed < to <= to make sure it was a inclusive sum.
// TESTS: enter 10 should be sume of 55 (correct) enter 2 should be sume of 3 (correct)

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    int sum;      // Accumulates the total
    int i;        // Used as loop control variable
    int numIter;  // The number of times to iterate
    cout << "Enter a number greater than 1 to sum up to: ";
    cin >> numIter;
    for (i = 1; i <= numIter; ++i) {
         sum += i;
     }
    cout << "The sum of the numbers from 1 to " << numIter << " (inclusive) is: " << sum << endl;

// SECTION II: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = co to cout << to >>. I also removed the new line after the input as when the user presses enter it will make a new line (I did this twice).
// TESTS: Enter three items with price 5 5 5 shuold output with 15 (correct) 3 itmes 1 2 3 answer 6 (correct)

    cout << endl;
    cout << "******************" << endl;
    cout << "Section II" << endl;
    cout << "******************" << endl;

    double total = 0;     // Accumulates total
    double price;     // Gets next price from user
    int numItems;     // Number of items
    int counter = 1;  // Loop control counter

    cout << "How many items do you have? ";
    cin >> numItems;

    while (counter <= numItems) {
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        total += price;
        counter++;
    }
    cout << "The total price of all items is: " << total << endl;

// SECTION III: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = I added a ; on line 103. I also initialized sum2 at 0 and counter2 at 1. I also changed the while part from sum2 to numIter2. I also made it so that 1 was added to counter2
// every iteration to avoid a infinite loop 
// TESTS: enter 10 should be 55 (correct)

    cout << endl;
    cout << "******************" << endl;
    cout << "Section III" << endl;
    cout << "******************" << endl;

    int sum2 = 0;
    int counter2 = 1;
    int numIter2;

    cout << "What number do you wish me to sum from 1 to?" << endl;
    cin >> numIter2;

    do {
        sum2 += counter2;
        cout << "Sum so far: " << sum2 << endl;
        counter2++;
    } while (counter2 <= numIter2);

    cout << endl << "Section III Recap" << endl;

    cout << "I calculated the sum of numbers from 1 to " << numIter2 << " (inclusive) as " << sum2 << endl;


// SECTION IV: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = I addded a prompt for the user to enter a number for ? for clarity. I also initialized all the variables at the top of the code to make it easier to read. I thne changed the for
// loops to set i3 to 1 then loop as long as i3 is less than or equal to the final number and then add one after every loop.
// TESTS: enter 4 should be 30 (correct)

    cout << endl;
    cout << "******************" << endl;
    cout << "Section IV" << endl;
    cout << "******************" << endl;

    int i3, numIter3, sum3 = 0;

    cout << "I will now calculate ";
    cout << "the sum of 1 squared to ? squared (inclusive)" << endl;
    
    cout << "Enter number for ?: ";
    cin >> numIter3;

    for (i3 = 1; i3 <= numIter3; i3++) {
        sum3 += i3*i3;
    }

    cout << "The sum of squares from 1 to " << numIter3 << " is: " << sum3 << endl;

// SECTION V: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = the above statement was missing the second / to make it a comment. Additionally I initialized sum4 and counter4 (counter4 at 1) and added an output to ask for the value for
// numIter4 for clarity sake. I alos put counter4++ into the while loop to avoid an infinite loop. I also changed the < 10 in the loop to <= numIter4 to make it loop as many times as 
// the user wants it to.
// TESTS: enter 4 should be 100 (correct)

    cout << endl;
    cout << "******************" << endl;
    cout << "Section V" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum from 1 cubed to ? cubed (inclusive)" << endl;

    int numIter4, counter4 = 1, sum4 = 0;
    cout << "Enter a number for ?: ";
    cin >> numIter4;

    while (counter4 <= numIter4) {
        sum4 += (counter4 * counter4 * counter4);
        counter4++;
    }

    cout << "The sum of cubes from 1 to " << numIter4 << " is: " << sum4 << endl;

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}
