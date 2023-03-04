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

template <typename T>
T findKthToLast(const int k, Node<T>* head, int& index){
    if (head->next != nullptr){
        return findKthToLast(k, head->next, index);
    }
    index++;
    std::cout << index << " " << k << std::endl;
    if (index == k){
        return head->value;
    }
}

template <typename T>
T findKthToLast(const int k, Node<T>* head){
    if (k <= 0){
        throw "can't return past the end";
    }
    Node<T>* iterator = head;
    int index = 0;
    return findKthToLast(k, iterator, index);
}

int main(){
	std::vector<std::string> words = {"cat", "cat", "dog", "snake", "kitten", "cat", "bird", "mouse", "lizard", "fish", "rat", "cat", "dog", "cat", "kitten", "mouse", "kitten", "monkey", "monkey"};
	std::vector<std::string> test = {"word", "word", "other"};
	Node<std::string>* head = assignDataToList(words);
	
    std::cout << findKthToLast(2, head) << std::endl;
}