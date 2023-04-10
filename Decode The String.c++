#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string s) {
    stack<int> numStack;
    stack<string> strStack;
    string currentString = "";
    int num = 0;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '[') {
            numStack.push(num);
            strStack.push(currentString);
            num = 0;
            currentString = "";
        } else if (c == ']') {
            int repeatTimes = numStack.top();
            numStack.pop();
            string repeatedString = "";
            for (int i = 0; i < repeatTimes; i++) {
                repeatedString += currentString;
            }
            currentString = strStack.top() + repeatedString;
            strStack.pop();
        } else {
            currentString += c;
        }
    }
    return currentString;
}

int main() {
    string encodedString;
  
    cin >> encodedString;
    string decodedString = decodeString(encodedString);
    cout <<decodedString << endl;
    return 0;
}
