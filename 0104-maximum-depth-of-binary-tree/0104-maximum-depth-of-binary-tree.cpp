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
    queue<pair<TreeNode*, int>> next_items;
    int max_depth = 0;
    
    int next_maxDepth(){
        if (next_items.size() == 0) return max_depth;
        
        auto next_item = next_items.front();
        next_items.pop();
        
        auto next_node = next_item.first;
        auto next_level = next_item.second + 1;
        
        max_depth = max(max_depth, next_level);
        
        if (next_node -> left != NULL) next_items.push(make_pair(next_node -> left, next_level));
        if (next_node -> right != NULL) next_items.push(make_pair(next_node -> right, next_level));
        return next_maxDepth();
    }
    
    public:
        int maxDepth(TreeNode* root) {
            if (root == NULL) return 0;
            
            queue<pair<TreeNode*, int>> empty;
            //swap(next_items, empty);
            max_depth = 0;
            
            next_items.push(make_pair(root, 0));
            return next_maxDepth();
        }
};