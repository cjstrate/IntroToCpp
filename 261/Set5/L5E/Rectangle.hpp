# include <iostream>
using namespace std;

class Rectangle {
    private:
        
        float base;
        float height;

    public:

    Rectangle();
    ~Rectangle();

    void setBase(const float VALUE);
    void setHeight(const float VALUE);
    float getBase();
    float getHeight();

    bool operator < (Rectangle OTHER);
    bool operator > (Rectangle OTHER);

};

Rectangle::Rectangle(){
    base = 1;
    height = 1;
}

Rectangle::~Rectangle(){
    base = 1;
    height = 1;
}

void Rectangle::setBase(const float VALUE){
    base = VALUE;
}

void Rectangle::setHeight(const float VALUE){
    height = VALUE;
}

float Rectangle::getBase(){
    return base;
}

float Rectangle::getHeight(){
    return height;
}

bool Rectangle::operator < (Rectangle OTHER){
    if (base == OTHER.getBase()){
        if (height < OTHER.getHeight()){
            return true;
        } else{
            return false;
        }
    }
    if (base < OTHER.getBase()){
        return true;
    } else{
        return false;
    }
}

bool Rectangle::operator > (Rectangle OTHER){
    if (base == OTHER.getBase()){
        if (height > OTHER.getHeight()){
            return true;
        } else{
            return false;
        }
    }
    if (base > OTHER.getBase()){
        return true;
    } else{
        return false;
    }
}