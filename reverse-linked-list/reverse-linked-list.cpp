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
    ListNode* reverseList(ListNode* head) {
        // Base case
        if (not (head && head -> next)) return head;
        
        // Create its reverse list sequentially move to the next step
        ListNode* prev = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        
        return prev;
    }
};