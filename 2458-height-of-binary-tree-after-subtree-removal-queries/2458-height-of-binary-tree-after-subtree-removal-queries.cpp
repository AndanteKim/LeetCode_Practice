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
    // Depth-first search to populate nodeIndexMap and nodeDepths
    void dfs(TreeNode* node, int depth, unordered_map<int, int>& nodeIndexMap, vector<int>& nodeDepths){
        if (!node) return;
        
        nodeIndexMap[node -> val] = nodeDepths.size();
        nodeDepths.push_back(depth);
        dfs(node -> left, depth + 1, nodeIndexMap, nodeDepths);
        dfs(node -> right, depth + 1, nodeIndexMap, nodeDepths);
    }
    
    // Calculate the size of the subtree for each node
    int calculateSubtreeSize(TreeNode* node, unordered_map<int, int>& subtreeSize){
        if (!node) return 0;
        
        int leftSize = calculateSubtreeSize(node -> left, subtreeSize);
        int rightSize = calculateSubtreeSize(node -> right, subtreeSize);
        int totalSize = leftSize + rightSize + 1;
        subtreeSize[node -> val] = totalSize;
        return totalSize;
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Map to store the index of each node value and
        // the number of nodes in the subtree for each node
        unordered_map<int, int> nodeIndexMap, subtreeSize;
        
        // Vectors to store node depths and maximum depths from left and right
        vector<int> nodeDepths, maxDepthFromLeft, maxDepthFromRight;
        
        // Perform DFS to populate nodeIndexMap and nodeDepths
        dfs(root, 0, nodeIndexMap, nodeDepths);
        
        int totalNodes = nodeDepths.size();
        
        // Calculate subtree sizes
        calculateSubtreeSize(root, subtreeSize);
        
        // Calculate maximum depths from left and right
        maxDepthFromLeft.push_back(nodeDepths[0]);
        maxDepthFromRight.push_back(nodeDepths.back());
        
        for (int i = 1; i < totalNodes; ++i){
            maxDepthFromLeft.push_back(max(maxDepthFromLeft[i - 1], nodeDepths[i]));
            maxDepthFromRight.push_back(max(maxDepthFromRight[i - 1], nodeDepths[totalNodes - i - 1]));
        }
        
        reverse(maxDepthFromRight.begin(), maxDepthFromRight.end());
        
        // Process queries
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i){
            int queryNode = queries[i];
            int startIndex = nodeIndexMap[queryNode] - 1;
            int endIndex = startIndex + 1 + subtreeSize[queryNode];
                
            int maxDepth = maxDepthFromLeft[startIndex];
            if (endIndex < totalNodes)
                maxDepth = max(maxDepth, maxDepthFromRight[endIndex]);
            ans[i] = maxDepth;
        }
        
        return ans;
    }
};