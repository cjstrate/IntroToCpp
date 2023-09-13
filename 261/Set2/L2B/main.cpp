/* CSCI 261: L2B
 *
 * Author: Carter Strate
 * Resources used: Received some help from Andrew Hett and Jordan Pettyjohn
 *
 * This program generates 10 ranodm floats and 10 random integers between two valuse (both inclusive and otherwise)
 */
# include <iostream>
# include <ctime>
# include <cstdlib>
# include <iomanip>
using namespace std;

int generate_random_integer(int max, bool maxInclusive, int min, bool minInclusive){
    if (maxInclusive == 1 && minInclusive == 1){
    } else if (maxInclusive == 0 && minInclusive == 0) {
        max--;
        min++;
    } else if (maxInclusive == 0){
        max--;
    } else{
        min++;
    }
    rand();
    return rand() % (max - min + 1) + min;
}

// I do not know how to make a random float between two numbers non inclusivley so I just subtracted a really small decimal off the max and added that same decimal to min to change
// the inclusive range by a tiny bit.
float generate_random_float(float max, bool maxInclusive, float min, bool minInclusive){
    if (maxInclusive == 1 && minInclusive == 1){
    } else if (maxInclusive == 0 && minInclusive == 0) {
        max = max - (1 / (double)RAND_MAX);
        min = min + (1 / (double)RAND_MAX);
    } else if (maxInclusive == 0){
        max = max - (1 / (double)RAND_MAX);
    } else{
        min = min + (1 / (double)RAND_MAX);
    }
    rand();
    return rand() / (double)RAND_MAX * (max - min) + min;
}

int main(){
    int max, min;
    bool minIn, maxIn;

    srand( time(0) );

    cout << "Enter the lower range for the random int/float: ";
    cin >> min;
    cout << "Is this value inclusive (1 = True and 0 = Flase): ";
    cin >> minIn;
    cout << "Enter the upper range for the random int/float: ";
    cin >> max;
    cout << "Is this value inclusive (1 = True and 0 = Flase): ";
    cin >> maxIn;

    cout << "10 Integers" << endl;
    for (int i = 1; i <= 10; i++){
        cout << generate_random_integer(max, maxIn, min, minIn) << endl;
    }

    cout << "10 floats" << endl;
    for (int i = 1; i<=10; i++){
        cout << setprecision(4) << generate_random_float(max, maxIn, min, minIn) << endl;
    }
    return 0;
}