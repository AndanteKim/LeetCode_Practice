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
        // Base case
        if (!(head && head -> next)) return head;
        
        ListNode* sentinel = new ListNode(-1), *prevNode = sentinel;
        
        while (head && head -> next){
            // Nodes to be swapped
            ListNode* first = head, *second = head -> next;
            
            // Swapping
            first -> next = second -> next;
            second -> next = first;
            prevNode -> next = second;
            
            // Reinitialize the head and prevNode for next swap
            prevNode = first;
            head = first -> next;
        }
        
        // Return the new head node
        return sentinel -> next;
    }
};