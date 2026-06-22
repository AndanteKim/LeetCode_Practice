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
private:
    NodeCopy* dfs(Node* node, unordered_map<Node*, NodeCopy*>& seen) {
        if (!node) return nullptr;

        if (seen.contains(node)) return seen[node];

        seen[node] = new NodeCopy(node -> val);
        seen[node] -> left = dfs(node -> left, seen);
        seen[node] -> right = dfs(node -> right, seen);
        seen[node] -> random = dfs(node -> random, seen);

        return seen[node];
    }

public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> seen;
        return dfs(root, seen);
    }
};