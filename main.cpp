#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<char, int> romanNums = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},

    };
    string input = "CDXXX";
    int sum = 0;

    for (int i = 0; i < input.length(); i++) {
        if (i == input.length() - 1) {
            sum += romanNums[input[i]];
            break;
        }
        if (romanNums[input[i+1]] <= romanNums[input[i]]) {
            sum += romanNums[input[i]];
        }
        else {
            if (romanNums[input[i]] * 10 < romanNums[input[i+1]]) {
                cout << "NOT VALID INPUT" << endl;
                break;
            }
            else {
                sum -= romanNums[input[i]];
            }
        }
    }

    cout << sum << endl;
    

    return 0;
}
