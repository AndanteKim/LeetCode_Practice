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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1, *curr2 = l2;
        int digit = 0, carry = 0;
        ListNode *curr = new ListNode();
        ListNode *ans = curr;
        
        // Two pointer
        while (curr1 || curr2){
            // If both curr1 and curr2 are not nullptr
            if (curr1 && curr2){
                digit = (curr1 -> val + curr2 -> val + carry) % 10;
                carry = (curr1 -> val + curr2 -> val + carry) / 10;
            }
            // If only curr1 is not nullptr
            else if (curr1){
                digit = (curr1 -> val + carry) % 10;
                carry = (curr1 -> val + carry) / 10;
            }
            // If only curr2 is not nullptr
            else{
                digit = (curr2 -> val + carry) % 10;
                carry = (curr2 -> val + carry) / 10;
            }
            
            curr -> val = digit;
            if (curr1) curr1 = curr1 -> next;
            if (curr2) curr2 = curr2 -> next;
            if (curr1 || curr2){
                curr -> next = new ListNode();
                curr = curr -> next;
            }
        }
        
        // If carry still remains
        if (carry){
            curr -> next = new ListNode(carry);
        }
        
        return ans;
    }
};