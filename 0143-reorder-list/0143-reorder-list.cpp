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
class Solution {
public:
    void reorderList(ListNode* head) {
        // Iterative combo: Find middle point, reversed Linked List(LL), two sorted LL
        ListNode *slow = head, *fast = head;
        
        // Find middle point
        while (fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // reverse the second part of the list
        ListNode *prev = nullptr;
        while (slow){
            ListNode *temp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = temp;
        }
        
        // merge two sorted LL
        ListNode *first = head, *second = prev;
        while (second -> next){
            ListNode *temp = first -> next;
            first -> next = second;
            first = temp;
            
            temp = second -> next;
            second -> next = first;
            second = temp;
        }
    }
};