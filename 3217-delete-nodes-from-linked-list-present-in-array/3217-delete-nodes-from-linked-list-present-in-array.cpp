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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Set candidates and link the root's head
        unordered_set<int> candidates(nums.begin(), nums.end());
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        curr -> next = head;
        
        while (curr){
            // Delete nodes if the next val is in candidates.
            while (curr -> next && candidates.count(curr -> next -> val))
                curr -> next = curr -> next -> next;
            
            curr = curr -> next;
        }
        
        return dummy -> next;
    }
};