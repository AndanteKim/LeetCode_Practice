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
    ListNode* rec(ListNode* node, int val){
        if (node != nullptr){
            if (node -> val == val) return rec(node -> next, val);
            else{
                node -> next = rec(node -> next, val);
            }
        }
        return node;
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        return rec(head, val);
    }
};