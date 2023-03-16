/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
    unordered_map<Node*, NodeCopy*> seen;
    
    NodeCopy* dfs(Node* root){
        if (!root) return nullptr;
        
        if (seen[root] != nullptr) return seen[root];
        NodeCopy* new_root = new NodeCopy(root -> val);
        seen[root] = new_root;
        new_root -> left = dfs(root -> left);
        new_root -> right = dfs(root -> right);
        new_root -> random = dfs(root -> random);
        
        return new_root;
    }
    
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy* new_root = dfs(root);
        
        return new_root;
    }
};