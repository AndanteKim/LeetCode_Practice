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
    bool dfs(TreeNode* currT, ListNode* currL){
        // Base case: If the current node reached the end, and it's the subpath of current subtree
        if (!currL)
            return true;
        
        // Base case: If it's not the subpath
        if ((!currT && currL) || (currT -> val != currL -> val))
            return false;
        
        bool left = dfs(currT -> left, currL -> next);
        bool right = dfs(currT -> right, currL -> next);
        return left || right;
    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()){
            TreeNode* currTree = queue.front(); queue.pop();
            
            if (currTree -> val == head -> val){
                bool isSubpath = dfs(currTree, head);
                if (isSubpath)
                    return true;
            }
            
            if (currTree -> left)
                queue.push(currTree -> left);
            
            if (currTree -> right)
                queue.push(currTree -> right);
        }
        
        return false;
    }
};