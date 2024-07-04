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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *sentinel = new ListNode();
        sentinel -> next = head;
        ListNode *curr = head, *prev = sentinel;
        stack<ListNode*> stk;
        
        while (curr){
            if (stk.size() == k){
                prev -> next = stk.top();
                ListNode* nextNode = stk.top() -> next, *node;
                while (stk.size() > 1){
                    node = stk.top(); stk.pop();
                    node -> next = stk.top();
                }
                
                node = stk.top(); stk.pop();
                prev = node;
                node -> next = nextNode;
            }
            
            stk.push(curr);
            curr = curr -> next;
        }
        
        if (stk.size() == k){
            prev -> next = stk.top();
            ListNode *nextNode = stk.top() -> next, *node;
            while (stk.size() > 1){
                node = stk.top(), stk.pop();
                node -> next = stk.top();
            }
            
            node = stk.top(); stk.pop();
            prev = node;
            node -> next = nextNode;
        }
        
        return sentinel -> next;
    }
};