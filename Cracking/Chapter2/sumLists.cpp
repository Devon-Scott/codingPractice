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

// Takes a linked list where the inputs are stored in reverse order
// eg. 617 is stored as 7 -> 1 -> 6
Node<int>* sumListsReverse(Node<int>* firstSummand, Node<int>* second){
	// Need to delve to the end of the list, possibly through recursion,
	// to get the value of the ones place
	// Then add them together
	// But what if the integers are of different lengths?
	Node<int>* result;
	Node<int>* resultIter = result;
		
	bool carry = false;
	bool first = true;
	Node<int>* firstIter = firstSummand;
	Node<int>* secondIter = second;

	while (firstIter != nullptr && secondIter != nullptr){
		if (!first){
			resultIter->next = new Node<int>;
			resultIter = resultIter->next;
		}
		carry = false;
		int value = firstIter->value + secondIter->value;
		if (value >= 10){
			value -= 10;
			carry = true;
		}
		resultIter->value = value;
	}	
}
