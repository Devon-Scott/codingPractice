/*
2.2 Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list. 
*/

/*
defines:
struct Node<T>
assignDataToList(std::vector<T> data)
printLinkedList(Node<T>* head)
*/
#include "linkedUtility.h"

/* 
 * Helper recursive function that uses a reference to index and returnValue
 * Operates in 0(n) time and O(n) space due to being a recursive call
 * Time complexity:
 * The only loop is a recursive loop, and it touches every item at most twice:
 * Once when traversing to the end of the list and adding calls to the stack
 * Once again when it comes back, discarding calls from the stack and incrementing index
 * So technically O(2n)
 * I would like a way of returning the whole thing as soon as a value is found
 * without needing to discard each call from the stack one by one 
 */
template <typename T>
void findKthToLast(const int k, Node<T>* head, int& index, T& returnValue){
	if (head->next == nullptr){
		if (k == index){
			returnValue = head->value;
			index++;
			return;
		} else {
			index++;
			return;
		}
	}
	findKthToLast(k, head->next, index, returnValue);
	if (k == index){
		returnValue = head->value;
		index++;
		return;
	} else {
		index++;
		return;
	}
}

template <typename T>
T findKthToLast(const int k, Node<T>* head){
    if (k <= 0){
        throw "can't return past the end";
    }
    Node<T>* iterator = head;
    int index = 1;
	T returnValue;
    findKthToLast(k, iterator, index, returnValue);
	return returnValue;
}

int main(){
	std::vector<std::string> words = {"cat", "cat", "dog", "snake", "kitten", "cat", "bird", "mouse", "lizard", "fish", "rat", "cat", "dog", "cat", "kitten", "mouse", "kitten", "monkey", "monkey"};
	std::vector<std::string> test = {"word", "word", "other"};
	Node<std::string>* head = assignDataToList(words);
	
	for (int i = 1; i < words.size(); i++){
		std::cout << findKthToLast(i, head) << std::endl;
	}
}
