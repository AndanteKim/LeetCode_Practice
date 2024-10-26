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
    // Function to calculate the height of the tree
    int height(TreeNode* node, unordered_map<TreeNode*, int>& heightCache){
        if (!node) return -1;
        
        // Return cached height if already calculated
        if (heightCache.count(node))
            return heightCache[node];
        
        heightCache[node] = 1 + max(height(node -> left, heightCache), height(node -> right, heightCache));
        return heightCache[node];
    }
    
    // DFS to precompute the maximum values after removing the subtree
    void dfs(TreeNode* node, int depth, int maxVal, unordered_map<int, int>& resultMap, unordered_map<TreeNode*, int>& heightCache){
        if (!node) return;
        
        resultMap[node -> val] = maxVal;
        
        // Traverse left and right subtrees while updating max values
        dfs(node -> left, depth + 1, max(maxVal, depth + 1 + height(node -> right, heightCache)), resultMap, heightCache);
        dfs(node -> right, depth + 1, max(maxVal, depth + 1 + height(node -> left, heightCache)), resultMap, heightCache);
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<TreeNode*, int> heightCache;
        unordered_map<int, int> resultMap;
        
        // Run DFS to fill resultMap with maximum heights after each query
        dfs(root, 0, 0, resultMap, heightCache);
        
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i)
            ans[i] = resultMap[queries[i]];
        
        return ans;
    }
};