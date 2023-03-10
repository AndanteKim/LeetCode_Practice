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
    ListNode *_head;
public:
    Solution(ListNode* head) : _head(head) {
        
    }
    
    int getRandom() {
        int res = 0, i = 1;
        for(ListNode* h = _head; h; h = h->next, ++i){
            if (rand() % i == 0) res = h -> val;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */