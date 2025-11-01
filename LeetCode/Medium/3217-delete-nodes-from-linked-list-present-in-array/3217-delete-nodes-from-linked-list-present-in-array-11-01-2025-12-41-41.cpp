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
        unordered_set<int> needDelete(nums.begin(), nums.end());
        ListNode* sentinel = new ListNode();
        sentinel -> next = head;
        ListNode* curr = sentinel;

        while (curr) {
            while (curr -> next && needDelete.count(curr -> next -> val)) {
                curr -> next = curr -> next -> next;
            }

            curr = curr -> next;
        }

        return sentinel -> next;
    }
};