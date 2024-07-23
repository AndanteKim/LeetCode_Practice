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
    TreeNode* dfs(int val, unordered_map<int, vector<pair<int, int>>>& parentsToChildren){
        // Create new TreeNode for current value
        TreeNode* node = new TreeNode(val);
        
        // If current node has children, recursively build them.
        for (auto& [child, isLeft] : parentsToChildren[val]){
            
            // Attach child node based on isLeft flag
            if (isLeft)
                node -> left = dfs(child, parentsToChildren);
            else
                node -> right = dfs(child, parentsToChildren);
        }
        
        return node;
    }
    
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Step 1: Organize data
        unordered_set<int> allNodes, children;
        unordered_map<int, vector<pair<int, int>>> parentsToChildren;
        
        for (vector<int>& d : descriptions){
            int parent = d[0], child = d[1], isLeft = d[2];
            allNodes.insert(parent);
            allNodes.insert(child);
            children.insert(child);
            parentsToChildren[parent].push_back({child, isLeft});
        }
        
        // Step 2: Find the root
        int rootVal = 0;
        for (int node : allNodes){
            if (!children.contains(node)){
                rootVal = node;
                break;
            }
        }
        
        // Step 3 & 4: Build the tree using DFS
        return dfs(rootVal, parentsToChildren);
    }
};