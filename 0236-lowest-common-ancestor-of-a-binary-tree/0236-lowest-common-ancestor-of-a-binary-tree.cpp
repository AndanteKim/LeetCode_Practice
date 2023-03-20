/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> *st = new stack<TreeNode*>;
        st -> push(root);
        unordered_map<TreeNode*, TreeNode*> parent{{root, nullptr}};
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()){
            TreeNode* node = st -> top();
            st -> pop();
            
            if (node -> left){
                parent[node -> left] = node;
                st -> push(node -> left);
            }
            
            if (node -> right){
                parent[node -> right] = node;
                st -> push(node -> right);
            }
        }
        set<TreeNode*> ancestors;
        while (p){
            ancestors.insert(p);
            p = parent[p];
        }
        
        while (ancestors.find(q) == ancestors.end()){
            q = parent[q];
        }
               
        return q;
    }
};