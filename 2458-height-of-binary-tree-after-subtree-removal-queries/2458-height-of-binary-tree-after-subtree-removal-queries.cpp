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
    int n = 1e5;
    
    // Depth-First search to calculate node depths and subtree heights
    int dfs(TreeNode* node, int level, vector<int>& nodeDepths, vector<int>& subtreeHeights, vector<int>& firstLargestHeight, vector<int>& secondLargestHeight){
        if (!node) return 0;
        
        nodeDepths[node -> val] = level;
        
        // Calculate the height of the current subtree
        int leftHeight = dfs(node -> left, level + 1, nodeDepths, subtreeHeights, firstLargestHeight, secondLargestHeight);
        int rightHeight = dfs(node -> right, level + 1, nodeDepths, subtreeHeights, firstLargestHeight, secondLargestHeight);
        int currentHeight = 1 + max(leftHeight, rightHeight);
        
        subtreeHeights[node -> val] = currentHeight;
        
        // Update the largest and second largest heights at the current level
        if (currentHeight > firstLargestHeight[level]){
            secondLargestHeight[level] = firstLargestHeight[level];
            firstLargestHeight[level] = currentHeight;
        }
        else if (currentHeight > secondLargestHeight[level])
            secondLargestHeight[level] = currentHeight;
        
        return currentHeight;
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Vectors to store node depths and heights
        vector<int> nodeDepths(n + 1), subtreeHeights(n + 1);
        
        // Vectors to store the first and second largest heights at each level
        vector<int> firstLargestHeight(n + 1), secondLargestHeight(n + 1);
        
        // Perform DFS to calculate depths and heights
        dfs(root, 0, nodeDepths, subtreeHeights, firstLargestHeight, secondLargestHeight);
        int qSize = queries.size();
        vector<int> ans;
        ans.reserve(qSize);
        
        // Process each query
        for (int i = 0; i < qSize; ++i){
            int queryNode = queries[i];
            int nodeLevel = nodeDepths[queryNode];
            
            // Calculate the height of the tree after removing the query node
            if (subtreeHeights[queryNode] == firstLargestHeight[nodeLevel])
                ans.push_back(nodeLevel + secondLargestHeight[nodeLevel] - 1);
            else
                ans.push_back(nodeLevel + firstLargestHeight[nodeLevel] - 1);
        }
        
        return ans;
    }
};