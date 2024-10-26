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
    // Left to right traversal
    int currentMaxHeight = 0;
    vector<int> maxHeightAfterRemoval;
    void traversalLeftToRight(TreeNode* node, int currentHeight){
        if (!node) return;
        
        // Store the maximum height if this node were removed
        maxHeightAfterRemoval[node -> val] = currentMaxHeight;
        
        //Update the current maximum height
        currentMaxHeight = max(currentMaxHeight, currentHeight);
        
        // Traverse left subtree first, then right
        traversalLeftToRight(node -> left, currentHeight + 1);
        traversalLeftToRight(node -> right, currentHeight + 1);
    }
    
    // Right to left traversal
    void traversalRightToLeft(TreeNode* node, int currentHeight){
        if (!node) return;
        
        // Update the maximum height if this node were removed
        maxHeightAfterRemoval[node -> val] = max(maxHeightAfterRemoval[node -> val], currentMaxHeight);
        
        // Update the current maximum height
        currentMaxHeight = max(currentMaxHeight, currentHeight);

        //Update the current maximum height
        traversalRightToLeft(node -> right, currentHeight + 1);
        
        // Traverse right subtree first, then left
        traversalRightToLeft(node -> left, currentHeight + 1);
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Array to store the maximum height of the tree after removing each node
        vector<int> ans(queries.size());
        maxHeightAfterRemoval.resize(100'001);
        traversalLeftToRight(root, 0);
        currentMaxHeight = 0;    // Reset for the second traversal
        traversalRightToLeft(root, 0);
        
        // Process queries and build the result vector
        for (int i = 0; i < queries.size(); ++i){
            ans[i] = maxHeightAfterRemoval[queries[i]];
        }
        
        return ans;
    }
};