/* CSCI 261: Assignment 2: A2 - PPM Image Editor
 *
 * Author: Carter Strate
 * Resources used: Received some help from Andrew Hett and Jordan Pettyjohn
 *
 * This file is where all the function prototypes are
 */
// ppm_functions.h
#ifndef PPM_FUNCTIONS_H
#define PPM_FUNCTIONS_H
# include <fstream>
using namespace std;

void print_file_options();

void print_operation_options();

int get_user_input(int min, int max);

bool open_files(ifstream & fileIn, ofstream & fileOut, int file, int operation);

bool read_header_information(ifstream  & fileIn, int& width, int& height, int& maxVal);

void write_header_information(ofstream & fileOut, int width, int height, int maxVal);

void read_and_write_modified_pixels(ifstream & fileIn, ofstream & fileOut, int operation, int width, int height, int maxVal);

#endif //PPM_FUNCTIONS_H