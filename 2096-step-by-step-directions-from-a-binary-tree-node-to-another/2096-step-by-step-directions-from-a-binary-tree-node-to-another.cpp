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
    bool findPath(TreeNode* node, int target, string& path){
        if (!node) return false;
        
        if (node -> val == target) return true;
        
        // Try left subtree
        path.push_back('L');
        if (findPath(node -> left, target, path))
            return true;
        path.pop_back(); // Remove the last character
        
        // Try right subtree
        path.push_back('R');
        if (findPath(node -> right, target, path))
            return true;
        path.pop_back(); // Remove the last character
        
        return false;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathStart = "", pathDest = "";
        
        // Find paths from root to start and destination nodes
        findPath(root, startValue, pathStart);
        findPath(root, destValue, pathDest);
        
        string directions = "";
        int commonPathLength = 0;
        
        // Find the lenght of the common path
        while (commonPathLength < pathStart.size() && commonPathLength < pathDest.size() && \
              pathStart[commonPathLength] == pathDest[commonPathLength])
            ++commonPathLength;
        
        // Add "U" for each step to go up from start to common ancestor
        directions.append(pathStart.size() - commonPathLength, 'U');
        
        // Add directions from common ancestor to destination
        directions.append(pathDest.substr(commonPathLength, pathDest.size() - commonPathLength));
        
        return directions;
    }
};