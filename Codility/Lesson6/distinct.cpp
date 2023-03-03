#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    std::set<int> result;
    for (int n : A){
        result.emplace(n);
    }
    return (result.size());
}

int main(){

}