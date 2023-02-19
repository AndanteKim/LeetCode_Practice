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
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        deque<int> level_list;
        deque<TreeNode*> node_queue{{root, NULL}};
        bool is_order_left = true;
        
        while (!node_queue.empty()){
            TreeNode *curr_node = node_queue.front();
            node_queue.pop_front();
            if (curr_node != NULL){
                if (is_order_left) level_list.push_back(curr_node -> val);
                else level_list.push_front(curr_node -> val);
                
                if (curr_node -> left) node_queue.push_back(curr_node -> left);
                if (curr_node -> right) node_queue.push_back(curr_node -> right);
            }
            else{
                vector<int> sub_vec(level_list.begin(), level_list.end());
                ans.push_back(sub_vec);
                level_list.clear();
                if (node_queue.size() > 0) node_queue.push_back(NULL);
                is_order_left = !is_order_left;
            }
        }
        
        return ans;
    }
};