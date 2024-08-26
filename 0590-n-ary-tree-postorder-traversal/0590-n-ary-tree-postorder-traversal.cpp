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
public:
    vector<int> postorder(Node* root) {
        // Base case: If the root is nullptr, return the empty vector
        if (!root) return {};
        
        // Stack for traversal and stack to reverse the order.
        stack<Node*> nodeStack, reverseStack;
        nodeStack.push(root);
        
        // Traverse the tree using the nodeStack
        while (!nodeStack.empty()){
            Node* curr = nodeStack.top();
            nodeStack.pop();
            reverseStack.push(curr);
            
            // Push all the children of the current node to nodeStack
            for (Node* child : curr -> children)
                nodeStack.push(child);
        }
        
        vector<int> ans;
        // Pop nodes from reverseStack and add their values to the answer vector.
        while (!reverseStack.empty()){
            Node* curr = reverseStack.top();
            reverseStack.pop();
            ans.push_back(curr -> val);
        }
        
        return ans;
    }
};