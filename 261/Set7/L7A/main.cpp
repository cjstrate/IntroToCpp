#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    // create a window
    RenderWindow window( VideoMode(1300, 800), "Shapes go " );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // while the window is open
    int posX = 15;
    int posY = 15;
    bool dirX = true;
    bool dirY = true;
    int posX2 = 400;
    int posY2 = 700;
    bool dirX2 = false;
    bool dirY2 = true;
    float recAng = 45;
    float recAng2 = 225;
    int circPosX = 650;
    int circPosY = 0;
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        CircleShape star;
        star.setPosition( posX, posY );
        star.setRadius(40 );
        star.setFillColor( Color::Yellow );
        window.draw( star);
        /////////////////////////////////////

        if (posX >= 1300){
            dirX = false;
        }

        if (posY >= 800){
            dirY = false;
        }

        if (posX <= 0){
            dirX = true;
        }

        if (posY <= 0){
            dirY = true;
        }

        if (dirX){
            posX++;
        } else {
            posX--;
        }

        if (dirY){
            posY++;
        } else {
            posY--;
        }

        CircleShape star2;
        star.setPosition( posX2, posY2 );
        star.setRadius(40 );
        star.setFillColor( Color::Blue );
        window.draw( star);
        /////////////////////////////////////

        if (posX2 >= 1300){
            dirX2 = false;
        }

        if (posY2 >= 800){
            dirY2 = false;
        }

        if (posX2 <= 0){
            dirX2 = true;
        }

        if (posY2 <= 0){
            dirY2 = true;
        }

        if (dirX2){
            posX2++;
        } else {
            posX2--;
        }

        if (dirY2){
            posY2++;
        } else {
            posY2--;
        }

        RectangleShape rec;
        rec.setSize (Vector2f(40, 50));
        rec.setPosition(650, 400);
        rec.setFillColor(Color::Green);
        rec.setRotation(recAng);
        window.draw(rec);

        recAng = recAng + 0.1;

        RectangleShape rec2;
        rec2.setSize (Vector2f(40, 50));
        rec2.setPosition(650, 400);
        rec2.setFillColor(Color::Red);
        rec2.setRotation(recAng2);
        window.draw(rec2);

        recAng2 = recAng2 + 0.1;

        CircleShape circle;

        circle.setRadius(20);
        circle.setPosition(circPosX, circPosY);
        circle.setFillColor(Color(200,40,150));
        window.draw(circle);

        if (circPosY >= 800){
            circPosY = 0;
            circPosX = circPosX + 50;
        } else {
            circPosY++;
        }

        if (circPosX >= 1300){
            circPosX = 0;
        }

        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}