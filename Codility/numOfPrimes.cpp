#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if (n == 2){
        return true;
    }
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int countPrimesLessThan(int n){
    int numOfPrimes = 0;
    for (int i = 2; i < n; i++){
        if (isPrime(i)){
            cout << i << endl;
            numOfPrimes++;
        }
    }
    return numOfPrimes;
}

int main(){
    std::cout << countPrimesLessThan(190) << std::endl;
}