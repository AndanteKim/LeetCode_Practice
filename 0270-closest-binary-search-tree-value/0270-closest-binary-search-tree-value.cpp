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
    void dfs(TreeNode* node, vector<int>& values, double target){
        if (!node) return;
        dfs(node -> left, values, target);
        values.push_back(node -> val);
        dfs(node -> right, values, target);
    }
    
public:
    int closestValue(TreeNode* root, double target) {
        vector<int> values;
        dfs(root, values, target);
        
        return *min_element(values.begin(), values.end(), \
                            [&target](int x, int y) {return abs(x - target) < abs(y - target);});
    }
};