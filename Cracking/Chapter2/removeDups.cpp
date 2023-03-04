#include <iostream>
#include <vector>
#include <string>

template <typename T>
struct Node{
	T value;
	Node* next;
	Node(T &item){
		value = item;
		next = nullptr;
	}
};

template <typename T>
void printLinkedList(Node<T>* head){
	Node<T>* iter = head;
	while (iter != nullptr){
		std::cout << iter->value << " ";
		iter = iter->next;
	}
	std::cout << std::endl;
}

/*
Time complexity: Constant
*/
template<typename T>
Node<T>* deleteNode(Node<T>* head){
	Node<T>* n = head;
	Node<T>* temp = n;
	n = n->next;
	delete temp;
	return n;
}

/*
Time complexity: Linear
Runs through a linked list and removes all the values
equal to the head of the list
*/
template<typename T>
void deleteDuplicateNodes(Node<T>* head){
	Node<T>* iterator = head;
	T duplicateValue = head->value;
	while (iterator->next != nullptr){
		if (iterator->next->value == duplicateValue){
			iterator->next = deleteNode(iterator->next);
			// Realized that I was returning a nullptr, then needed to break because
			// that would mean we reached the end of the list
			if (iterator->next == nullptr){
				break;
			}
		}
		if (iterator != nullptr){
			iterator = iterator->next;
		}
	}
}

/*
Time Complexity:
One iterator that runs through the length of the list: O(n)
On every element, calls a function that itself has an iterator 
that runs through the rest of the list: O(n)
Linear function that calls a linear function on every element: O(n^2)
Space Complexity:
No extra data structures, just a couple extra pointers, so O(1)
*/ 
template <typename T>
void removeDups(Node<T>* head){
	Node<T>* iterator = head;
	// What count as a duplicate? Two pointers to the same item,
	// or two items that share equality?
	// Assume two items that share equality, otherwise it would be described as circular
	while (iterator != nullptr){
		deleteDuplicateNodes(iterator);
		iterator = iterator->next;
	}
}

template <typename T>
Node<T>* assignDataToList(std::vector<T> data){
	Node<T>* head = new Node<T>(data[0]);
	Node<T>* iterator = head;
	for (int i = 1; i < data.size(); i++){
		iterator->next = new Node<T>(data[i]);
		iterator = iterator->next;
	}
	return head;
}

int main(){
	std::vector<std::string> words = {"cat", "cat", "dog", "snake", "kitten", "cat", "bird", "mouse", "lizard", "fish", "rat", "cat", "dog", "cat", "kitten", "mouse", "kitten", "monkey", "monkey"};
	std::vector<std::string> test = {"word", "word", "other"};
	Node<std::string>* head = assignDataToList(words);
	
	printLinkedList(head);
	// I'm cutting the list off at the point where I delete. I should be assigning 
	// something like head = head->next->next
	removeDups(head);
	printLinkedList(head);
}

