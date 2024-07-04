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
    ListNode* mergeNodes(ListNode* head) {
        // Start with the first non-zero value
        head = head -> next;
        if (!head)
            return head;
        
        // Initialize a dummy head node.
        ListNode* temp = head;
        int sum = 0;
        while (temp -> val != 0){
            sum += temp -> val;
            temp = temp -> next;
        }
        
        // Store the sum in head's value.
        head -> val = sum;
        
        // Store head's next node as the recursive result for temp node.
        head -> next = mergeNodes(temp);
        
        return head;
    }
};