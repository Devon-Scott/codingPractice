#include <iostream>
#include <cmath>
using namespace std;

// 2147483648
// 1463847412

int reverse(int x){
    int reverse = 0, sample = x;
    while (x != 0){
        int unitValue = x % 10;
        if (reverse <= INT32_MAX / 10.0 && reverse >= INT32_MIN / 10.0){
            reverse *= 10;
        } else {
            reverse = 0;
            break;
        }
        reverse += unitValue;
        x /= 10;
    }
    return reverse;
}

int main(){
    cout << "Input: ";
    int x;
    cin >> x;
    cout << "Output: " << reverse(x) << endl;
}