/* CSCI 261: Assignment 2: A2 - PPM Image Editor
 *
 * Author: Carter Strate
 * Resources used: Received some help from Andrew Hett and Jordan Pettyjohn
 *
 * This file is where all the funcions are called to actually create the altered ppm file
 */
# include <iostream>
# include "ppm_functions.h"
# include <fstream>
using namespace std;

int main(){

    int file, operation, width, height, maxValue;
    ifstream fileIn;
    ofstream fileOut;

    // Loop the user input until they enter an acceptable value
    while(true){
        print_file_options();
        file = get_user_input(1,3);
        if (file != -1){
            break;
        }

    }

    while(true){
        print_operation_options();
        operation = get_user_input(1,2);
        if (operation != -1){
            cin.clear();
            break;
        }
    }

    // exits the program if the file could not be opened
    if (!(open_files(fileIn, fileOut, file, operation))){
        cerr << "There was an error opening the file";
        return -1;
        }
    
    // exits the program if the file is not a P3 ppm file
    if (!(read_header_information(fileIn, width, height, maxValue))){
        cerr << "This is not the correct kind of ppm file";
        return -1;
        }
    
    // making the altered file
    write_header_information(fileOut, width, height, maxValue);
    read_and_write_modified_pixels(fileIn, fileOut, operation, width, height, maxValue);

    return 0;
}