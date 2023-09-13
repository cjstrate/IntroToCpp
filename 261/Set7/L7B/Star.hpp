# include <iostream>
# include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Star : public CircleShape{
    private:
        int windowWidth;
        int windowHeight;
        float maxBrightness;
    public:
        Star(int Wdth, int Height, float Max);
        void setPosition(float x, float y);
        void setBrightness(float value);
};

Star::Star(int Width, int Height, float max){
    windowWidth = Width;
    windowHeight = Height;
    maxBrightness = max;

    setRadius(2.0);
    
    setPosition(0.0f, 0.0f);
}

void Star::setPosition(float x, float y){
    float xPixel = (x + 1.0) * windowWidth / 2.0;
    float yPixel = (-y + 1.0) * windowHeight / 2.0;

    CircleShape::setPosition(xPixel, yPixel);
}

void Star::setBrightness(float value){
    int invertedBrightness = maxBrightness - value;
    int shadeOfGray = (int)( ( 255.0 * invertedBrightness ) / maxBrightness);
    
    CircleShape::setFillColor(Color(shadeOfGray,shadeOfGray,shadeOfGray));
}