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
    ListNode* doubleIt(ListNode* head) {
        stack<int> stack;
        ListNode *node = head;
        
        while (node){
            stack.push(node -> val);
            node = node -> next;
        }
        
        vector<int> doubled;
        int carry = 0;
        
        while (!stack.empty()){
            int val = stack.top();
            stack.pop();
            val = 2 * val + carry;
            carry = val / 10;
            int digit = val % 10;
            doubled.push_back(digit);
        }
        
        if (carry > 0) doubled.push_back(carry);
        
        ListNode *sentinel = new ListNode(), *curr = sentinel;
        while (!doubled.empty()){
            curr -> next = new ListNode(doubled.back());
            doubled.pop_back();
            curr = curr -> next;
        }
        
        return sentinel -> next;
    }
};