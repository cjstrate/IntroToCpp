# include <cstdlib>
# include <iostream>
# include <ctime>

using namespace std;

int main(){
    float out, Q1, Q2, Q3, min, max;

    cout << "Enter the minimum value: ";
    cin >> min;
    cout << "Enter the maximum value: ";
    cin >> max;
    
    srand ( time(0) );

    rand();
    
    out = rand() / (double)RAND_MAX * (max - min) + min;

    Q2 = (min + max) / 2;
    Q1 = (Q2 + min) / 2;
    Q3 = (Q2 + max) / 2;

    cout << "A random value is: ";
    cout << out << endl;

    if (out > Q3) {
        cout << "This is in the fourth quartile"; 
    } else if (out > Q2) {
        cout << "This is in the third quartile";
    } else if (out > Q1) {
        cout << "This is in the second quartile";
    } else {
        cout << "This is in the first quartile";
    }

    return 0;
}