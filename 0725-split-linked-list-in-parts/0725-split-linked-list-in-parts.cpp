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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int n = 0;
        
        while (curr){
            ++n;
            curr = curr -> next;
        }
        
        int width = n / k, rem = n % k;
        curr = head;
        vector<ListNode*> ans(k);
        for (int i = 0; i < k; ++i){
            ListNode* root = new ListNode(), * write = root;
            for (int j = 0; j < width + (i < rem ? 1 : 0); ++j){
                write = write -> next = new ListNode(curr -> val);
                if (curr) curr = curr -> next;
            }
            ans[i] = root -> next;
        }
        
        return ans;
    }
};