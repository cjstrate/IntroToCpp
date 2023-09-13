/* CSCI 261: Assignment 3: L3A
 *
 * Author: Carter Strate
 * Resources used: None
 *
 * The purpose of this progarm was to get 15 or less inputs from the user and add them to an array. Then find the max and min of the numbers in the array.
 * 
 */
# include <iostream>
using namespace std;

int main(){

    int nums[15];
    int index = -1;
    int max = 0, min = 0;

    cout << "Please enter up to 15 non-zero whole numbers. Enter a 0 to signal the end of the data or enter all 15 values: " << endl;

    for (int i = 1; i <= 15; i++){
        int num;
        cout << "Number " << i << ": ";
        cin >> num;

        if (num == 0){
            index ++;
            break;
        } else {
            nums[i] = num;
            index ++;
        }
        
        if ( i == 1){
            max = num;
        } else if (num > max){
            max = num;
        }

        if (i == 1){
            min = num;
        } else if (num < min){
            min = num;
        }
    }

    cout << "The numbers are" << endl;
    for (int i = 1; i <= index; i++){
        cout << nums[i] << " ";
    }
    
    cout << endl;
    cout << "The maximum value is: " << max << endl;
    cout << "The minimum value is: " << min << endl;
    cout << "Have a nice day!";

    return 0;
}