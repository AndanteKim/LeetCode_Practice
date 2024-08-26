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
        
        vector<int> ans;
        stack<pair<Node*, bool>> nodeStack;
        nodeStack.push({root, false});
        
        while (!nodeStack.empty()){
            auto& [curr, isVisited] = nodeStack.top();
            
            if (isVisited){
                // If the node has been visited, then add its value to the vector
                ans.push_back(curr -> val);
                
                // pop the stack to check the next
                nodeStack.pop();
            }
            else{
                // Mark the current node as visited.
                isVisited = true;
                
                // Push all children to the stack in reverse order.
                for (int i = curr -> children.size() - 1; i >= 0; --i){
                    nodeStack.push({curr -> children[i], false});
                }
            }
        }
        
        return ans;
    }
};