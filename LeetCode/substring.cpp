#include <iostream>

int lengthOfLongestSubstring(std::string s) {
    int start = 0, end = 0, longest = 0;
    while (end < s.length()){
        std::cout << "start is: " << s[start] << "(" << start << ") end is: " << s[end] << "(" << end << ")" << std::endl;
        if (s[end] == s[start]){
            if (start == end){
                end++;
            } else {
                start++;
                end++;
            }
        } else if (end > 0) {
            for (int i = start; i < end; i++){
                    if (s[i] == s[end]){
                        start = i + 1;
                    }
                }
            if (s[end] == s[end-1]){
                start = end;
            } else {
                end++;
            }
        }
        if (end - start > longest){
            longest = end - start;
        }
        std::cout << longest << std::endl;
    }
    return longest;
}

int main(){
    std::string a = "dvdf";
    std::string b = "aab";
    std::string c = "aabbcdeeff";
    std::string d = "abcabcbb";
    int subOfA = lengthOfLongestSubstring(a);
    int subOfB = lengthOfLongestSubstring(b);
    int subOfC = lengthOfLongestSubstring(c);
    int subOfD = lengthOfLongestSubstring(d);
    std::cout << a << " is " << subOfA << std::endl;
    std::cout << b << " is " << subOfB << std::endl;
    std::cout << c << " is " << subOfC << std::endl;
    std::cout << d << " is " << subOfD << std::endl;
    std::cout << lengthOfLongestSubstring("ohvhjdml") << std::endl;
}