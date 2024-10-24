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
    // Checks whether the given pair of nodes should be examined be
    // pushed into the stack
    bool checkNodeValues(TreeNode* node1, TreeNode* node2){
        if (!(node1 || node2)) return true;
        
        if (node1 && node2 && node1 -> val == node2 -> val) return true;
        
        return false;
    }
    
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Initialize stack to store pairs of nodes
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({root1, root2});
        
        // While the stack isn't empty
        while (!s.empty()){
            auto [node1, node2] = s.top(); s.pop();
            
            if (!(node1 || node2)) continue;
            if (!(node1 && node2)) return false;
            if (node1 -> val != node2 -> val) return false;
            
            // Check both configurations: no swap and swap
            if (checkNodeValues(node1 -> left, node2 -> left) && checkNodeValues(node1 -> right, node2 -> right)){
                s.push({node1 -> left, node2 -> left});
                s.push({node1 -> right, node2 -> right});
            }
            else if (checkNodeValues(node1 -> left, node2 -> right) && checkNodeValues(node1 -> right, node2 -> left)){
                s.push({node1 -> left, node2 -> right});
                s.push({node1 -> right, node2 -> left});
            }
            else
                return false;
        }
        
        return true;
    }
};