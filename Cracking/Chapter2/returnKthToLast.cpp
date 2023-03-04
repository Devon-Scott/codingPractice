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

int main(){
	std::vector<std::string> words = {"cat", "cat", "dog", "snake", "kitten", "cat", "bird", "mouse", "lizard", "fish", "rat", "cat", "dog", "cat", "kitten", "mouse", "kitten", "monkey", "monkey"};
	std::vector<std::string> test = {"word", "word", "other"};
	Node<std::string>* head = assignDataToList(words);
	
	printLinkedList(head);
	// I'm cutting the list off at the point where I delete. I should be assigning 
	// something like head = head->next->next
	printLinkedList(head);
}