/*
2.3 Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
that node.
EXAMPLE
lnput:the node c from the linked lista->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a->b->d->e- >f
*/

#include "linkedUtility.h"

template <typename T>
void deleteMiddleNode(Node<T>* node){

}

template <typename T>
Node<T>* getRandomNode(Node<T>* head){
    Node<T>* iterator = head;
}

int main(){
    std::vector<std::string> words = {"cat", "cat", "dog", "snake", "kitten", "cat", "bird", "mouse", "lizard", "fish", "rat", "cat", "dog", "cat", "kitten", "mouse", "kitten", "monkey", "monkey"};
	std::vector<std::string> test = {"word", "word", "other"};
	Node<std::string>* head = assignDataToList(words);

    printLinkedList(head);
    Node<std::string>* node = getRandomNode(head);
    deleteMiddleNode(node);
    printLinkedList(head);
}
