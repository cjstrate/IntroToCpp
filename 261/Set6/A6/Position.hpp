# include <iostream>
using namespace std;

class Position {

    private:
        int row;
        int col;

    public:
        Position();
        Position(int, int);
        ~Position();

        int getRow();
        int getCol();

        void setRow(int);
        void setCol(int);

};

Position::Position(){
    row = 0;
    col = 0;
}

Position::Position(int Row, int Col){
    row = Row;
    col = Col;
}

Position::~Position(){
    row = 0;
    col = 0;
}

int Position::getRow(){
    return row;
}

int Position::getCol(){
    return col;
}

void Position::setRow(int value){
    row = value;
}

void Position::setCol(int value){
    col = value;
}