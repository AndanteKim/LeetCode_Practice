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
    ListNode* removeNodes(ListNode* head) {
        // Base case, reached end of the list
        if (!(head && head -> next)) return head;
        
        // Recursive call
        ListNode* nextNode = removeNodes(head -> next);
        
        // If the next node has greater value head, delete the head
        // return the next node, which removes the current head and
        // makes next the new head
        if (head -> val < nextNode -> val)
            return nextNode;
        
        // Keep the head
        head -> next = nextNode;
        return head;
    }
};