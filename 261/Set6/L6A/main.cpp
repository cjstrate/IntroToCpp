# include <iostream>
# include <fstream>
# include "file.hpp"
using namespace std;

int main(){

    string fileName = prompt_name_file();
    ifstream fileIn;
    
    if (!(open_file(fileIn, fileName))){
        cerr << "File could not be opened... shutting down" << endl;
        return -1;
    }

    int dem;
    fileIn >> dem;

    int array[dem][dem];

    for (int i = 0; i < dem; i++){
        for (int j = 0; j < dem; j++){
            int input;
            fileIn >> input;
            array[i][j] = input;
        }
    }

    fileIn.close();

    cout << "The table is:" << endl;

    int min = array[0][0];
    int max = array[0][0];

    for (int i = 0; i< dem; i++){
        for (int j = 0; j < dem; j++){
            if (array[i][j] < min){
                min = array[i][j];
            }
            if (array[i][j] > max){
                max = array[i][j];
            }
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "The min is: " << min << endl;
    cout << "The max is: " << max << endl;

    return 0;
}