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
    ListNode* removeNodes(ListNode* head) {
        ListNode *curr = head;
        stack<ListNode*> stack;
        
        // Add nodes to the stack
        while (curr){
            stack.push(curr);
            curr = curr -> next;
        }
        
        ListNode* ans = new ListNode(stack.top() -> val), *newNode;
        int max = stack.top() -> val;
        stack.pop();
        
        // Remove nodes from the stack and add to ans
        while (!stack.empty()){
            ListNode *curr = stack.top();
            stack.pop();
            // curr should not be added to the ans
            if (curr -> val < max){
                continue;
            }
            // Add new node with curr's value to front of ans
            else{
                newNode = new ListNode(curr -> val);
                newNode -> next = ans;
                ans = newNode;
                max = newNode -> val;
            }
            
        }
        
        return ans;
    }
};