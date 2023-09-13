#include <iostream>

using namespace std;

int main() {
    
    int while_n = 0, do_while_n = 0, for_n = 0;

    cout << "while loop Na'ing" << endl;
    while ( while_n < 4) {
        cout << "Na" << endl;
        while_n++;
    }
    
    cout << "do-while loop Na'ing" << endl;
    do {
        cout << "Na" << endl;
        do_while_n++;
    } while ( do_while_n < 4);

    cout << "for loop Na'ing" << endl;
    for (for_n; for_n < 4; for_n++){
        cout << "Na" << endl;
    }

    return 0;
}