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
        // Base case: If head or next pointer of head is nullptr
        if (!(head && head -> next))
            return head;
        
        // Find the length of head
        int n = 0;
        ListNode *curr = head;
        while (curr){
            ++n;
            curr = curr -> next;
        }
        
        // To shorten rotation and avoid repetition, we'll apply k % n
        k %= n;
        ListNode *prev;
        
        // Rotate the linked list until k is running out
        while (k-- > 0){
            curr = head;
            
            // Check the end of linked list and its previous pointer.
            while (curr -> next){
                prev = curr;
                curr = curr -> next;
            }
            
            // switch pointer for each previous node and the end of node
            prev -> next = nullptr;
            curr -> next = head;
            
            // reset the pointer of head
            head = curr;
        }
        
        return head;
    }
};