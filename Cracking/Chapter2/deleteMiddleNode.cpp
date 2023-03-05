/*
2.3 Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
that node.
EXAMPLE
lnput:the node c from the linked lista->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a->b->d->e- >f
*/

#include "linkedUtility.h"
#include <cmath>
#include <ctime>

// node must be dereferenced to access the actual variable of node, even
// though node itself is a pointer
template <typename T>
void deleteMiddleNode(Node<T>* node){
	Node<T>* temp = node;
	*node = *(node->next);
	delete temp;
}

// Might include this in an update to linkedUtility.h
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

int main(){
	srand(time(0));
    std::vector<std::string> words = {"cat", "cat", "dog", "snake", "kitten", "cat", "bird", "mouse", "lizard", "fish", "rat", "cat", "dog", "cat", "kitten", "mouse", "kitten", "monkey", "monkey"};
	std::vector<std::string> test = {"word", "word", "other"};
	Node<std::string>* head = assignDataToList(words);

    printLinkedList(head);
    Node<std::string>* node = getRandomNode(head);
	std::cout << node->value << std::endl;
	deleteMiddleNode(node);
    printLinkedList(head);
}
