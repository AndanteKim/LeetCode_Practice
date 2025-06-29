/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
private:
    Node *first, *last;
    
    void dfs(Node* node){
        if (node){
            // left
            dfs(node -> left);
            
            // node
            if (last){
                // link the previous node (last)
                // with the current one (node)
                last -> right = node;
                node -> left = last;
            }
            else
                // keep the smallest node
                // to close DLL later on
                first = node;
            last = node;

            // right
            dfs(node -> right);
        }
    }

public:
    
    Node* treeToDoublyList(Node* root) {
        // Base case
        if (!root) return nullptr;

        dfs(root);

        // Close DLL
        first -> left = last;
        last -> right = first;
        return first;
    }
};