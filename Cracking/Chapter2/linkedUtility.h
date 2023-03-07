#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

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

// Gives a 10% chance to return any node except the first
// or last node in a linked list
template <typename T>
Node<T>* getRandomNode(Node<T>* head){
    Node<T>* iterator = head->next;

	while (true){
		if (iterator->next == nullptr){
			iterator = head->next;
		} else if (rand() % 10 == 0){
			return iterator;
		} else {
			iterator = iterator->next;
		}
	}
}

/*
Since the Partition exercise, I learned that passing a pointer by reference
is how to best apply operations on the head of the actual list
Otherwise a copy of the pointer remains in the calling function, and it's
not properly set to nullptr
*/ 
template <typename T>
void deleteListIterative(Node<T>* &head){
	while (head != nullptr){
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
}

template <typename T>
void deleteListRecursive(Node<T>* &head){
	if (head->next != nullptr){
		deleteListRecursive(head->next);
	}
	delete head;
	head = nullptr;
}