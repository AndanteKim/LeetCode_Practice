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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* root = head;
        int n = 0;
        while (root) {
            ++n;
            root = root -> next;
        }
        ListNode* frontNode = head, *endNode = head;
        for (int i = 0; i <= k - 2; ++i) frontNode = frontNode -> next;
        for (int i = 0; i <= n - k - 1; ++i) endNode = endNode -> next;
        swap(frontNode -> val, endNode -> val);
        return head;
    }
};