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
        ListNode* node = head;
        deque<ListNode*> dq;
        
        while (node){
            while (!dq.empty() && node -> val > dq.back() -> val)
                dq.pop_back();
            dq.push_back(node);
            node = node -> next;
        }
        
        ListNode* sentinel = new ListNode();
        sentinel -> next = dq.front();
        while (dq.size() > 1){
            dq.front() -> next = dq[1];
            dq.pop_front();
        }
        
        return sentinel -> next;
    }
};