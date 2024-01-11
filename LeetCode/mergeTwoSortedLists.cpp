
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* result = nullptr;
    ListNode* iterator;
    bool first = true;
    while (list1 != nullptr && list2 != nullptr){
        if (first){
            if (list1->val < list2->val){
                result = list1;
                list1 = list1->next;
            }
            else {
                result = list2;
                list2 = list2->next;
            }
            iterator = result;
        }
        else {
            if (list1->val < list2->val){
                iterator->next = list1;
                list1 = list1->next;
            }
            else {
                iterator->next = list2;
                list2 = list2->next;
            }
            iterator = iterator->next;
        }
    }
    while (list1 != nullptr){
        iterator->next = list1;
        list1 = list1->next;
        iterator = iterator->next;
    }
    while (list2 != nullptr){
        iterator->next = list2;
        list2 = list2->next;
        iterator = iterator->next;
    }
    return result;
}
