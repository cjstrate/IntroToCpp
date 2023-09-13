#include "star.hpp"
#include "File.hpp"
#include <vector>

using namespace std;
// Allow user to pass in file from terminal
int main(int argc, char* argv[1]){

    // Have user input file.
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

    // Check if file can be opened
    if (!(open_file(fileIn,fileName))){
        cerr << "Error: The chosen file could not be opened" << endl;
        return -1;
    } else {
        cout << "File opended successfully!" << endl;
    }

    vector<float> starData;
    float num { 0 };
    while (fileIn >> num) {
        starData.emplace_back(num);
    }

    int numLines = starData.size()/6;
 
    float maxBrightness = 0;
    for (int i = 0; i < numLines; i++) {
        if ( starData[3+i*6] > maxBrightness && starData[3+i*6] < 8) {
            maxBrightness = starData[3+i*6];
        }
    }

    RenderWindow window( VideoMode(640, 640), "Star Map" );
    Event event;
    while( window.isOpen() ) {
        window.clear();

        for (int i = 0; i < numLines; i++) {
            if ( starData[3+i*6] < 8) {
                float x = starData[0+i*6];
                float y = starData[1+i*6];

                float brightness = starData[3+i*6];

                Star newStar(640, 640, maxBrightness);
                newStar.setPosition(x, y);
                newStar.setBrightness(brightness);
                window.draw(newStar);
            }
        }

        window.display();
        while( window.pollEvent(event) ) {
            if(event.type == Event::Closed) {
                window.close();
            }
        }
    }

    fileIn.close();
    return 0;
}