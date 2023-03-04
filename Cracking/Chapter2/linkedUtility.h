#include <iostream>
#include <vector>

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