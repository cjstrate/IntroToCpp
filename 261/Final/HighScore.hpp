#include <iostream>
using namespace std;

class HighScore{
    private:
        string name;
        int score;
    public:
        HighScore(string name, int score);

        string getName();
        int getScore();

        void setName(string input);
        void setScore(int input);
};

HighScore::HighScore(string userName, int userScore){
    name = userName;
    score = userScore;
}

string HighScore::getName(){
    return name;
}

int HighScore::getScore(){
    return score;
}

void HighScore::setName(string input){
    name = input;
}

void HighScore::setScore(int input){
    score = input;
}