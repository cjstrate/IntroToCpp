/* CSCI 261: L2A
 *
 * Author: Carter Strate
 * Resources used: Received some help from Andrew Hett and Jordan Pettyjohn
 *
 * This program takes a text file input and decipheres it with a given key
 */
# include <iostream>
# include <fstream>
using namespace std;

int main() {
    char c;

    ifstream secretMessageIn("secretMessage.txt");
    ofstream secretMessageOut("decipheredMessage.txt");

    if ( secretMessageIn.fail() ){
        cerr << "Error opening input file";
        return -1;
    }

    if ( secretMessageOut.fail() ){
        cerr << "Error opening outpur file";
        return -1;
    }

    while ( secretMessageIn.get(c) ){
        if (c == '~'){
            c = ' ';
            secretMessageOut << c;
        } else if (c == '\n'){
            c = '\n';
            secretMessageOut << c;
        } else {
            c = char(c + 1);
            secretMessageOut << c;
        }
    }
    secretMessageIn.close();
    secretMessageOut.close();
    return 0;
}