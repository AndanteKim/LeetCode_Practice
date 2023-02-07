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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return nullptr;
        
        ListNode* curr = head, * prev = nullptr;
        while (left > 1){
            prev = curr;
            curr = curr -> next;
            --left;
            --right;
        }
        
        ListNode *tail = curr, *con = prev;
        
        while (right > 0){
            ListNode* third = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = third;
            --right;
        }
            
        if (con != nullptr) con -> next = prev;
        else head = prev;
        
        tail -> next = curr;
        
        return head;
    }
};