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
        ListNode *sentinel = new ListNode();
        ListNode *curr = sentinel;
        int carry = 0;
        
        while (l1 || l2 || carry != 0){
            int l1Val = (l1)? l1 -> val : 0, l2Val = (l2)? l2 -> val : 0;
            int total = (l1Val + l2Val + carry) % 10;
            carry = (l1Val + l2Val + carry) / 10;
            
            curr -> next = new ListNode(total);
            curr = curr -> next;
            
            (l1)? l1 = l1 -> next : l1 = nullptr;
            (l2)? l2 = l2 -> next : l2 = nullptr;
            
        }
        
        return sentinel -> next;
    }
};