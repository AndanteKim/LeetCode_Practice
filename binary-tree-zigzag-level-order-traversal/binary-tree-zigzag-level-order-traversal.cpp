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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        deque<TreeNode*> *dq = new deque<TreeNode*>;
        vector<vector<int>> ans;
        dq -> push_back(root);
        bool reverse = false;
        
        while (!dq -> empty()){
            vector<int> bfs;
            int sz = dq -> size();
            if (!reverse){
                for (int i = 0; i < sz; ++i){
                    TreeNode* node = dq -> front();
                    dq -> pop_front();
                    bfs.push_back(node -> val);
                    if (node -> left) dq -> push_back(node -> left);
                    if (node -> right) dq -> push_back(node -> right);
                }
                reverse = true;
            }
            else{
                for (int i = 0; i < sz; ++i){
                    TreeNode* node = dq -> back();
                    dq -> pop_back();
                    bfs.push_back(node -> val);
                    if (node -> right) dq -> push_front(node -> right);
                    if (node -> left) dq -> push_front(node -> left);
                }
                reverse = false;
            }
            ans.push_back(bfs);
        }
        
        return ans;
    }
};