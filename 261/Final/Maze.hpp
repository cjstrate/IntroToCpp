# include <iostream>
# include <SFML/Graphics.hpp>
# include "Node.h"
# include <ctime>
# include <cstdlib>
using namespace std;
using namespace sf;

class Maze : public RectangleShape {
    private:
        // pointers that point to all the nodes that make up the maze
        Node *pStart;
        Node *pEnd;
        Node *p1;
        Node *p2;
        Node *p3;
        Node *p4;
        Node *p5;
        Node *p6;
        Node *p7;
        Node *p8;
        Node *p9;
        Node *p10;
        Node *p11;
        Node *p12;
        Node *p13;
        Node *p14;
        Node *p15;
        Node *p16;
        Node *p17;
        Node *p18;
        Node *p19;
        Node *p20;
        Node *p21;
        Node *p22;
        Node *p23;
        Node *p24;
        // a pointer that tracks the players location and the pursuers location
        Node *pPlayer;
        Node *pPursuer;
    public:
        // constructor/deconstructor
        Maze();
        ~Maze();
        // a fucntion that will traverse the player in a chosen direction
        int traversePlayer(int i, bool &cont, bool &win);
        // a funtion that will traverse the pursuer in a random direction
        void traversePursuer();
        // a funtion to draw the map
        void mapDraw();
        // a graphic if you are caught by the pursuer
        void gameOver();
};

Maze::Maze(){
    cout << "in" << endl;
    // due to the nature of the maze I coud not just us a head pointer and a tail pointer
    // since the maze will have dead ends and loops the best method I thought of for construction
    // and deconstruciton was to initialize all the connections by hand
    pStart = new Node;
    pEnd = new Node;
    p1 = new Node;
    p2 = new Node;
    p3 = new Node;
    p4 = new Node;
    p5 = new Node;
    p6 = new Node;
    p7 = new Node;
    p8 = new Node;
    p9 = new Node;
    p10 = new Node;
    p11= new Node;
    p12 = new Node;
    p13 = new Node;
    p14 = new Node;
    p15 = new Node;
    p16 = new Node;
    p17 = new Node;
    p18 = new Node;
    p19 = new Node;
    p20 = new Node;
    p21 = new Node;
    p22 = new Node;
    p23 = new Node;
    p24 = new Node;

    pPlayer = new Node;
    pPursuer = new Node;

    pStart -> discovered = true;
    pStart -> pNorth = p1;;
    pStart -> pEast = p4;
    pStart -> pSouth = p12;
    pStart -> pWest = p3;

    p1 -> discovered = false;
    p1 -> pNorth = p8;
    p1 -> pEast = nullptr;
    p1 -> pSouth = pStart;
    p1 -> pWest = p2;

    p2 -> discovered = false;
    p2 -> pNorth = nullptr;
    p2 -> pEast = p1;
    p2 -> pSouth = p3;
    p2 -> pWest = nullptr;

    p3 -> discovered = false;
    p3 -> pNorth = p2;
    p3 -> pEast = pStart;
    p3 -> pSouth = nullptr;
    p3 -> pWest = p23;

    p4 -> discovered = false;
    p4 -> pNorth = nullptr;
    p4 -> pEast = p5;
    p4 -> pSouth = nullptr;
    p4 -> pWest = pStart;

    p5 -> discovered = false;
    p5 -> pNorth = p6;
    p5 -> pEast = nullptr;
    p5 -> pSouth = nullptr;
    p5 -> pWest = p4;

    p6 -> discovered = false;
    p6 -> pNorth = p7;
    p6 -> pEast = nullptr;
    p6 -> pSouth = p5;
    p6 -> pWest = nullptr;

    p7 -> discovered = false;
    p7 -> pNorth = nullptr;
    p7 -> pEast = nullptr;
    p7 -> pSouth = p6;
    p7 -> pWest = nullptr;

    p8 -> discovered = false;
    p8 -> pNorth = p9;
    p8 -> pEast = nullptr;
    p8 -> pSouth = p1;
    p8 -> pWest = nullptr;

    p9 -> discovered = false;
    p9 -> pNorth = p11;
    p9 -> pEast = nullptr;
    p9 -> pSouth = p8;
    p9 -> pWest = p10;
    p10 -> discovered = false;
    p10 -> pNorth = nullptr;
    p10 -> pEast = p9;
    p10 -> pSouth = nullptr;
    p10 -> pWest = nullptr;

    // I am slighly regretting my choice to do this

    p11 -> discovered = false;
    p11 -> pNorth = nullptr;
    p11 -> pEast = nullptr;
    p11 -> pSouth = p9;
    p11 -> pWest = nullptr;

    p12 -> discovered = false;
    p12 -> pNorth = pStart;
    p12 -> pEast = nullptr;
    p12 -> pSouth = p13;
    p12 -> pWest = nullptr;

    p13 -> discovered = false;
    p13 -> pNorth = p12;
    p13 -> pEast = nullptr;
    p13 -> pSouth = nullptr;
    p13 -> pWest = p14;

    p14 -> discovered = false;
    p14 -> pNorth = nullptr;
    p14 -> pEast = p13;
    p14 -> pSouth = nullptr;
    p14 -> pWest = p15;

    p15 -> discovered = false;
    p15 -> pNorth = nullptr;
    p15 -> pEast = p14;
    p15 -> pSouth = p16;
    p15 -> pWest = p17;

    p16 -> discovered = false;
    p16 -> pNorth = p15;
    p16 -> pEast = nullptr;
    p16 -> pSouth = nullptr;
    p16 -> pWest = nullptr;

    p17 -> discovered = false;
    p17 -> pNorth = p21;
    p17 -> pEast = p15;
    p17 -> pSouth = nullptr;
    p17 -> pWest = p18;

    p18 -> discovered = false;
    p18 -> pNorth = p19;
    p18 -> pEast = p17;
    p18 -> pSouth = nullptr;
    p18 -> pWest = nullptr;

    p19 -> discovered = false;
    p19 -> pNorth = pEnd;
    p19 -> pEast = nullptr;
    p19 -> pSouth = p18;
    p19 -> pWest = p20;

    p20 -> discovered = false;
    p20 -> pNorth = nullptr;
    p20 -> pEast = p19;
    p20 -> pSouth = nullptr;
    p20 -> pWest = nullptr;

    // AAHHHHHHHH almost there

    p21 -> discovered = false;
    p21 -> pNorth = p24;
    p21 -> pEast = nullptr;
    p21 -> pSouth = p17;
    p21 -> pWest = nullptr;

    p22 -> discovered = false;
    p22 -> pNorth = p23;
    p22 -> pEast = nullptr;
    p22 -> pSouth = p15;
    p22 -> pWest = nullptr;

    p23 -> discovered = false;
    p23 -> pNorth = nullptr;
    p23 -> pEast = p3;
    p23 -> pSouth = p22;
    p23 -> pWest = p24;

    p24 -> discovered = false;
    p24 -> pNorth = nullptr;
    p24 -> pEast = p23;
    p24 -> pSouth = p21;
    p24 -> pWest = nullptr;

    pEnd -> discovered = false;
    pEnd -> pNorth = nullptr;
    pEnd -> pEast = nullptr;
    pEnd -> pSouth =p19;
    pEnd -> pWest = nullptr;


    // Now I set the starting posistions of the player and pursuer
    pPlayer = pStart;
    pPursuer = p21;
}

