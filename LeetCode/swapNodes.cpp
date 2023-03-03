#include <vector>
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head){
    ListNode *trace = head;
    while (trace != nullptr){
        cout << trace->val << ", ";
        trace = trace->next;
    }
    cout << endl;
}

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    
    // Swap the first two nodes in the list, then pass secondNode->next as the head of a linked list to be swapped
    ListNode *trace = head;
    head = trace->next;
    ListNode *temp = head->next;
    head->next = trace;
    trace->next = swapPairs(temp);
    return head;
}

int main(){
    ListNode* head = new ListNode();
    ListNode* trace = head;
    int limit = 11;
    for (int i = 1; i < limit; i++){
        trace->val = i;
        if (i != limit - 1){
            trace->next = new ListNode();
            trace = trace->next;
        }
    }
    printList(head);
    ListNode* newHead = swapPairs(head);
    printList(newHead);

}