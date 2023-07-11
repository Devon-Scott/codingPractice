#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string makePalindrome(string z){
    string x;
    bool odd = z.length() % 2 != 0;
    for (int i = z.length() - 1 - odd; i >= 0; i--){
        x += z[i];
    }
    return x;
}

int main(){
    string a, b;
    std::cin >> a >> b;
    string ax = makePalindrome(a);
    string bx = makePalindrome(b);
    if (bx.length() == ax.length()){
        if (strcmp(ax.c_str(), bx.c_str()) == 0){
            std::cout << "No solution." << std::endl;
            return 0;
        }
        if (strcmp(ax.c_str(), bx.c_str()) < 0){
            std::cout << ax << std::endl;
        }
        else {
            std::cout << bx << std::endl;
        }
    } else if (bx.length() < a.length()){
        std::cout << bx << std::endl;
    } else {
        std::cout << ax << std::endl;
    }
    return 0;
}