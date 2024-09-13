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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        
        while (head){
            ListNode* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        
        return prev;
    }
    
public:
    ListNode* plusOne(ListNode* head) {
        // Use reversed linked list to flip the digits easily by in-place method.
        head = reverseLL(head);
        
        // Plus one in advance and set root pointer
        int carry = 1;
        ListNode* root = head;
        
        // Compute the digit plus one with carry
        while (root){
            int temp = (root -> val + carry) % 10;
            carry = (root -> val + carry) / 10;
            root -> val = temp;
            
            // If the root reaches at the end of root and carry is larger than 0, create a new linked list.
            if (!(root -> next) && carry){
                root -> next = new ListNode(carry);
                break;
            }
            root = root -> next;
        }
        
        // Revert the original head and return it.
        return reverseLL(head);
    }
};