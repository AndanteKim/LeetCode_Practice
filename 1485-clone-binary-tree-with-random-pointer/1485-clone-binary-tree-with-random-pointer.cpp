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
    NodeCopy* bfs(Node* root){
        if (!root) return nullptr;
        queue<Node*> *pending = new queue<Node*>;
        pending -> push(root);
        seen[root] = new NodeCopy(root -> val);
        
        while (!pending -> empty()){
            Node* old_node = pending -> front();
            pending -> pop();
            NodeCopy* new_node = seen[old_node];
            
            if (old_node -> left){
                if (seen.find(old_node -> left) == seen.end()){
                    pending -> push(old_node -> left);
                    seen[old_node -> left] = new NodeCopy(old_node -> left -> val);
                }
                new_node -> left = seen[old_node -> left];
            }
            
            if (old_node -> right){
                if (seen.find(old_node -> right) == seen.end()){
                    pending -> push(old_node -> right);
                    seen[old_node -> right] = new NodeCopy(old_node -> right -> val);
                }
                new_node -> right = seen[old_node -> right];
            }
            
            if (old_node -> random){
                if (seen.find(old_node -> random) == seen.end()){
                    pending -> push(old_node -> random);
                    seen[old_node -> random] = new NodeCopy(old_node -> random -> val);
                }
                new_node -> random = seen[old_node -> random];
            }
        }
        
        return seen[root];
    }
    
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy* new_root = bfs(root);
        return new_root;
    }
};