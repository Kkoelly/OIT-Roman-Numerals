#pragma once

#include <iostream>
#include <string>
#include <map>
using namespace std;
class numbers {
public:
    numbers() {
    }
    ~numbers() {
    }

    int toDeci(string const& input) {
        int sum = 0;
        for (int i = 0; i < input.length(); i++) {
            auto a = romanNums.find(input[i]);
            auto b = romanNums.find(input[i + 1]);

            if (i == input.length() - 1) {
                sum += a->second;
                break;
            }
            if (a->second >= b->second) {
                sum += a->second;
            } else if (a->second * 10 < b->second) {
                cout << "NOT VALID INPUT" << endl;
                return 0;
            } else {
                sum -= a->second;
            }
        }
        return sum;
    }

    string toRoman(int& input) {
        int length = 0;
        string result = "";
        for (auto& entry : romanNums) {
            length = input / entry.second;
            cout << "LENGTH: " << length << " ENTRY: " << entry.second << endl;
            result += string(length, entry.first);
            input %= entry.second;
        }
        return result;
    }
private:
    const map<char, int> romanNums = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
    };
};