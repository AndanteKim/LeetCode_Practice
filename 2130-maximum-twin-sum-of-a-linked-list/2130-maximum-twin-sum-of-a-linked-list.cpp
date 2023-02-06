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
        int length = 0;
        ListNode* root = head;
        
        while (root != nullptr) {
            ++length;
            root = root -> next;
        }
        
        ListNode* rev = nullptr, * curr = head;
        int i = 0;
        
        while (i < length / 2){
            curr = curr -> next;
            ++i;
        }
        
        while (i < length){
            ListNode* next_node = curr -> next;
            curr -> next = rev;
            rev = curr;
            curr = next_node;
            ++i;
        }
        
        int ans = 0, current = 0;
        ListNode* slow = head;
        i = 0;
        while (i < length / 2){
            current = slow -> val + rev -> val;
            ans = max(ans, current);
            slow = slow -> next;
            rev = rev -> next;
            ++i;
        }
        
        return ans;
    }
};