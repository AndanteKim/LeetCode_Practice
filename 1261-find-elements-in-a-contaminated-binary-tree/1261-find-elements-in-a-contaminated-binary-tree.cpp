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
class FindElements {
private:
    unordered_set<int> seen;

public:
    FindElements(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto [node, x] = q.front(); q.pop();
            seen.insert(x);

            if (node -> left)
                q.push({node -> left, 2 * x + 1});
            
            if (node -> right)
                q.push({node -> right, 2 * x + 2});
        }
    }
    
    bool find(int target) {
        return seen.find(target) != seen.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */