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
        stack<int> s1, s2;
        
        while (l1){
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        
        while (l2){
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        
        int digit = 0, carry = 0;
        stack<int> l;
        
        while (!s1.empty() || !s2.empty()){
            int v1 = 0, v2 = 0;
            if (!s1.empty()){
                v1 = s1.top();
                s1.pop();
            }
            if (!s2.empty()){
                v2 = s2.top();
                s2.pop();
            }
            if (carry){
                digit = (v1 + v2 + carry) % 10;
                carry = (v1 + v2 + carry) / 10;
            }
            else{
                digit = (v1 + v2) % 10;
                carry = (v1 + v2) / 10;
            }
            
            l.push(digit);
        }
        if (carry) l.push(carry);
        ListNode *root = new ListNode(), *sentinel = new ListNode();
        sentinel -> next = root;
        
        while(!l.empty()){
            root -> val = l.top();
            l.pop();
            if (!l.empty()){
                root -> next = new ListNode();
                root = root -> next;
            }
        }
        
        return sentinel -> next;
    }
};