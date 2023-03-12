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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {return a -> val > b -> val;};
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for (auto list: lists){
            if (list) pq.push(list);
        }
        
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while (!pq.empty()){
            auto curr = pq.top(); pq.pop();
            tail -> next = curr;
            tail = tail -> next;
            if (curr -> next) pq.push(curr -> next);
        }
        
        return dummy -> next;
    }
};