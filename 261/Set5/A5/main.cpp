/* CSCI 261: Assignment 5: A5 - Wild Left-Center-Right Simulation
 *
 * Author: Carter Strate
 * Resources used: Jordan Pettyjohn for debugging and psudocode
 *
 * The point of this program was to have the computer play a game however mine does not work
 */
// this code does not work. for some reason the player name is always 0 and i have no idea were it came from. it also loops ifinitly (i have it stopping after five rounds)
// The number of chips does not decrease when I call the funciton to do so. I am sorry you have to look at this.
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "CircularlyDoublyLinkedList.hpp"
# include "Player.hpp"

using namespace std;

int diceRoll(){
    return (rand() % 8);
}

void playGame(CircularlyDoublyLinkedList<Player> &Object, int direction, int turns,int player){
    int currentPlayers;
    int center = 0;
    turns++;
    for (int i = 0; i < Object.size(); i++){
        if (Object.get(i).getChips() > 0){
            currentPlayers++;
        }
    }
    if (currentPlayers <= 1){
        Player winner;
        for (int i = 0; i < Object.size(); i++){
            if (Object.get(player).getChips() > 0){
                winner = Object.get(player);
                cout << "Player #" << winner.getName() << " wins with " << winner.getChips() << " chips left after " << turns << endl; 
            } else{
                if (player = (Object.size() - 1)){
                    player = 0;
                } else{
                    player++;
                }
            }
        }
        return;
    }
    int chips = Object.get(player).getChips();
    cout << "Player #" << Object.get(player).getName() << " has " << chips << " chips left" << endl;
    if (chips > 3){
        chips = 3;
    } 
    cout << "   Rolling " << chips << " dice" << endl;
    
    int numSkips = 1;


    for (int i = 0; i < chips; i++){
        int num = diceRoll();
        if (num == 3){
            cout << "   Rolled a 3 - give left - "; 
            Object.get(player).loseChips();

            if (player = (Object.size() - 1)){
                    player = 0;
                } else{
                    player++;
                }
 
            cout << "Player #" << Object.get(player).getName() << " has " << Object.get(player).getChips() << " chips left - ";

            Object.get(player).gainChips();
            if (player = 0){
                player = Object.size() - 1;
            } else {
                player--;
            }

            cout << "Player #" << Object.get(player).getName() << " has " << Object.get(player).getChips() << " chips left" << endl;

        } else if (num == 4){
            cout << "   Rolled a 4 - give right - ";
            Object.get(player).loseChips();
            if (player = 0){
                player = Object.size() - 1;
            } else {
                player--;
            }
            cout << "Player #" << Object.get(player).getName() << " has " << Object.get(player).getChips() << " chips left - ";

            Object.get(player).gainChips();
            if (player = (Object.size() - 1)){
                    player = 0;
                } else{
                    player++;
                }
 
            cout << "Player #" << Object.get(player).getName() << " has" << Object.get(player).getChips() << " chips left" << endl;

        } else if (num == 5){
            cout << "   Rolled a 5 - give center - ";
            Object.get(player).loseChips();
            center++;
            cout << "Center has " << center << " chips - Player #" << Object.get(player).getChips() << " has " << Object.get(player).getChips() << " chips left" << endl;
        } else if (num == 6){
            cout << "   Rolled a 6 - reverse!" << endl;
            direction = direction * -1;
        } else if (num == 7){
            if (direction == 1){
                cout << "   Rolled a 7 - skip! skipping " << numSkips << " players" << endl;
                numSkips++;
            }
        } else {
            cout << "   Rolled a " << num << " - keep!" << endl;
        }
    }
    for (int i = 0; i < numSkips; i++){
        if (direction == 1){
            if (player = (Object.size() - 1)){
                    player = 0;
                } else{
                    player++;
                }
        } else {
            if (player = 0){
                player = Object.size() - 1;
            } else {
                player--;
            }
        }
    }
    turns ++;
    playGame(Object,direction,turns, player);
    
}

int main(){

    CircularlyDoublyLinkedList<Player> game;

    int numPlayers;
    cout << "How many players are playing: ";
    cin >> numPlayers;
    cout << "1" << endl;
    int n = 1;
    for (int i = 0; i < numPlayers; i++){
        Player New(n);
        game.insert(0, New);
        n++; 
    } 
    srand(time(0));
    game.traverseCCW();
    playGame(game, 1, 0, 0);
    cout << "Done" << endl;

    return 0;
} 