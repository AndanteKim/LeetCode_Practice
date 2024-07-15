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
        TreeNode* root = nullptr;
        unordered_map<int, TreeNode*> seen;
        unordered_map<TreeNode*, TreeNode*> ancestors;
        
        for (vector<int>& description : descriptions){
            int p = description[0], c = description[1], isLeft = description[2];
            TreeNode* treeP = nullptr, *treeC = nullptr;
            
            if (seen.count(p)){
                treeP = seen[p];
                treeC = seen.count(c)? seen[c] : new TreeNode(c);
                
                if (isLeft) treeP -> left = treeC;
                else treeP -> right = treeC;
            }
            else{
                treeP = new TreeNode(p);
                treeC = seen.count(c)? seen[c] : new TreeNode(c);
                
                if (isLeft) treeP -> left = treeC;
                else treeP -> right = treeC;
            }
            
            ancestors[treeC] = treeP;
            seen[c] = treeC, seen[p] = treeP;
        }
        
        for (auto&[n, node] : seen){
            if (ancestors.find(node) == ancestors.end()){
                root = node;
            }
        }
        
        return root;
    }
};