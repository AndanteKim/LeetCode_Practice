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
    ListNode* mergeNodes(ListNode* head) {
        // dummy node
        ListNode* sentinel = new ListNode();
        sentinel -> next = head;
        
        ListNode* prev = sentinel, *root = head;
        int curr = 0;
        
        while (root){
            if (root -> val == 0 && curr > 0){
                root -> val = curr;
                curr = 0;
                prev -> next = root;
                prev = root;
            }
            else
                curr += root -> val;
            root = root -> next;
        }
        
        return sentinel -> next;
    }
};