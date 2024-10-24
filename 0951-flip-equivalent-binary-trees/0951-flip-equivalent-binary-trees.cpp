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
    void bfs(TreeNode* root, unordered_map<int, unordered_set<int>>& match){
        if (!root) return;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()){
            TreeNode* node = queue.front(); queue.pop();
            match[node -> val] = {};
            if (node -> left){
                match[node -> val].insert(node -> left -> val);
                queue.push(node -> left);
            }
            
            if (node -> right){
                match[node -> val].insert(node -> right -> val);
                queue.push(node -> right);
            }
        }
        
    }
    
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        unordered_map<int, unordered_set<int>> match1, match2;
        bfs(root1, match1);
        bfs(root2, match2);
        
        return match1 == match2;
    }
};