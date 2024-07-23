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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Maps values to TreeNode pointers
        unordered_map<int, TreeNode*> nodeToMap;
        
        // Store values which are children in the descriptions
        unordered_set<int> children;
        
        // Iterate through descriptions to create nodes and set up tree structure
        for (vector<int>& d : descriptions){
            // Extract parent value, child value, and whether it's a 
            // left child (1) or right child (0)
            int parent = d[0], child = d[1], isLeft = d[2];
            
            // Create parent and child nodes if not already created
            if (!nodeToMap.contains(parent))
                nodeToMap[parent] = new TreeNode(parent);
            if (!nodeToMap.contains(child))
                nodeToMap[child] = new TreeNode(child);
            
            // Attach child node to parent's left or right branch
            if (isLeft)
                nodeToMap[parent] -> left = nodeToMap[child];
            else
                nodeToMap[parent] -> right = nodeToMap[child];
            
            // Mark child as a child in the set
            children.insert(child);
        }
        
        // Find and return the root node
        for (auto& [_, node] : nodeToMap){
            // Root node found
            if (!children.contains(node -> val))
                return node;
        }
        
        // Should not occur according to problem statement
        return nullptr;
    }
};