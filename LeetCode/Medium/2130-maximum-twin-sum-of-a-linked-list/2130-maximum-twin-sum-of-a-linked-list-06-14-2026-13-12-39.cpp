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
    int pairSum(ListNode* head) {
        ListNode *curr = head;
        int n = 0;
        stack<ListNode*> st;

        while (curr) {
            st.push(curr);
            curr = curr -> next;
            ++n;
        }

        int ans = 0;
        curr = head;
        for (int i = 0; i < (n >> 1); ++i) {
            ListNode* rev = st.top(); st.pop();
            ans = max(ans, curr -> val + rev -> val);
            curr = curr -> next;
        }

        return ans;
    }
};