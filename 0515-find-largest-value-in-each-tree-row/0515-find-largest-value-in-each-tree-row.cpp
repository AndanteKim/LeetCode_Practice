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
    vector<int> largestValues(TreeNode* root) {
        // Base case
        if (!root) return {};

        queue<TreeNode*> queue;
        queue.push(root);
        vector<int> ans;

        while (!queue.empty()){
            int size = queue.size(), largestVal = std::numeric_limits<int>::min();

            for (int i = 0; i < size; ++i){
                TreeNode* node = queue.front(); queue.pop();

                largestVal = max(largestVal, node -> val);
                if (node -> left)
                    queue.push(node -> left);
                
                if (node -> right)
                    queue.push(node -> right);
            }

            ans.push_back(largestVal);
        }

        return ans;
    }
};