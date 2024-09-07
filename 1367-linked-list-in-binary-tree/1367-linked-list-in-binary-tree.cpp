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
private:
    bool dfs(ListNode* head, TreeNode* node){
        if (!head)
            return true;
        
        if (!node || (node -> val != head -> val))
            return false;
        
        // Continue searching in both left and right subtrees
        return dfs(head -> next, node -> left) || dfs(head -> next, node -> right);
    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root)
            return false;
        
        // Check the current node and all its descendants
        bool main = dfs(head, root);
        
        // Check all paths from the left and right children of the root
        bool left = isSubPath(head, root -> left), right = isSubPath(head, root -> right);
        
        return main || left || right;
    }
};