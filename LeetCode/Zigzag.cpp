#include <iostream>
using namespace std;

void iterate(const int &max, int &row, int &col){
    static bool reverse;
    if (max == 1){
        col++;
        return;
    }
    if (row == max - 1){
        reverse = true;
    } else if (row == 0){
        reverse = false;
    }
    if (reverse){
        col++;
        row--;
    } else {
        row++;
    }

}

string convert(string s, int numRows) {
    int length = s.length();
    int segmentWidth = max(numRows - 1, 1); // Given numRows = 1, equals 2
    int charsInSegment = 2 * segmentWidth; // given numRows = 1, equals 2
    int numOfSegment = length / charsInSegment; // given "AB", equals 1
    int numOfAddCols = max(1, (length % charsInSegment) - numRows + 2); // given "AB" and numRows = 1, equals 1
    const int numCols = (segmentWidth * numOfSegment) + numOfAddCols; // equals 3
    
    char** array = new char*[numRows];
    for (int i = 0; i < numRows; i++){
        array[i] = new char[numCols];
    } // a 1 by 3 array
    std::cout << "array declared" << std::endl;

    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            array[i][j] = ' ';
        }
    }
    std::cout << "array filled with spaces" << std::endl;
    
    int row = 0, col = 0;
    for (int i = 0; i < length; i++){
        array[row][col] = s[i];
        iterate(numRows, row, col);
    }
    std::cout << "iterate done" << std::endl;
    
    std::string result;
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            if (array[i][j] != ' '){
                result += array[i][j];
            }
        }
        delete[] array[i];
        std::cout << "array " << i << " deleted" << std::endl;
    }
    delete[] array;
    return result;
}

int main(){
    string sample = "ABCD";
    int numRows = 1;
    cout << convert(sample, numRows) << endl;
}