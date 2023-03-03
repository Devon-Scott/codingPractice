#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solution(int A, int B, int K){
    if ((K > B && A != 0) || (A == B && A % K != 0)){
        return 0;
    }
    int divisors = 0, i = A;
    for (i; i <= B; i++){
        if (i % K == 0){
            divisors++;
            break;
        }
    }
    divisors += (B - i) / K;
    return divisors;
}

int main(){
    cout << 0 % 11 << endl;
    //cout << solution(6, 11, 2) << endl;
    cout << solution(0, 1, 11) << endl;
    // 1073741824
    //cout << solution(0, INT_MAX, 2) << endl;
}