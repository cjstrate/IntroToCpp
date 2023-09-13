/* CSCI 261: L2C
 *
 * Author: Carter Strate
 * Resources used: Received some help from Andrew Hett and Jordan Pettyjohn
 *
 * This program converts cartesian coordinates to polar coordinates
 */
# include <iostream>
# include <cmath>
using namespace std;

void polar_to_cartesian(const double rad, const double angle, double& xCoord, double& yCoord){
    xCoord = rad * cos(angle);
    yCoord = rad * sin(angle);
}

void cartesian_to_polar(const double xCoord, const double yCoord, double& rad, double& angle){
    rad = sqrt( (pow(xCoord,2)) + (pow(yCoord,2)));
    angle = atan( yCoord/xCoord );
}

int main() {
    int choice;
    double rad, angle, xCoord, yCoord;

    cout << "1: (r, theta) -> (x, y)" << endl << "2: (x, y) -> (r, theta)" << endl;
    cin >> choice;

    if (choice == 1){
        cout << "What is the Radius: ";
        cin >> rad;
        cout << "What is the angle: ";
        cin >> angle;
        polar_to_cartesian(rad, angle, xCoord, yCoord);
        cout << "("<< xCoord << "," << yCoord << ")";
    } else if (choice == 2){
        cout << "What is the x coordinate: ";
        cin >> xCoord;
        cout << "What is the y coordinate: ";
        cin >> yCoord;
        cartesian_to_polar(xCoord, yCoord, rad, angle);
        cout << "("<< rad << "," << angle << ")";
    } else {
        cout << "Pleas select 1 or 2";
    }

    return 0;
}