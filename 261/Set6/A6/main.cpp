/* CSCI 261: Assignment 6: A6 - A-MAZE-ing
 *
 * Author: Carte Strate
 * Resources used: The internet (geeks for geeks) for conceptual explanation of BFS and DFS. Jordan Pettyjohn for psudocode and debuggind assistance.
 *
 * The pupose of this program is to read in a maze from a file and then to either breadth first search it to solve it (if it can be solved) or to depth first search it.
 */
# include <iostream>
# include <fstream>
# include "File.hpp"
# include "Stack.hpp"
# include "Queue.hpp"
# include "Position.hpp"
using namespace std;

int main(int argc, char* argv[1]){

    string fileName;
    ifstream fileIn;
    if (argc == 1){
        fileName = prompt_name_file();
    } else if(argc == 2){
        fileName = argv[1];
    } else {
        cerr << "Usage: " << argv[0] << " [filename] " << endl;
        cerr << " filename  - optional file to open upon start" << endl;
        return -2;
    }

    if (!(open_file(fileIn,fileName))){
        cerr << "Error: The chosen file could not be opened" << endl;
        return -1;
    } else {
        cout << "File opended successfully!" << endl;
    }

    int rows;
    int columns;

    fileIn >> rows;
    fileIn >> columns;

    // make the maze

    char maze[rows][columns];

    int startRow;
    int startCol;

    // file input into the maze 2d array and find the starting posistion

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            fileIn >> maze[i][j];
            if (maze[i][j] == 'S'){
                startRow = i;
                startCol = j;
            }
        }
    }

    int choice;
    cout << "Enter 1 to search via BFS." << endl << "Enter 2 to search via DFS." << endl << "Choice: ";
    cin >> choice;

    // define a bool that will be changed to true if maze is solved

    bool possible = false;

    // if user chose BFS

    if (choice == 1){
        // define the queue and position to keep track of the spots we need to check
        Queue<Position> list;
        // Position is a class I made to simply hold the row and column index so that they could both be easily stored in the queue
        Position start(startRow, startCol);
        // push the earlier found staring position to the queue to start
        list.push(start);
        // while there are things to check keep going
        while (! list.isEmpty()){
            // all following if statements are checking if each direction is valid (not a wall) and then addign said direction to the queue
            if (maze[(list.peak().getRow() + 1)][(list.peak().getCol())] == '.'){
                int newRow = list.peak().getRow() + 1;
                int newCol = list.peak().getCol();

                Position New(newRow, newCol);

                list.push(New);
            }
            if (maze[(list.peak().getRow())][(list.peak().getCol() + 1)] == '.'){
                int newRow = list.peak().getRow();
                int newCol = list.peak().getCol() + 1;

                Position New(newRow, newCol);

                list.push(New);
            }
            if (maze[(list.peak().getRow() - 1)][(list.peak().getCol())] == '.'){
                int newRow = list.peak().getRow() - 1;
                int newCol = list.peak().getCol();

                Position New(newRow, newCol);

                list.push(New);
            }
            if (maze[(list.peak().getRow())][(list.peak().getCol() - 1)] == '.'){
                int newRow = list.peak().getRow();
                int newCol = list.peak().getCol() - 1;

                Position New(newRow, newCol);

                list.push(New);
            }
            // check to see if adjacent index is the end and if so set the possible bool to true and break from the loop
            if (maze[(list.peak().getRow() - 1)][(list.peak().getCol())] == 'E' || maze[(list.peak().getRow() + 1)][(list.peak().getCol())] == 'E' 
            || maze[(list.peak().getRow())][(list.peak().getCol() - 1)] == 'E' || maze[(list.peak().getRow())][(list.peak().getCol() + 1)] == 'E'){
                maze[(list.peak().getRow())][(list.peak().getCol())] = '@';
                possible = true;
                break;
            }
            // mark the current index as a @ instead of a . to prevent looping
            maze[(list.peak().getRow())][(list.peak().getCol())] = '@';
            // pop current index and move on to whatever is next
            list.pop();
        }
        // deconstruct the queue
        list.~Queue();

    } else if (choice == 2){
        Stack<Position> list;
        Position start(startRow, startCol);
        list.push(start);
        
        while (! list.isEmpty()){
            // due to how a stack works I had to save the current index and then pop it so that I did not just add and then remove an index and never check it
            int sRow = list.peak().getRow();
            int sCol = list.peak().getCol();
            list.pop();
            if (maze[(sRow + 1)][sCol] == '.'){
                int newRow = sRow + 1;
                int newCol = sCol;

                Position New(newRow, newCol);

                list.push(New);
            }
            if (maze[sRow][(sCol + 1)] == '.'){
                int newRow = sRow;
                int newCol = sCol + 1;

                Position New(newRow, newCol);

                list.push(New);
            }
            if (maze[(sRow - 1)][sCol] == '.'){
                int newRow = sRow - 1;
                int newCol = sCol;

                Position New(newRow, newCol);

                list.push(New);
            }
            if (maze[sRow][(sCol - 1)] == '.'){
                int newRow = sRow;
                int newCol = sCol - 1;

                Position New(newRow, newCol);

                list.push(New);
            }
            if (maze[(sRow - 1)][sCol] == 'E' || maze[(sRow + 1)][sCol] == 'E' || maze[sRow][(sCol - 1)] == 'E' || maze[sRow][(sCol + 1)] == 'E'){
                maze[sRow][sCol] = '@';
                possible = true;
                break;
            }
            maze[sRow][sCol] = '@';
        }
        list.~Stack();
    }
    // if the end was reached so so and if not say so as well
    if (possible == true){
        cout << "End was reached!" << endl;
    } else if (possible == false){
        cout << "End could not be reached." << endl;
    }
    // print out the maze after searching (all searched points were made into @ symbols earlier)
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}