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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = new ListNode(-1), *sentinel = curr;
        curr -> next = head;
        
        while (curr != nullptr && curr -> next != nullptr){
            while(curr -> next != nullptr && val == curr -> next -> val){
                curr -> next = curr -> next -> next;
            }
            curr = curr -> next;
        }
        
        return sentinel -> next;
    }
};