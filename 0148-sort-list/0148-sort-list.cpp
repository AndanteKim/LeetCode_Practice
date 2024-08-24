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
    ListNode* sortList(ListNode* head) {
        ListNode* root = head;
        vector<int> flatten;
        ListNode* dummy = new ListNode(), *curr = dummy;
        
        while (root){
            flatten.push_back(root -> val);
            root = root -> next;
        }
        
        sort(flatten.begin(), flatten.end());
        for (int n : flatten){
            curr -> next = new ListNode(n);
            curr = curr -> next;
        }
        
        return dummy -> next;
    }
};