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
    TreeNode* findLowestLCA(TreeNode* root, int v1, int v2){
        if (!root) return nullptr;
        
        if (root -> val == v1 || root -> val == v2) return root;
        
        TreeNode* left = findLowestLCA(root -> left, v1, v2);
        TreeNode* right = findLowestLCA(root -> right, v1, v2);
        
        // If there exists both left and right, then return the lowest ancestor
        if (left && right) return root;
        
        return left? left : right;
    }
    
    bool findPath(TreeNode* node, int target, string& path){
        if (!node) return false;
        
        if (node -> val == target)
            return true;
        
        // Try left subtree
        path.push_back('L');
        bool left = findPath(node -> left, target, path);
        
        if (left) return true;
        path.pop_back(); // Remove the last character
        
        // Try right subtree
        path.push_back('R');
        bool right = findPath(node -> right, target, path);
        
        if (right) return true;
        path.pop_back(); // Remove the last character
        
        return false;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Find the Lowest Common Ancestor (LCA) of start and destination nodes
        TreeNode* lca = findLowestLCA(root, startValue, destValue);
        string pathToStart, pathToDest;
        
        // Find paths from LCA to start and destination nodes
        findPath(lca, startValue, pathToStart);
        findPath(lca, destValue, pathToDest);
        string ans = "";
        
        // Add "U" for each step to go up from start to LCA
        ans.append(pathToStart.size(), 'U');
        
        // Append the path from LCA to destination
        ans.append(pathToDest);
        
        return ans;
    }
};