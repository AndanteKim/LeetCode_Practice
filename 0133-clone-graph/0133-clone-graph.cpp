/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        if (visited.find(node) != visited.end()) return visited[node];
        
        Node* CloneNode = new Node(node -> val, vector<Node*>());
        visited[node] = CloneNode;
        
        if (!node -> neighbors.empty()){
            for (Node* n : node -> neighbors)
                CloneNode -> neighbors.push_back(cloneGraph(n)); 
        }
        
        return CloneNode;
    }
};