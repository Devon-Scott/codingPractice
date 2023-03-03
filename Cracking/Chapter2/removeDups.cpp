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

// Call DeleteNextNodes(head, val) which enters a loop 
// If head->value = val, call DeleteNode(head, val)
template<typename T>
Node<T>* deleteNode(Node<T>* head){
	Node<T>* n = head;
	Node<T>* temp = n;
	n = n->next;
	delete temp;
	return n;
}

template<typename T>
void deleteDuplicateNodes2(Node<T>* head){
	Node<T>* iterator = head;
	T duplicateValue = head->value;
	while (iterator->next != nullptr){
		if (iterator->next->value == duplicateValue){
			iterator->next = deleteNode(iterator->next);
		}
		if (iterator != nullptr){
			iterator = iterator->next;
		}
	}
}

template<typename T>
Node<T>* deleteDuplicateNodes(Node<T>* head, T val){
	Node<T>* iterator = head;
	while (iterator->next != nullptr){
		if (iterator->value == val){
			iterator = deleteNode(iterator);
		}
		if (iterator->next != nullptr){
			iterator = iterator->next;
		}
	}
	return head;
}

template <typename T>
void removeDups(Node<T>* head){
	// Brute force 0n^2
	// Need to touch every item in the list, put it in a set, then check if every 
	// future item is an element of that set
	// This also requires o(n) extra space for the set
	Node<T>* iterator = head;
	// What count as a duplicate? Two pointers to the same item,
	// or two items that share equality?
	// Assume two items that share equality, otherwise it would be described as circular
	while (iterator->next != nullptr){
		iterator->next = deleteDuplicateNodes(iterator->next, iterator->value);
		if (iterator->next != nullptr){
			iterator = iterator->next;
		}
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
	std::vector<std::string> words = {"cat", "cat", "dog", "snake", "kitten", "cat", "bird", "mouse", "lizard", "fish", "rat", "cat", "dog", "cat", "kitten", "kitten"};
	std::vector<std::string> test = {"word", "word", "other"};
	Node<std::string>* head = assignDataToList(test);
	
	printLinkedList(head);
	// I'm cutting the list off at the point where I delete. I should be assigning 
	// something like head = head->next->next
	deleteDuplicateNodes2(head);
	printLinkedList(head);
}

