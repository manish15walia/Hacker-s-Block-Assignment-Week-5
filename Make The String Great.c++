#include <iostream>
#include <string>

using namespace std;

string makeGood(string s) {
    string gdstr = "";
    for (char c : s) {
        if (!gdstr.empty() && abs(gdstr.back() - c) == 32) {
            gdstr.pop_back();
        } else {
            gdstr.push_back(c);
        }
    }
    return gdstr;
}

int main() {
    string s;
  
    cin >> s;
    string gdstr = makeGood(s);
    cout << gdstr << endl;
    return 0;
}
