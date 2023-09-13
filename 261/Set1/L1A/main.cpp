#include <iostream>

using namespace std;

int main() {
    float stress, force, area, volts, resistance, current;
    cout << "Enter force: ";
    cin >> force;
    cout << "Enter area: ";
    cin >> area;
    stress = force / area;
    cout << "Stress: " << stress << endl;
    cout << "Enter volts: ";
    cin >> volts;
    cout << "Enter resistance: ";
    cin >> resistance;
    current = volts / resistance;
    cout << "Current: " << current;

    
    
    return 0;
}