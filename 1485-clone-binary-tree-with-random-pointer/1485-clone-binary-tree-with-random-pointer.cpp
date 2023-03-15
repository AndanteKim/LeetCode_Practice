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
    unordered_map<Node*, NodeCopy*> new_old_pairs;

    NodeCopy* deep_copy(Node* root){
        if(!root) return nullptr;
        NodeCopy* new_root = new NodeCopy(root -> val);
        new_root -> left = deep_copy(root -> left);
        new_root -> right = deep_copy(root -> right);
        new_old_pairs[root] = new_root;
        return new_root;
    }
    
    void map_random_pointers(Node* old_node){
        if (!old_node) return;
        NodeCopy* new_node = new_old_pairs[old_node];
        Node* old_node_random = old_node -> random;
        NodeCopy* new_node_random = new_old_pairs[old_node_random];
        new_node -> random = new_node_random;
        map_random_pointers(old_node -> left);
        map_random_pointers(old_node -> right);
    }
    
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy* new_root = deep_copy(root);
        map_random_pointers(root);
        return new_root;    
    }
};