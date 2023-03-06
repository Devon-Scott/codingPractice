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