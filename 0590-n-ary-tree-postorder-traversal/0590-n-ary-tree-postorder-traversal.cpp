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
    void dfs(Node* curr, vector<int>& ans){
        if (!curr)
            return;
        
        for (Node* child : curr -> children)
            dfs(child, ans);
        ans.push_back(curr -> val);
    }
    
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};