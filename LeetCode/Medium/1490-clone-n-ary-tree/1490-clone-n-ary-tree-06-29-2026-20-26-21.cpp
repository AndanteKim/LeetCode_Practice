/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    Node* dfs(Node* node) {
        if (!node) return nullptr;

        Node* newNode = new Node(node -> val);
        for (Node* child : node -> children) {
            newNode -> children.push_back(dfs(child));
        }

        return newNode;
    }

public:
    Node* cloneTree(Node* root) {
        return dfs(root);
    }
};