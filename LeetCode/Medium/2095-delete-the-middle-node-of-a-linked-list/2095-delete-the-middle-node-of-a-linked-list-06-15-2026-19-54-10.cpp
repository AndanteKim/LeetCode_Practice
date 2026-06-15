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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* curr = head;
        int n = 0;

        while (curr) {
            ++n;
            curr = curr -> next;
        }

        if (n <= 1) return nullptr;

        int mid = n >> 1;
        curr = head;
        for (int i = 0; i < mid - 1; ++i) curr = curr -> next;

        curr -> next = curr -> next -> next;

        return head;
    }
};