#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solutionTwo(vector<int> &A, vector<int> &B) {
    // Implement your solution here

    // Road goes from A[i] to B[i]
    int cities = A.size();
    int roads = 0;
    
    // This feels recursive, traverse nodes to check direction
    // Make an actual tree and check how many parent nodes 0 has
    // Then check how many parent/root nodes each city has that aren't 0
    // Goal is to make 0 the root of the whole tree, figure out how many edges need to be reversed to make that happen
}


void iterateArray(vector<int> &A, int size){
    if (size == 0){
        return;
    }
    if (A[size - 1] == 6){
        A[size - 1] == 1;
        iterateArray(A, size - 1);
    } else {
        A[size - 1]++;
    }
}

bool equal(int sum, int target){
    return sum == target;
}
vector<int> solutionOne(vector<int> &A, int F, int M) {
    // Implement your solution here
    // Given an array of known dice rolls A, and a number of forgotten dice rolls F, find the possible
    // values of the forgotten dice rolls to equal the given mean M of all the dice rolls
    vector<int> impossibleResult = {0};
    
    // Find current average of known rolls
    int sum = 0;
    for (int n : A){
        if ((M == 6 && n != 6) || (M == 1 && n != 1)){
            return impossibleResult;
        }
        sum += n;
        
    }

    // What if we just brute forced it
    sum = 0;
    int nums = A.size() + F;
    vector<int> forgot(F);
    for (int i = 0; i < F; i++){
        forgot[i] = 1;
    }
    bool allSix = false;
    while (!equal(sum / nums, M)){
        sum = 0;
        bool allSix = true;
        for (int n : A){
            sum += n;
        }
        for (int f : forgot){
            if (f != 6){
                allSix = false;
            }
            sum += f;
        }

        if (equal(sum / nums, M)){
            return forgot;
        }

        if (allSix){
            return impossibleResult;
        }
        iterateArray(forgot, F);
    }
    return impossibleResult;


}



int solutionThree(vector<int> &A) {
    // Implement your solution here
    if (A.size() < 2){
        return 0;
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> first(A.begin(), A.end());
    int sum = first.top();
    first.pop();
    sum += first.top();
    first.pop();
    while (!first.empty()){
        // Time it took all the previous lists to be merged
        int oldTime = sum;
        
        // Time it takes to merge the current merged list with the next largest list
        int time = oldTime + first.top();
        first.pop();

        // Total time to merge all lists so far;
        sum = time + oldTime;
    }
    return sum;
}
int main(){
    vector<int> list = {1, 5, 6};
    vector<int> sample = solutionOne(list, 4, 3);
    for (int n : sample){
        cout << n << ", ";
    }

    
}