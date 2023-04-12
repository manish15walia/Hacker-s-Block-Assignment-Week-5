#include <iostream>
using namespace std;

bool isHappy(int n) {
    for (int i = 0; i < 20; i++) {  // limit the number of iterations to prevent infinite loops
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        if (sum == 1) {
            return true;
        }
        n = sum;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    if (isHappy(n)) {
        cout<<"true";
    } else {
        cout<<"false";
    }

    return 0;
}
