#include <iostream>
#include <set>
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
Node<T>* deleteDuplicateNodes(Node<T>* head, T val){
	Node<T>* n = head;
	//std::cout << n->value << " compared to " << val << std::endl;
	/*if (n->value == val){
		//std::cout << "deleting " << n->value << std::endl;
		Node<T>* temp = n;
		n = n->next;
		delete temp;
		return n;
	}*/
	while (n->next != nullptr){
		if (n->value == val){
			n->next = deleteNode(n);
		}
		if (n->next != nullptr){
			n = n->next;
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
	std::set<T> tempBuffer;
	Node<T>* iterator = head;
	Node<T>* nextIterator = head->next;
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

int main(){
	std::string words[] = {"cat", "cat", "dog", "snake", "kitten", "cat", "bird", "mouse", "lizard", "fish", "rat", "cat", "dog", "cat", "kitten", "kitten"};
	std::string test[] = {"word", "word"};
	Node<std::string>* head = new Node<std::string>(words[0]);
	Node<std::string>* iterator = head;
	for (int i = 1; i < 16; i++){
		iterator->next = new Node<std::string>(words[i]);
		iterator = iterator->next;
	}
	printLinkedList(head);
	removeDups(head);
	printLinkedList(head);
}

