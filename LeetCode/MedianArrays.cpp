#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*long long sum = 0;
    auto nums1Iter = nums1.begin();
    auto nums2Iter = nums2.begin();
    while (nums1Iter != nums1.end()){
        sum += *nums1Iter;
        nums1Iter++;
    }
    while (nums2Iter != nums2.end()){
        sum += *nums2Iter;
        nums2Iter++;
    }
    double result = sum / (double)(nums1.size() + nums2.size());
    return result;*/

    auto num1FIt = nums1.begin();
    auto num2FIt = nums2.begin();
    auto num1RIt = nums1.rbegin();
    auto num2RIt = nums2.rbegin();

    while (true){
        int num1Forward = *num1FIt;
        int num2Forward = *num2FIt;
        int num1Reverse = *num1RIt;
        int num2Reverse = *num2RIt;
        std::cout << num1Forward << " " << num1Reverse << " " << num2Forward << " " << num2Reverse << std::endl;
        if (*num1FIt < *num2FIt && *num1FIt < *num1RIt){
            num1FIt++;
        } else if (*num2FIt < *num1FIt && *num2FIt < *num2RIt){
            num2FIt++;
        } else if (*num1RIt > *num2RIt && *num1RIt > *num1FIt){
            num1RIt++;
        } else if (*num2RIt > *num1RIt && *num2RIt > *num2FIt){
            num2RIt++;
        } else {
            break;
        }
    }
    return (double)((*num1FIt + *num2RIt) / 2);
}

int main(){
    vector<int> l1 = {1,3};
    vector<int> l2 = {2,7};
    vector<int> l3 = {1, 2, 4, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

    cout << findMedianSortedArrays(l1, l2) << endl;
}