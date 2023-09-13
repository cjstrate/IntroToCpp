/* CSCI 261: Assignment 7: A7 - Triangle Land
 *
 * Author: Carter Strate
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): Jordan Pettyjohn for debugging and psudocode. Andrew Hett for debugging.
 *
 * The purpose of this program is read in the coordiantes and colors of various triangles vaidate them and then display them in a window
 */
# include <iostream>
# include <SFML/Graphics.hpp>
# include "File.hpp"
# include "Triangle.hpp"
# include <vector>

using namespace sf;
using namespace std;

int main(int argc, char* argv[1]){

    // get file input

    string fileName;
    ifstream fileIn;
    if (argc == 1){
        fileName = prompt_name_file();
    } else if(argc == 2){
        fileName = argv[1];
    } else {
        cerr << "Usage: " << argv[0] << " [filename] " << endl;
        cerr << " filename  - optional file to open upon start" << endl;
        return -2;
    }

    if (!(open_file(fileIn,fileName))){
        cerr << "Error: The chosen file could not be opened" << endl;
        return -1;
    } else {
        cout << "File opended successfully!" << endl;
    }

    // create vectors to contain the triangles

    vector<Triangle*> list;

    // validate triangles (repeat three times for each type of triangles)

    while (true){
        char Type;
        fileIn >> Type;
        if (Type == 'S'){
            // If type is a scalene triangle
            ScaleneTriangle *pNew = new ScaleneTriangle;
            double x1, x2, x3, y1, y2, y3;
            // input the value to their respective coordinates 
            fileIn >> x1;
            fileIn >> y1;
            fileIn >> x2;
            fileIn >> y2;
            fileIn >> x3;
            fileIn >> y3;

            // input RGB values

            int red, green, blue;

            fileIn >> red;
            fileIn >> green;
            fileIn >> blue;

            bool valid;

            // check to see if the triangle is valid

            valid = pNew -> setCoordinates(x1,y1,x2,y2,x3,y3);

            if (valid){
                // if valid set the color and add the triangle to the vector
                pNew -> setColor(Color(red,green,blue));
                list.push_back(pNew);
            } else {
                cout << "triangle is invalid - " << "\"" << Type << " " << x1 << " " << y1 << " ";
                cout << x2 << " " << y2 << " " << x3 << " " << y3 << " " << red << " " << green << " " << blue << "\"" << endl;
            }
        } else if (Type == 'E'){
            // If the triangle is Equilateral
            // repeat the above steps for an equilateral triangle
            EquilateralTriangle *pNew = new EquilateralTriangle;
            double x1, x2, x3, y1, y2, y3;
            fileIn >> x1;
            fileIn >> y1;
            fileIn >> x2;
            fileIn >> y2;
            fileIn >> x3;
            fileIn >> y3;

            int red, green, blue;

            fileIn >> red;
            fileIn >> green;
            fileIn >> blue;

            bool valid;

            valid = pNew -> setCoordinates(x1,y1,x2,y2,x3,y3);

            if (valid){
                pNew -> setColor(Color(red,green,blue));
                list.push_back(pNew);
            } else {
                cout << "triangle is invalid - " << "\"" << Type << " " << x1 << " " << y1 << " ";
                cout << x2 << " " << y2 << " " << x3 << " " << y3 << " " << red << " " << green << " " << blue << "\"" << endl;
            }
        } else if (Type == 'I'){
            // If triangle is Isosceles
            // Repeat steps for and Isosceles triangle
            IsoscelesTriangle *pNew = new IsoscelesTriangle;
            double x1, x2, x3, y1, y2, y3;
            fileIn >> x1;
            fileIn >> y1;
            fileIn >> x2;
            fileIn >> y2;
            fileIn >> x3;
            fileIn >> y3;

            int red, green, blue;

            fileIn >> red;
            fileIn >> green;
            fileIn >> blue;

            bool valid;

            valid = pNew -> setCoordinates(x1,y1,x2,y2,x3,y3);

            if (valid){
                pNew -> setColor(Color(red,green,blue));
                list.push_back(pNew);
            } else {
                cout << "triangle is invalid - " << "\"" << Type << " " << x1 << " " << y1 << " ";
                cout << x2 << " " << y2 << " " << x3 << " " << y3 << " " << red << " " << green << " " << blue << "\"" << endl;
            }
        }
        // check if at the end of the file
        if (fileIn.eof()){
            break;
        }
    }
    fileIn.close();

    RenderWindow window( VideoMode(640, 640), "Window");
    // draw all the triangles in the vector
    Event event;
    while (window.isOpen()){
        window.clear();

        // Iterate through the vector and draw all triangles inside
        
        for (unsigned int i = 0; i < list.size(); i++){
            list[i] -> draw(window);
        }

        window.display();
        while( window.pollEvent(event) ) {
            if(event.type == Event::Closed) {
                window.close();
            }
        }
    }

    // deallocate the the classes in the list

    for (unsigned int i = 0; i < list.size(); i++){
        delete[] list[i];
    }

    return 0;
}