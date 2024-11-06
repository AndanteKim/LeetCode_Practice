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
    // Depth-First Search to build the Euler tour and store node information
    void dfs(TreeNode* node, int height, vector<int>& eulerTour, unordered_map<int, int>& nodeHeights, unordered_map<int, int>& firstOccurrence, unordered_map<int, int>& lastOccurrence){
        if (!node) return;
        
        nodeHeights[node -> val] = height;
        firstOccurrence[node -> val] = eulerTour.size();
        eulerTour.push_back(node -> val);
        
        dfs(node -> left, height + 1, eulerTour, nodeHeights, firstOccurrence, lastOccurrence);
        dfs(node -> right, height + 1, eulerTour, nodeHeights, firstOccurrence, lastOccurrence);
        
        lastOccurrence[node -> val] = eulerTour.size();
        eulerTour.push_back(node -> val);
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Vectors and maps to store tree information
        vector<int> eulerTour;
        unordered_map<int, int> nodeHeights, firstOccurrence, lastOccurrence;
        
        // Perform DFS to build Euler tour and node information
        dfs(root, 0, eulerTour, nodeHeights, firstOccurrence, lastOccurrence);
        
        int tourSize = eulerTour.size();
        vector<int> maxDepthLeft(tourSize, 0), maxDepthRight(tourSize, 0);
        
        // Initialize the first and last elements of max height arrays
        maxDepthLeft[0] = maxDepthRight.back() = nodeHeights[root -> val];
        
        // Build maxDepthLeft and maxDepthRight arrays
        for (int i = 1; i < tourSize; ++i){
            maxDepthLeft[i] = max(maxDepthLeft[i - 1], nodeHeights[eulerTour[i]]);
        }
        
        for (int i = tourSize - 2; i >= 0; --i){
            maxDepthRight[i] = max(maxDepthRight[i + 1], nodeHeights[eulerTour[i]]);
        }
        
        // Process queries
        int querySize = queries.size();
        vector<int> ans(querySize);
        
        for (int i = 0; i < querySize; ++i){
            int query = queries[i];
            int leftMax = (maxDepthLeft[firstOccurrence[query]] > 0)? maxDepthLeft[firstOccurrence[query] - 1]: 0;
            int rightMax = (maxDepthRight[lastOccurrence[query]] < tourSize - 1)? maxDepthRight[lastOccurrence[query] + 1] : 0;
            ans[i] = max(leftMax, rightMax);
        }
        
        return ans;
    }
};