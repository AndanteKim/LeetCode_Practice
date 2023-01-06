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
    
    void dfs(Node* root, vector<int> &ans){
        if (!root) return;
        vector<Node*> g = root -> children;
        ans.push_back(root -> val);
        for (int i = 0; i < g.size(); ++i) dfs(g[i], ans);
    }
public:
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};