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
private:
    ListNode* reverseLL(ListNode* head, int k){
        // Reverse k nodes of the given linked list.
        // This function assumes that the list contains
        // at least k nodes.
        ListNode* prev = nullptr, *ptr = head;
        
        // Decrement the count of nodes to be reversed by 1.
        while (k-- > 0){
            // Keep track of the next node to process in the
            // original list
            ListNode* nextNode = ptr -> next;
            
            // Insert the node pointed to by "ptr"
            // at the beginning of the reversed list
            ptr -> next = prev;
            prev = ptr;
            
            // Move on to the next node
            ptr = nextNode;
        }
        
        // Return the head of the reversed list
        return prev;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* ptr = head;
        
        // First, see if there are at least k nodes
        // left in the linked list.
        while (ptr && count < k){
            ++count;
            ptr = ptr -> next;
        }
        
        // If we have k nodes, then we reverse them.
        if (count == k){
            
            // Reverse the first k nodes of the list and
            // get the reversed list's head.
            ListNode* reverseHead = reverseLL(head, k);
            
            // Now, recurse on the remaaining linked list. Since
            // our recursion returns the head of the overall processed
            // list, we use that and the "original" head of the "k" nodes
            // to re-wire the connections.
            head -> next = reverseKGroup(ptr, k);
            return reverseHead;
        }
        
        return head;
    }
};