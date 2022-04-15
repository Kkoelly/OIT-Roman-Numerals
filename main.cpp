#include <iostream>
#include <map>
#include <string>
#include "numbers.h"

using namespace std;

int main() {
    char option;
    numbers num;

    do {
        cout << "Choose (1) roman to decimal, or (2) decimal to roman: " << endl;
        cin >> option;
    }
    while(!(option == '1' || option == '2'));

    if (option == '1') {
        string input;
        cout << "Enter the number to convert: " << endl;
        cin >> input;
        cout << num.toDeci(input) << endl;
    }
    else if (option == '2') {
        int input;
        cout << "Enter the number to convert: " << endl;
        cin >> input;
        cout << num.toRoman(input) << endl;
    }

    return 0;
}

