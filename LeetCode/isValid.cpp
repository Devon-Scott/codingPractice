#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
    int n = s.length();
    stack<int> recent;
    for (int i = 0; i < n; i++){
        switch(s[i]){
            case '(':
            recent.push(0); break;
            case ')':
            if (recent.size() && recent.top() == 0){
                recent.pop(); break;
            }
            else {
                return false;
            }

            case '{':
            recent.push(1); break;
            case '}':
            if (recent.size() && recent.top() == 1){
                recent.pop(); break;
            }
            else {
                return false;
            }

            case '[':
            recent.push(2); break;
            case ']':
            if (recent.size() && recent.top() == 2){
                recent.pop(); break;
            }
            else {
                return false;
            }
        }
    }
    return (recent.empty());
}

int main(){
    vector<string> tests = {"{{[[]]}}", "[{]}", "]", "(){}[]"};
    for (string s: tests){
        std::cout << isValid(s) << std::endl;
    }
}