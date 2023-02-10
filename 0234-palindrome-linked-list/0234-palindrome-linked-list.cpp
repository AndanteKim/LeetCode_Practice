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
    bool isPalindrome(ListNode* head) {
        ListNode *current_node = head;
        vector<int> vals, rev_vals;
        
        while (current_node != nullptr){
            vals.push_back(current_node -> val);
            rev_vals.push_back(current_node -> val);
            current_node = current_node -> next;
        }
        
        reverse(rev_vals.begin(), rev_vals.end());
        return rev_vals == vals;
    }
};