/*
2.4 Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions.
EXAMPLE
Input:
Output:
3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
*/

#include "linkedUtility.h"

/*
Thoughts:
Step 1: Check the head of the list
Step 2: Move that node to the appropriate iterator list
Step 3: Point head to the next node in the list
Step 4: Remove the pointer from the iterator to the head
Step 5: repeat from step 1

This should operate in O(n) time and O(1) space: 
Time complexity: one iteration through the list, with a constant 
number of steps at each element "touch"
Space complexity: Four pointers created to keep track of the start and end of each partition
Otherwise this happens in place, with just the pointers to each node shuffled around
*/
template <typename T>
void partition(T val, Node<T>* &head){
    Node<T>* leftIterator = nullptr;
    Node<T>* leftStart = nullptr;
    Node<T>* rightIterator = nullptr;
    Node<T>* rightStart = nullptr;
    
    while (head != nullptr){
        if (head->value < val){
            if (leftIterator != nullptr){
                leftIterator->next = head;
                head = head->next;
                leftIterator = leftIterator->next;
                leftIterator->next = nullptr;
            } else {
                leftIterator = head;
                leftStart = leftIterator;
                head = head->next;
                leftIterator->next = nullptr;
            }
        } else {
            if (rightIterator != nullptr){
                rightIterator->next = head;
                head = head->next;
                rightIterator = rightIterator->next;
                rightIterator->next = nullptr;
            } else {
                rightIterator = head;
                rightStart = rightIterator;
                head = head->next;
                rightIterator->next = nullptr;
            }
        }
        
    }
    // Head is now a nullptr so can't derefence it to reassign it, causes crashing
    // But passing head by reference seems to have fixed my problem
    if (leftIterator != nullptr){
        leftIterator->next = rightStart;
        head = leftStart;
    } else {
        head = rightStart;
    }
    
}

int main(){
    srand(time(0));
    std::vector<std::string> words = {"cat", "cat", "dog", "snake", "kitten", "cat", "bird", "mouse", "lizard", "fish", "rat", "cat", "dog", "cat", "kitten", "bird", "mouse", "kitten", "monkey", "monkey"};
	std::vector<std::string> test = {"word", "word", "other"};
	Node<std::string>* head = assignDataToList(words);

    printLinkedList(head);
    Node<std::string>* node = getRandomNode(head);
	std::cout << "string test: cat" << std::endl;
	partition(head->value, head);
    printLinkedList(head);

    int partitionVal = rand() % 100;
    std::cout << "nums test: " << partitionVal << std::endl;
    std::vector<int> testNums;
    for (int i = 0; i < 20; i++){
        testNums.push_back(rand() % 100);
    }
    Node<int>* intHead = assignDataToList(testNums);
    printLinkedList(intHead);
    partition(partitionVal, intHead);
    printLinkedList(intHead);

    deleteListIterative(head);
    deleteListRecursive(intHead);
    if (head == nullptr){
        std::cout << "deletion successful" << std::endl;
    }
    printLinkedList(head);
    printLinkedList(intHead);
}