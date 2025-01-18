/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
#include <iostream>
class Solution {

    
public:
    ListNode* recursiveCounter(ListNode* head, int n, int& counter){
        if (head->next == nullptr){
            counter++;
            if (counter == n){
                return nullptr;
            }
            return head;
        }
        
        head->next = recursiveCounter(head->next, n, counter);
        counter++;
        if (counter == n){
            return head->next;
        }
        else {
            return head;
        }
        
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter = 0;
        ListNode* tracker;
        tracker = recursiveCounter(head, n, counter);
        return tracker;
    }
};
// @lc code=end

