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
        ListNode *curr = head;
        
        while (curr != nullptr){
            ++length;
            curr = curr -> next;
        }
        
        ListNode * rev = nullptr;
        curr = head;
        int i = 0;
        
        while (i < length / 2){
            curr = curr -> next;
            ++i;
        }
        
        ListNode *next_node;
        while (i < length){
            next_node = curr -> next;
            curr -> next = rev;
            rev = curr;
            curr = next_node;
            ++i;
        }
        
        i = 0;
        int ans = 0;
        ListNode* slow = head;
        while (i < length / 2){
            int curr_val = slow -> val + rev -> val;
            ans = max(ans, curr_val);
            slow = slow -> next;
            rev = rev -> next;
            ++i;
        }
        
        return ans;
    }
};