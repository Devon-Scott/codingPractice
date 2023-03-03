#include <iostream>
#include <vector>
#include <string>
using namespace std;

string makeDomino(int x, int y){
    return string(to_string(x) + "-" + to_string(y));
}

void increment(int& x, int& y){
    if (y == 6){
        x++;
        y = 0;
    } else {
        y++;
    }
}

string solution(vector<string> &A) {
    int x = 0, y = 0;
    bool contains = true;
    string forwards, backwards;
    while (contains){
        contains = false;
        forwards = makeDomino(x, y);
        backwards = makeDomino(y, x);
        for (int i = 0; i < A.size(); i++){
            if (forwards == A[i] || backwards == A[i]){
                contains = true;
                break;
            }
        }
        if (contains){
            increment(x, y);
        } else {
            return forwards;
        }
    }
    return forwards;
}

int main(){
    vector<string> one = {"0-0", "0-1", "0-2", "0-3", "0-4", "0-5", "0-6"};
    vector<string> two = {"0-0", "1-1", "2-2", "3-3", "4-4", "5-5", "6-6"};
    std::cout << solution(one) << std::endl;
}