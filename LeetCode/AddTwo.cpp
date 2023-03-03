#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head, *node, *temp;
    ListNode *t1 = l1, *t2 = l2;
    bool carriedOne = false;
    int loops = 0;

    while (t1 != nullptr && t2 != nullptr){
        int result = t1->val + t2->val;
        if (carriedOne){
            result++;
        }
        carriedOne = false;
        if (result >= 10){
            carriedOne = true;
            result = result - 10;
        }

        node = new ListNode(result);
        if (loops == 0){
            head = temp = node;
        } else {
            temp->next = node;
            temp = node;
        }
        loops++;
        t1 = t1->next;
        t2 = t2->next;
    }

    while (t1 != nullptr){
        int result = t1->val;
        if (carriedOne){
            result++;
        }
        carriedOne = false;
        if (result >= 10){
            carriedOne = true;
            result = result - 10;
        }
        node = new ListNode(result);
        temp->next = node;
        temp = node;
        t1 = t1->next;
    }

    while (t2 != nullptr){
        int result = t2->val;
        if (carriedOne){
            result++;
        }
        carriedOne = false;
        if (result >= 10){
            carriedOne = true;
            result = result - 10;
        }
        node = new ListNode(result);
        temp->next = node;
        temp = node;
        t2 = t2->next;
    }
    
    if (carriedOne){
        node = new ListNode(1);
        temp->next = node;
        temp = node;
    }

    return head;
}

void printNode(ListNode *l){
    while (l != nullptr){
        cout << l->val;
        l = l->next;
    }
    cout << endl;
}

int main(){
    ListNode *headOne, *list, *node;
    for (int i = 0; i < 4;i++){
        node = new ListNode();
        node->val = 9;
        if (i == 0){
            headOne = list = node;
        } else {
            list->next = node;
            list = node;
        }
    }

    ListNode *headTwo, *listTwo, *nodeTwo;
    for (int i = 0; i < 7; i++){
        nodeTwo = new ListNode();
        nodeTwo->val = 9;
        if (i == 0){
            headTwo = listTwo = nodeTwo;
        } else {
            listTwo->next = nodeTwo;
            listTwo = nodeTwo;
        }
    }
    printNode(headOne);
    printNode(headTwo);
    // Add function for printing linked list

    ListNode* p1 = addTwoNumbers(headOne, headTwo);
    printNode(p1);
    
}