Maze::~Maze(){
    delete pStart;
    delete pEnd;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    delete p7;
    delete p8;
    delete p9;
    delete p10;
    delete p11;
    delete p12;
    delete p13;
    delete p14;
    delete p15;
    delete p16;
    delete p17;
    delete p18;
    delete p19;
    delete p20;
    delete p21;
    delete p22;
    delete p23;
    delete p24;
    delete pPlayer;
    delete pPursuer;

    pStart = nullptr;
    pEnd = nullptr;
    p1 = nullptr;
    p2 = nullptr;
    p3 = nullptr;
    p4 = nullptr;
    p5 = nullptr;
    p6 = nullptr;
    p7 = nullptr;
    p8 = nullptr;
    p9 = nullptr;
    p10 = nullptr;
    p11 = nullptr;
    p12 = nullptr;
    p13 = nullptr;
    p14 = nullptr;
    p15 = nullptr;
    p16 = nullptr;
    p17 = nullptr;
    p18 = nullptr;
    p19 = nullptr;
    p20 = nullptr;
    p21 = nullptr;
    p22 = nullptr;
    p23 = nullptr;
    p24 = nullptr;
    pPlayer = nullptr;
    pPursuer = nullptr;
}

int Maze::traversePlayer(int i, bool &cont, bool &win){
    if (pPlayer -> pNorth != nullptr){
        cout << "North = OPEN" << endl;
    } else {
        cout << "North = closed" << endl;
    }

    if (pPlayer -> pEast != nullptr){
        cout << "East = OPEN" << endl;
    } else {
        cout << "East = closed" << endl;
    }

    if (pPlayer -> pSouth!= nullptr){
        cout << "South = OPEN" << endl;
    } else {
        cout << "South = closed" << endl;
    }

    if (pPlayer -> pWest != nullptr){
        cout << "West = OPEN" << endl;
    } else {
        cout << "West = closed" << endl;
    }

    cout << "Choose a direction to go" << endl;

    cout << "[1] North" << endl << "[2] East" << endl << "[3] South" << endl << "[4] West" << endl << "[5] Open Map" << endl;
    cout << "Choice: ";

    string value;
    
    cin >> value;

    if (value == "1"){
        if (pPlayer -> pNorth != nullptr){
            pPlayer -> pNorth -> discovered = true;
            pPlayer = pPlayer -> pNorth;
            cout << "You walk through the door" << endl;
            traversePursuer();
            i++;
        } else {
            cout << "You walk directly into a wall and do not leave the room" << endl;
            traversePursuer();
            i++;
        }
    } else if (value == "2"){
        if (pPlayer -> pEast != nullptr){
            pPlayer -> pEast -> discovered = true;
            pPlayer = pPlayer -> pEast;
            cout << "You walk through the door" << endl;
            traversePursuer();
            i++;
        } else {
            cout << "You walk directly into a wall and do not leave the room" << endl;
            traversePursuer();
            i++;
        }
    } else if (value == "3"){
        if (pPlayer -> pSouth != nullptr){
            pPlayer -> pSouth -> discovered = true;
            pPlayer = pPlayer -> pSouth;
            cout << "You walk through the door" << endl;
            traversePursuer();
            i++;
        } else {
            cout << "You walk directly into a wall and do not leave the room" << endl;
            traversePursuer();
            i++;
        }
    } else if (value == "4"){
        if (pPlayer -> pWest != nullptr){
            pPlayer -> pWest -> discovered = true;
            pPlayer = pPlayer -> pWest;
            cout << "You walk through the door" << endl;
            traversePursuer();
            i++;
        } else {
            cout << "You walk directly into a wall and do not leave the room" << endl;
            traversePursuer();
            i++;
        }
    }else if (value == "5"){
        mapDraw();
    } else {
        cout << "You stand aimlessly in the middle of the room as that was not a valid choice" << endl;
        traversePursuer();
        i++;
    }
    
    if (pPlayer == pPursuer){
        cout << "The pursuer has caught you!" << endl;
        gameOver();
        cont = false;
    }

    if (pPlayer == pEnd){
        cout << "Congratulations you found the end!" << endl;
        win = true;
        cont = false;
    }

    return i;
}

