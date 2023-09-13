/* CSCI 261: Final Project
 *
 * Author: Carter Strate
 *
 * The pupose of this program is allow the user to navigate a maze
 */
# include <iostream>
# include <fstream>
# include "Maze.hpp"
# include "HighScore.hpp"
# include <vector>
using namespace std;

int main(){
    // Create the list that will contain the high scores
    vector<HighScore> list;
    ifstream fileIn;
    fileIn.open("HighScoreList.txt");
    // open the high score file
    while(true){
        // loop through the file to get all the high scores
        string name;
        int score;
        fileIn >> name;
        fileIn >> score;

        // create a HighScore Class for each read in high score

        HighScore New(name, score);

        // add high score to the list

        list.push_back(New);

        // if at end of file break
        
        if (fileIn.eof()){
            break;
        }
    }
    while(true){
        // promp user to either see high score or play game
        string choice;
        cout << "Welcome to my game!" << endl;
        cout << "[1] Play Game" << endl << "[2] View High Scores" << endl << "[3] Quite" << endl;
        cout << "Choice: ";
        cin >> choice;
        // if they want to play
        if (choice == "1"){
            bool cont = true;
            bool win = false;
            int i;
            Maze test;
            while(cont){
                // while the player has not found the exit or been caught by the pursuer then traverse the player
                i = test.traversePlayer(i, cont, win);
                if (!cont){
                    break;
                }
            }

            if (win == true){
                // if they win
                cout << "Would you like to add you score of " << i << " to the score board?" << endl;
                string choice;
                cout << "[1] Yes" << endl << "[2] No" << endl << "Choice: ";
                cin >> choice;
                if (choice == "1"){
                    // add the high score to the list
                    ofstream fileOut;
                    fileOut.open("HighScoreList.txt");
                    string name;
                    cout << "Please enter your name: ";
                    cin >> name;
                    HighScore input(name, i);
                    list.push_back(input);
                    while(true){
                        // sort the list
                        bool sorted = true;
                        for (unsigned int i = 0; i < (list.size() - 1); i++){
                            if (list.at(i).getScore() > list.at(i + 1).getScore()){
                                HighScore big(list.at(i).getName(), list.at(i).getScore());
                                HighScore small(list.at(i + 1).getName(), list.at(i + 1).getScore());
                                list.at(i) = small;
                                list.at(i + 1) = big;
                                sorted = false;
                            }
                        }
                        if (sorted){
                            break;
                        }
                    }
                    // out put the list to the file
                    for (unsigned int i = 0; i < list.size(); i++){
                        fileOut << list.at(i).getName() << " ";
                        fileOut << list.at(i).getScore();
                    }
                    // print the list
                    for (unsigned int i = 0; i < list.size(); i++){
                        cout << list[i].getName() << " " << list[i].getScore() << endl;
                    }
                }
                cout << "Thank you for playing!" << endl;
            }

            test.~Maze();
        } else if (choice == "2"){
            for (unsigned int i = 0; i < list.size(); i++){
                cout << list[i].getName() << " " << list[i].getScore() << endl;
            }
        } else if (choice == "3"){
            return 0;
        }
    }

    return 0;
}