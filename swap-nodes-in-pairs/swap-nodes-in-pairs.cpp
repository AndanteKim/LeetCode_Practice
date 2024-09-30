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
        if (!(head && head -> next)) return head;
        
        // Nodes to be swapped
        ListNode* first = head, *second = head -> next;
        
        // swapping
        first -> next = swapPairs(second -> next);
        second -> next = first;
        
        // Now, the head is the second
        return second;
    }
};