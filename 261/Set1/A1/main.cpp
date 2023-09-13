// Carter Strate
// Resources: Jordan Pettyjohn and Andrew Hett (just basic questions/ verbal psuedocode)
// This is a program designed to allow a user to play any number of games of rock paper scissors with the computer

# include <iostream>
# include <ctime>
# include <cstdlib>

using namespace std;

int main() {

    string p_choice, com_choice, winner, proceed;
    int rand_out;

    while (true){
        cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter R, P or S)" << endl;
        cout << "Player: ";
        cin >> p_choice;

        if (p_choice == "R" || p_choice == "r"){
            p_choice = "Rock";
        } else if (p_choice == "P" || p_choice == "p"){
            p_choice = "Paper";
        } else if (p_choice == "S" || p_choice == "s"){
            p_choice = "Scissors";
        }
        
        srand(time(0));

        rand();

        rand_out = rand() % (4 - 2 + 1) + 1;
        if (rand_out == 1){
            com_choice = "Rock";
        } else if (rand_out == 2){
            com_choice = "Paper";
        } else if (rand_out == 3){
            com_choice = "Scissors";
        }

        cout << "Player choose " << p_choice << endl;
        cout << "Computer choose " << com_choice << endl;

        if (p_choice == "Rock" && com_choice == "Paper"){
            cout << "Paper beats Rock." << endl;
            winner = "Computer";
        } else if (p_choice == "Paper" && com_choice == "Rock"){
            cout << "Paper beats Rock." << endl;
            winner = "Player";
        } else if (p_choice == "Scissors" && com_choice == "Paper"){
            cout << "Scissors beats Paper." << endl;
            winner = "Player";
        } else if (p_choice == "Paper" && com_choice == "Scissors"){
            cout << "Scissors beats Paper." << endl;
            winner = "Computer";
        } else if (p_choice == "Rock" && com_choice == "Scissors"){
            cout << "Rock beats Scissors" << endl;
            winner = "Player";
        } else if (p_choice == "Scissors" && com_choice == "Rock"){
            cout << "Rock beats Scissors" << endl;
            winner = "Computer";
        } else if (p_choice == com_choice){
            cout << p_choice << " ties " << com_choice << endl;
            winner = "No one";
        }

        cout << winner << " Wins!" << endl;

        cout << "Do you like to play again? (Y/N) ";
        cin >> proceed;

        if (proceed == "N"){
            break;
        }
    }
    return 0;
}