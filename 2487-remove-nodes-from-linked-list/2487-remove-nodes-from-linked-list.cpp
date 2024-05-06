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
    ListNode* reverseList(ListNode* head){
        ListNode *prev = nullptr, *curr = head, *nextTemp = nullptr;
        
        // set each node's next pointer to the previous node
        while (curr){
            nextTemp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        return prev;
    }
    
public:
    ListNode* removeNodes(ListNode* head) {
        // Reverse the original linked list
        head = reverseList(head);
        int mx = 0;
        ListNode *curr = head, *prev = nullptr, *deleted = nullptr;
        
        // Traverse the list deleting nodes
        while (curr){
            mx = max(mx, curr -> val);
            // delete current by skipping
            if (curr -> val < mx){
                prev -> next = curr -> next;
                deleted = curr;
                curr = curr -> next;
                deleted -> next = nullptr;
            }
            // curr doesn't need to be deleted
            else{
                prev = curr;
                curr = curr -> next;
            }
            
        }
        
        // Reverse and return the modified linked list
        return reverseList(head);
    }
};