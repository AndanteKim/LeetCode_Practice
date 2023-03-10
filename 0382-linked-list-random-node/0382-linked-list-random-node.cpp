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
    ListNode* mHead;
public:
    Solution(ListNode* head) {
        mHead = head;
    }
    
    int getRandom() {
        ListNode* curr = mHead;
        int scope = 1, chosen_value = 0;
        
        while (curr != nullptr){
            if (rand() % scope == 0) chosen_value = curr -> val;
            ++scope;
            curr = curr -> next;
        }
        return chosen_value;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */