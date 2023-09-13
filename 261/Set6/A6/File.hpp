# include <fstream>
# include <iostream>

using namespace std;

bool open_file(ifstream &fileIn, string fileName);

string prompt_name_file();

bool open_file(ifstream &fileIn, string fileName){

    fileIn.open(fileName);

    if (fileIn.fail() ) {
        return 0;
    } else {
        return 1;
    }

}

string prompt_name_file() {

    cout << "Enter the name of the file to open: ";
    string fileIn;
    cin >> fileIn;
    return fileIn;

}
