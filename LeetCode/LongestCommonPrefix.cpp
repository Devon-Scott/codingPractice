#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

/*
    Lessons Learned:
    The conversion between cstr and string may be costly in terms of runtime
    My solution beat 35%. I compared it to a supposed 100% solution, and 
    that was the only significant difference. I chose to use a cstr because 
    I couldn't predict what the string concatenation behaviour would be like 
    in C++. I didn't want to wind up creating a whole new string on every
    concatenation operation.
*/

string longestCommonPrefix(vector<string>& strs) {
    std::sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size() - 1];
    int length = min(first.length(), last.length());
    char c_result[length + 1];
    memset(c_result, 0, length + 1);
    int index = 0;
    for (int i = 0; i < length; i++){
        if (first[i] == last[i]){
            c_result[index] = first[i];
            index++;
        }
        else {
            break;
        }
    }
    c_result[index + 1] = '\0';
    string result = string(c_result);
    return result;
}   

int main(){
    vector<string> test1 = {"flower", "flock", "flame", "fucking", "frat"};
    vector<string> test2 = {""};
    std::cout << longestCommonPrefix(test1) << std::endl;
    std::cout << longestCommonPrefix(test2) << std::endl;
}