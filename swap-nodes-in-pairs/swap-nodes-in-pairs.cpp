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
    ListNode* swapPairs(ListNode* head) {
        // Recursive
        // Base case
        if (!head) return nullptr;
        if (!head -> next) return head;
        
        // Save 2 nodes(next and double next node)
        ListNode* nextNode = head -> next;
        ListNode* temp = nextNode -> next;
        
        // turn the direction
        head -> next = swapPairs(temp);
        nextNode -> next = head;
        return nextNode;
    }
};