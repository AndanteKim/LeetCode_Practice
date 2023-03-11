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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    ListNode* findMiddle(ListNode* head){
        ListNode* prevPtr = NULL;
        ListNode* slowPtr = head, *fastPtr = head;
        
        while (fastPtr && fastPtr -> next){
            prevPtr = slowPtr;
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next;
        }
        
        if (prevPtr) prevPtr -> next = NULL;
        
        return slowPtr;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        
        ListNode* mid = findMiddle(head);
        
        TreeNode* node = new TreeNode(mid -> val);
        if (head == mid) return node;
        
        node -> left = sortedListToBST(head);
        node -> right = sortedListToBST(mid -> next);
        return node;
    }
};