void Maze::traversePursuer(){
    srand(time(0));

    rand();

    int dir = rand() % (4 - 3 + 1) + 1;

    if (dir == 1){
        if (pPursuer -> pNorth != nullptr){
            pPursuer = pPursuer -> pNorth;
        }
    } else if (dir == 2){
        if (pPursuer -> pEast != nullptr){
            pPursuer = pPursuer -> pEast;
        }
    } else if (dir == 3){
        if (pPursuer -> pSouth != nullptr){
            pPursuer = pPursuer -> pSouth;
        }
    } else if (dir == 4){
        if (pPursuer -> pWest != nullptr){
            pPursuer = pPursuer -> pWest;
        }
    }
}

void Maze::mapDraw(){
    RenderWindow window(VideoMode(640,640), "Map");
    Event event;
    int centerX = 320;
    int centerY = 320;
    int sep = 50;
    while (window.isOpen()) {
        window.clear();
        
        if (pStart -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX,centerY);
            if (pPlayer == pStart){
                start.setFillColor(Color::Green);
            } else if (pPursuer == pStart){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p1 -> discovered){
            RectangleShape room1;
            room1.setSize(Vector2f(30,30));
            room1.setPosition(centerX,centerY - sep);
            if (pPlayer == p1){
                room1.setFillColor(Color::Green);
            } else if (pPursuer == p1){
                room1.setFillColor(Color::Red);
            } else {
                room1.setFillColor(Color::Blue);
            }
            window.draw(room1);
        }

        if (p2 -> discovered){
            RectangleShape room2;
            room2.setSize(Vector2f(30,30));
            room2.setPosition(centerX - sep, centerY - sep);
            if (pPlayer == p2){
                room2.setFillColor(Color::Green);
            } else if (pPursuer == p2){
                room2.setFillColor(Color::Red);
            } else {
                room2.setFillColor(Color::Blue);
            }
            window.draw(room2);
        }

        if (p3 -> discovered){
            RectangleShape room3;
            room3.setSize(Vector2f(30,30));
            room3.setPosition(centerX - sep,centerY);
            if (pPlayer == p3){
                room3.setFillColor(Color::Green);
            } else if (pPursuer == p3){
                room3.setFillColor(Color::Red);
            } else {
                room3.setFillColor(Color::Blue);
            }
            window.draw(room3);
        }

        if (p4 -> discovered){
            RectangleShape room4;
            room4.setSize(Vector2f(30,30));
            room4.setPosition(centerX + sep,centerY);
            if (pPlayer == p4){
                room4.setFillColor(Color::Green);
            } else if (pPursuer == p4){
                room4.setFillColor(Color::Red);
            } else {
                room4.setFillColor(Color::Blue);
            }
            window.draw(room4);
        }

        if (p5 -> discovered){
            RectangleShape room5;
            room5.setSize(Vector2f(30,30));
            room5.setPosition(centerX + 2*sep,centerY);
            if (pPlayer == p5){
                room5.setFillColor(Color::Green);
            } else if (pPursuer == p5){
                room5.setFillColor(Color::Red);
            } else {
                room5.setFillColor(Color::Blue);
            }
            window.draw(room5);
        }

        if (p6 -> discovered){
            RectangleShape room6;
            room6.setSize(Vector2f(30,30));
            room6.setPosition(centerX + 2*sep,centerY - sep);
            if (pPlayer == p6){
                room6.setFillColor(Color::Green);
            } else if (pPursuer == p6){
                room6.setFillColor(Color::Red);
            } else {
                room6.setFillColor(Color::Blue);
            }
            window.draw(room6);
        }

        if (p7 -> discovered){
            RectangleShape room7;
            room7.setSize(Vector2f(30,30));
            room7.setPosition(centerX + 2*sep,centerY - 2*sep);
            if (pPlayer == p7){
                room7.setFillColor(Color::Green);
            } else if (pPursuer == p7){
                room7.setFillColor(Color::Red);
            } else {
                room7.setFillColor(Color::Blue);
            }
            window.draw(room7);
        }

        if (p8 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX,centerY - 2*sep);
            if (pPlayer == p8){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p8){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p9 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX,centerY - 3*sep);
            if (pPlayer == p9){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p9){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p10 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - sep,centerY - 3*sep);
            if (pPlayer == p10){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p10){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p11 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX,centerY - 4*sep);
            if (pPlayer == p11){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p11){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p12 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX,centerY + sep);
            if (pPlayer == p12){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p12){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p13 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX,centerY + 2*sep);
            if (pPlayer == p13){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p13){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p14 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - sep,centerY + 2*sep);
            if (pPlayer == p14){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p14){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p15 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 2*sep,centerY + 2*sep);
            if (pPlayer == p15){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p15){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p16 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 2*sep,centerY + 3*sep);
            if (pPlayer == p16){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p16){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p17 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 3*sep,centerY + 2*sep);
            if (pPlayer == p17){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p17){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p18 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 4*sep,centerY + 2*sep);
            if (pPlayer == p18){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p18){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p19 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 4*sep,centerY + sep);
            if (pPlayer == p19){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p19){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p20 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 5*sep,centerY + sep);
            if (pPlayer == p20){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p20){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p21 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 3*sep,centerY + sep);
            if (pPlayer == p21){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p21){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p22 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 2*sep,centerY + sep);
            if (pPlayer == p22){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p22){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p23 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 2*sep,centerY);
            if (pPlayer == p23){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p23){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (p24 -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 3*sep,centerY);
            if (pPlayer == p24){
                start.setFillColor(Color::Green);
            } else if (pPursuer == p24){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        if (pEnd -> discovered){
            RectangleShape start;
            start.setSize(Vector2f(30,30));
            start.setPosition(centerX - 4*sep,centerY );
            if (pPlayer == pEnd){
                start.setFillColor(Color::Green);
            } else if (pPursuer == pEnd){
                start.setFillColor(Color::Red);
            } else {
                start.setFillColor(Color::Blue);
            }
            window.draw(start);
        }

        window.display();

        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
    }
}

void Maze::gameOver(){
    int posX = 1600;
    RenderWindow window( VideoMode(1500,900), "Game Over");

    Event event;

    while(window.isOpen()){
        window.clear();
        Texture image;
    image.loadFromFile("FullSizeRender.png");
    Sprite sprite;
    sprite.setTexture(image);
    sprite.setPosition(0,0);
    sprite.setTextureRect(sf::IntRect(1300, 900, 1000, 1200));
    sprite.setPosition(posX,0);
    window.draw(sprite);
    if (posX > 620){
        posX = posX - 50;
    }

    window.display();

    while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
    }
}