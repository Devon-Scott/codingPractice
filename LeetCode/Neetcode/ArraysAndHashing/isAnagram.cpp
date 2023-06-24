#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define FIRST               0b10000000
#define SECOND              0b01000000
#define THIRD               0b00100000
#define FOURTH              0b00010000

#define ONE_BYTE_MASK       0b01111111
#define TWO_BYTE_MASK       0b00011111
#define THREE_BYTE_MASK     0b00001111
#define FOUR_BYTE_MASK      0b00000111
#define CONT_BYTE_MASK      0b00111111

void enque_string(string& s, priority_queue<int>& queue);

bool isAnagram(string s, string t) {
    // Check if equal length, if not, return false
    int length = s.length();
    if (length != t.length()){
        return false;
    }

    // Set up data structure for easy comparison
    priority_queue<int> s_queue;
    priority_queue<int> t_queue;

    // Read the strings in
    enque_string(s, s_queue);
    enque_string(t, t_queue);
    
    while (!s_queue.empty()){
        int s_char = s_queue.top();
        int t_char = t_queue.top();
        if (s_char != t_char){
            return false;
        }
        s_queue.pop();
        t_queue.pop();
    }
    return true;

}

void enque_string(string& s, priority_queue<int>& queue){
    int i = 0;
    while(i < s.length()){
        // Decode the character
        int bytes;
        char sample = s[i];
        int bitmasks[5] = {ONE_BYTE_MASK, TWO_BYTE_MASK, THREE_BYTE_MASK, FOUR_BYTE_MASK, CONT_BYTE_MASK};
        // Assume sample is a starting byte of a character and find number bytes
        
        int byte_representation = 0;
        // Perform a bitmask equality check based on UTF-8 standards
        if ((sample & FIRST) == 0){
            // All other bit representations start with 1, so this must be ASCII
            bytes = 1;
        }
        else if ((sample & (FIRST | SECOND | THIRD)) == (FIRST | SECOND)){
            bytes = 2;
        }
        else if ((sample & (FIRST | SECOND | THIRD | FOURTH)) == (FIRST | SECOND | THIRD)){
            bytes = 3;
        }
        else {
            bytes = 4;
        }
        
        // Working forwards from the first byte of the character
        // Figure out which bit mask we need to get rid of identifier bits
        // Then byte_representation will contain a concatination of the data bits
        for (int j = 0; j < bytes; j++){
            int char_sample = s[i + j];
            int mask;
            if (j == 0){
                mask = bitmasks[bytes - 1];
            }
            else {
                mask = CONT_BYTE_MASK;
                byte_representation = byte_representation << 6;
            }
            byte_representation += (char_sample & mask);
        }
        i += bytes;
        // Place its integer representation into the queue
        queue.emplace(byte_representation);
    }
}

int main(){
    string s = "anagram";
    string t = "nagaram";
    std::cout << isAnagram(s, t) << std::endl;
}