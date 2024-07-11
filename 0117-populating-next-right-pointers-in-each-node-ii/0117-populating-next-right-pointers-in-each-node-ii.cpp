/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    Node *prev = nullptr, *leftmost = nullptr;
    
    void processChild(Node* childNode){
        if (childNode){
            // If the "prev" pointer is already set, i.e. if we
            // already found at least one node on the next level,
            // setup its next pointer
            if (prev)
                prev -> next = childNode;            
            else{
                // Else it means this child node is the first node
                // we have encountered on the next level, so, we
                // set the leftmost pointer
                leftmost = childNode;
            }
            
            prev = childNode;
        }
    }
    
public:
    Node* connect(Node* root) {
        // base case
        if (!root) return root;
        
        // The root node is the only node on the first level
        // and hence its the leftmost node for that level
        leftmost = root;
        
        // Vairable to keep track of leading node on the "current" level
        Node* curr = leftmost;
        
        // We have no idead about the structure of the tree,
        // so, we keep going until we find the last level.
        // The nodes on the last level won't have any children
        while (leftmost){
            // "prev" tracks the lastest node on the "next" level
            // while "curr" tracks the latest node on the current
            // level.
            prev = nullptr, curr = leftmost;
            
            // We reset this so that we can re-assign it to the leftmost
            // node of the next level. Also, if there isn't one, this would
            // help break us out of the outermost loop.
            leftmost = nullptr;
            
            // Iterate on the nodes in the current level using
            // the next pointers already established.
            while (curr){
                // Process both the children and update the prev
                // and leftmost pointers as necessary.
                processChild(curr -> left);
                processChild(curr -> right);
                
                // Move onto the next node.
                curr = curr -> next;
            }
        }
        
        return root;
    }
};