/* CSCI 261: Assignment 4: A4 OBJ file format
 *
 * Author: Carter Strate
 * Resources used: Jordan Pettyjohn for pariprogramming
 *
 * The purpose of this program is to validate an obj files format
 */

# include <iostream>
# include <fstream>
# include "LinkedList.hpp"
# include "file.hpp"

using namespace std;

int main(int argc, char* argv[1]){

    string fileName;
    if (argc == 1){
        fileName = prompt_name_file();
    } else if(argc == 2){
        fileName = argv[1];
    } else {
        cerr << "Usage: " << argv[0] << " [filename] " << endl;
        cerr << " filename  - optional file to open upon start" << endl;
        return -2;
    }

    cout << "Opening file '" << fileName << "'" << endl;

    ifstream fileIn;
    if (! open_file(fileIn, fileName)){
        cerr << "Could not open file, shutting down..." << endl;
        return -1;
    }

    cout << "File suscessfully opened" << endl << endl;

    LinkedList<string> comments;

    LinkedList<float> vertices;

    LinkedList<int> faces;

    int iComments = 0;
    int iVertices = 0;
    int iFaces = 0;

    string checker;
    string commentInput;
    float vertexInput;
    int faceInput;


    for (unsigned int i = 0; i < comments.size(); i++){
        cout << comments.at(i) << " ";
    }

    bool skip = false;
    while(! fileIn.eof()){
        if (skip != true){
            fileIn >> checker;
        }
        skip = false;
        
        if (checker == "#"){
            iComments ++;
            while(true){
                fileIn >> commentInput;
                if (commentInput == "#" || commentInput == "v" || commentInput == "f" || fileIn.eof()){
                    checker = commentInput;
                    skip = true;
                    comments.pushBack("#");
                    break;
                }
                comments.pushBack(commentInput);
            }
        } else if (checker == "v"){
            iVertices++;
            for (int i = 0; i < 3; i++){
                fileIn >> vertexInput;
                vertices.pushBack(vertexInput);
            }
        } else if (checker == "f"){
            iFaces++;
            for (int i = 0; i< 3; i++){
                fileIn >> faceInput;
                faces.pushBack(faceInput);
            }
        }
    }
    

     if (checker == "v"){
         vertices.popBack();
         vertices.popBack();
         vertices.popBack();
         iVertices--;
     } else if (checker == "f"){
         faces.popBack();
         faces.popBack();
         faces.popBack();
         iFaces--;
     }

    cout << "Read in" << endl;
    cout <<"    " << iComments << " comments" << endl;
    cout <<"    " << iVertices << " vertices" << endl;
    cout <<"    " << iFaces << " faces" << endl;
    
    bool error = false;
    int index = 0;
    cout << endl << "Validating faces..." << endl;
    for (unsigned int i = 0; i < faces.size() / 3; i++){
        int val1 = 0;
        int val2 = 0;
        int val3 = 0;
        for (int j = 0; j < 3; j++){
            if (j == 0){
                val1 = faces.at(index);
            } else if (j == 1){
                val2 = faces.at(index);
            } else if (j == 2){
                val3 = faces.at(index);
            }
            
            if (faces.at(index) > ((vertices.size() / 3) + 1) || faces.at(index) < 1){
                cout << "Face " << i + 1 << " contains vertices out of range" << endl;
                error = true;
                index ++;
                break;
            }
            index++;
        }
        if (val1 == val2 || val1 == val3 || val2 == val3){
            cout << "Face " << i + 1 << " contains duplicate indices" << endl;
            error = true;
        }
    }
    if (error == true){
        cout << "...File is invalid";
        return -1;
    }
    cout << "...File is valid!" << endl << endl;

    int choice;
    while(true){
        cout << endl;
        cout << "What do you wish to do?" << endl;
        cout << "   1) Print comments" << endl;
        cout << "   2) Print vertices" << endl;
        cout << "   3) Print faces" << endl;
        cout << "   4) Quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        cout << endl;

        if (choice == 1){
            int count = 1;
            cout << "comments #1: ";
            for (unsigned int i = 0; i < comments.size() - 1; i++){
                if (comments.at(i) == "#"){
                    count++;
                    cout << endl;
                    cout << "comments #" << count << ": ";
                } else{
                    cout << comments.at(i) << " ";
                }
            }
            cout << endl;
        } else if (choice == 4){
            cout << "Goodbye!";
            break;
        } else if (choice == 2){
            index = 0;
            for (unsigned int i = 0; i < vertices.size() / 3; i++){
                cout << "Vertex #" << i + 1 << ": (";
                for (int j = 0; j < 3; j++){
                    if (j == 2){
                        cout << vertices.at(index) << ")" << endl;
                    } else{
                        cout << vertices.at(index) << ", ";
                    }
                    index++;
                }
            }
        } else if (choice == 3){
            index = 0;
            for (unsigned int i = 0; i< faces.size() / 3; i++){
                cout << "Face #" << i + 1 << ": (";
                for (int j = 0; j < 3; j++){
                    if (j == 2){
                        cout << faces.at(index) << ")" << endl;
                    } else{
                        cout << faces.at(index) << ", ";
                    }
                    index++;
                }
            }
        }
    }

    return 0;
}