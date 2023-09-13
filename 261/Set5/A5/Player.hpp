# include <iostream>
using namespace std;

class Player {
    private:
        bool clockwise;
        int playerNumber;
        int chips;
    public:
        Player();
        Player(int num);
        ~Player();

        void direction();

        int getName();
        int getChips();

        void loseChips();
        void gainChips();

        void rollOutcome(int chips); 
};

Player::Player() {
    chips = 3;
    playerNumber = 1;
}

Player::Player(int num) {
    chips = 3;
    playerNumber = num;
}

Player::~Player() {
    chips = 3;
    playerNumber = 0;
}

int Player::getName() {
    return playerNumber;
}

int Player::getChips() {
    return chips;
}

void Player::loseChips() {
    chips = chips - 1;
}

void Player::gainChips() {
    chips = chips + 1;
}