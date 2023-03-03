#include <iostream>
#include <vector>
#include <q
using namespace std;

void merge(vector<int> &A, int left, int mid, int right){
  
}

void mergeSort(vector<int> &A, int low, int high){
  int mid = (low + high) / 2
  if (low >= high){
    return
  }
  mergeSort(A, low, mid);
  mergeSort(A, mid + 1, high);
  merge(A, left, mid, right);
}

int solution(vector<int> &A){
  // Given an array A with an odd number of elements, find the element
  // that does not have a pair to go with it 
  
  // sort the array
  // push int to priority queue 
  // if pq.pop is not the same, return the first element 
  
  // Something like this is nlog(n)
  // sorting can be 
}
