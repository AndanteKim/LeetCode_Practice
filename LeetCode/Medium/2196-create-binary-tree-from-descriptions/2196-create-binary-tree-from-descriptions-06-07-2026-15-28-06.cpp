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
        unordered_map<int, int> ancestors;
        unordered_map<int, TreeNode*> load;

        for (const auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            TreeNode *p, *c;
            if (load.contains(parent))
                p = load[parent];
            else {
                p = new TreeNode(parent);
                load[parent] = p;
            }

            if (load.contains(child)) c = load[child];
            else {
                c = new TreeNode(child);
                load[child] = c;
            }

            if (isLeft) p -> left = c;
            else p -> right = c;

            ancestors[child] = parent;
        }

        for (const auto& [val, node] : load) {
            if (!ancestors.contains(val)) {
                return node;
            }
        }

        return nullptr;
    }
};