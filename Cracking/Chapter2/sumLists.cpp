/*
2.5 Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
Output: 2 -> 1 -> 9. That is, 912.
FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
Output: 9 - > 1 -> 2. That is, 912.
*/

#include "linkedUtility.h"


int getValueForSum(Node<int>* node){
    if(node != nullptr){
        return node->value;
    } else {
        return 0;
    }
}

Node<int>* sumListsReverse(Node<int>* firstSummand, Node<int>* secondSummand){
    Node<int>* sum = nullptr;
    Node<int>* sumIter = sum;
    Node<int>* firstIter = firstSummand; 
    Node<int>* secondIter = secondSummand; 

    int firstVal, secondVal, iterSum, nodeValue;
    bool carryOne = false;

    // Must return true if at least one is not nullptr
    // means that inner brackets must return false if at least one is not nullptr
    // means that must return true if both are nullptr
    while (!(firstIter == nullptr && secondIter == nullptr)){
        firstVal = getValueForSum(firstIter);
        if (firstIter != nullptr){
            firstIter = firstIter->next;
        }
        secondVal = getValueForSum(secondIter);
        if (secondIter != nullptr){
            secondIter = secondIter->next;
        }
        iterSum = firstVal + secondVal + carryOne;

        if (iterSum >= 10){
            carryOne = true;
            nodeValue = iterSum % 10;
        } else {
            carryOne = false;
            nodeValue = iterSum;
        }

        if (sum == nullptr){
            sum = new Node<int>(nodeValue);
            sumIter = sum;
        } else {
            sumIter->next = new Node<int>(nodeValue);
            sumIter = sumIter->next;
        }
    }

    if (carryOne){
        nodeValue = carryOne;
        sumIter->next = new Node<int>(nodeValue);
        sumIter = sumIter->next;
    }
    return sum;
}

int main(){
    std::vector<int> first = {7, 1, 6, 3};
    std::vector<int> second = {5, 9, 7};
    std::vector<int> third = {9, 9, 9, 9, 9, 9, 9};
    Node<int>* firstSummand = assignDataToList(first);
    Node<int>* secondSummand = assignDataToList(second);
    Node<int>* thirdSummand = assignDataToList(third);
    Node<int>* sum = sumListsReverse(firstSummand, secondSummand);
    printLinkedList(sum);

    Node<int>* secondSum = sumListsReverse(sum, thirdSummand);
    printLinkedList(secondSum);

}