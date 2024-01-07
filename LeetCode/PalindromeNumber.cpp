#include <iostream>
#include <assert.h>
#include <cmath>

using namespace std;

/*
    Lesson learned from solution
    Modulus is unnecessary, can simply create a reversed
    integer from the input and compare equality
    My modulus/power instructions were more costly than the
    simpler arithmetic to create a reversed integer
*/

bool isPalindrome(int x) {
    if (x < 0){
        return false;
    }        
    if (x < 10){
        return true;
    }
    int length = (int)log10(x) + 1;
    int mask = 10;
    while (length > 1){
        std::cout << "Number = " << x << " Length = " << length << std::endl;
        int highest = (x / (pow(10, length - 1)));
        int lowest = x % 10;
        if (highest != lowest){
            std::cout << highest << ' ' << lowest << std::endl;
            return false;
        }
        x = x % (int)(pow(10, length - 1));
        x = x / 10;
        length = length - 2;
    }
    return true;
}

int main(){
    int tests[] = {121, -121, 10, 1221, 1234, 1234321, 12344321};
    bool results[] = {true, false, false, true, false, true, true};
    for (int i = 0; i < 7; i++){
        bool result = isPalindrome(tests[i]);
        std::cout << result << std::endl;
    }
}