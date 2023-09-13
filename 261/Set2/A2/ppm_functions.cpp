/* CSCI 261: Assignment 2: A2 - PPM Image Editor
 *
 * Author: Carter Strate
 * Resources used: Received some help from Andrew Hett and Jordan Pettyjohn
 *
 * This file is where all the funcions are defined for A2
 */
# include <iostream>
# include <fstream>
using namespace std;

void print_file_options(){
    cout << "Which image to load?" << endl;
    cout << "1. Brick" << endl;
    cout << "2. Wallpaper" << endl;
    cout << "3. Private" << endl;
}

void print_operation_options(){
    cout << "Which process to apply?" << endl;
    cout << "1. Grayscale" << endl;
    cout << "2. Inversion" << endl;
}

int get_user_input(int min, int max){
    int out, tempVal = min;
    cout << "Enter ";
    // a loop to print out all the options available based on min and max
    while (tempVal < max){
        cout << tempVal <<", ";
        tempVal++;
    }
    cout << "or " << max << ": ";
    cin >> out;
    cout << endl;

    // I was having a problem where if the user entered a character then the cin would no take in any other values
    // this is how I fixed it. The reprompt does not match the example but it is what it is.
    while(cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "You can only enter numbers. Please try again" << endl;
        cout << "Number: ";
        cin >> out;
    }

    // checks to see if the number inputed is between max and min
    if (!(out <= max && out >= min)){
        cerr << "Invalid Input" << endl << endl;
        cin.clear();
        return -1;
    }
    
    return out;
}

bool open_files(ifstream& fileIn, ofstream& fileOut, int file, int operation){
    string file_name, file_name_out;
    
    if (file == 1){
        file_name = "brick.ppm";
    } else if (file == 2){
        file_name = "wallpaper.ppm";
    } else{
        file_name = "private.ppm";
    }

    // creates the name for the output file
    if (operation == 1 && file == 1){
        file_name_out = "brick_grayscale.ppm";
    } else if (operation == 1 && file == 2){
        file_name_out = "wallpaper_grayscale.ppm";
    } else if (operation == 1 && file == 3){
        file_name_out = "private_grayscale.ppm";
    } else if (operation == 2 && file == 1){
        file_name_out = "brick_inverted.ppm";
    } else if (operation == 2 && file == 2){
        file_name_out = "wallpaper_inverted.ppm";
    } else if (operation == 2 && file == 3){
        file_name_out = "private_inverted.ppm";
    }
    fileIn.open(file_name);
    fileOut.open(file_name_out);

    if ((fileIn.fail()) || (fileOut.fail())){
        return 0;
    } else{
        return 1;
    }
}


bool read_header_information(ifstream& fileIn, int& width, int& height, int& maxVal){
    string ppm_type;

    fileIn >> ppm_type;
    fileIn >> width;
    fileIn >> height;
    fileIn >> maxVal;

    if (ppm_type == "P3"){
        return 1;
    } else{
        return 0;
    }
}

void write_header_information(ofstream& fileOut, int width, int height, int maxValue){
    fileOut << "P3" << endl;
    fileOut << width << " ";
    fileOut << height << endl;
    fileOut << maxValue << endl;
}

void read_and_write_modified_pixels(ifstream& fileIn, ofstream& fileOut, int operation, int width, int height, int maxVal){
    int gray, red, blue, green;
    // computes and outputs the values to gray scale to picture
    if (operation == 1){
        for (int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                fileIn >> red;
                fileIn >> green;
                fileIn >> blue;
                gray = (0.2989 * red) + (0.5870 * green) + (0.1140 * blue);
                red = gray;
                green = gray;
                blue = gray;
                fileOut << red << endl;
                fileOut << green << endl;
                fileOut << blue << endl;
            }
        }
        // computes and outputes the values to invet the colors
        } else if (operation == 2){
            int total, color;
            total = (width * height) * 3;
            for(int i = 0; i < total; i++){
                fileIn >> color;
                color = maxVal - color;
                fileOut << color << endl;
            }
        }
    // close files
    fileIn.close();
    fileOut.close();
}