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
    ListNode* rotateRight(ListNode* head, int k) {
        // Base case
        if (!(head && head -> next))
            return head;
        
        // close the linked list into the ring
        ListNode* oldTail = head;
        int n = 1;
        while (oldTail -> next){
            ++n;
            oldTail = oldTail -> next;
        }
        oldTail -> next = head;
        
        // Find the new tail: (n - k % n - 1)th node
        // and new head: (n - k % n)th node
        ListNode* newTail = head;
        for (int i = 0; i < n - k % n - 1; ++i)
            newTail = newTail -> next;
        
        ListNode* newHead = newTail -> next;
        
        // Break the ring
        newTail -> next = nullptr;
        
        return newHead;
    }
};