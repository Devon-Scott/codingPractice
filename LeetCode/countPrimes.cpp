#include <iostream>
#include <vector>

int countPrimes(int n){
    if (n < 3){
        return 0;
    }
    std::vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;

    std::vector<int> prime;
    std::vector<int> spf(n);

    for (int i = 2; i < n; i++){
        if (isPrime[i]){
            prime.push_back(i);
            spf[i] = i;
        }
        
        for (int j = 0; j < (int)prime.size() && i * prime[j] < n && prime[j] <= spf[i]; j++){
            isPrime[i * prime[j]] = false;
            spf[i * prime[j]] = prime[j];
        }
    }

    return prime.size();
}

int badPrimes(int n) {
    if (n < 3){
        return 0;
    }
    std::vector<bool> isPrime(n, true);
    int primes = n;
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i < n; i++){
        if (isPrime.at(i)){
            for (int j = i * i; j < n; j += i){
                if (isPrime.at(j)){
                    primes--;
                }
                isPrime.at(j) = false;
            }
        }
        
    }
    return std::max(primes - 2, 0);
}

int main(){
    std::cout << badPrimes(10) << std::endl;
}