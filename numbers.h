#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class numbers {
public:
    numbers() {
    }
    ~numbers() {
    }

    //convert from a roman numeral to a decimal number
    int toDeci(string const& input) {
        int sum = 0;
        for (int i = 0; i < input.length(); i++) {
            auto a = romanNums.find(input[i]);
            auto b = romanNums.find(input[i + 1]);

            //don't try to access i+1 on last iteration
            if (i == input.length() - 1) {
                sum += a->second;
                break;
            }
            //if the previous number is greater than the current number, add.
            if (a->second >= b->second) {
                sum += a->second;
            }
            //if previous number is smaller than the current number, but not too small, subtract.
            else if (a->second * 10 < b->second) {
                cout << "NOT VALID INPUT" << endl;
                return 0;
            } else {
                sum -= a->second;
            }
        }
        return sum;
    }

    string toRoman(int& input) {
        int numOfChar = 0;
        string result = "";
        //loop through the map keys (the possible roman numerals) in the right order
        for (int i = 0; i < mapOrder.size(); i++) {
            auto c = romanNums.find(mapOrder[i]);
            //numOfChar is the number of that roman numeral that is needed
            numOfChar = input / c->second;
            //concatenate the roman numeral numOfChar times to result
            result += string(numOfChar, c->first);
            input %= c->second;
        }
        return result;
    }
private:
    const unordered_map<char, int> romanNums = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
    };
    //use a vector to keep the map in the right order for the toRoman function
    vector<char> mapOrder = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
};