/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    string backtrackPath(TreeNode* node, unordered_map<TreeNode*, pair<TreeNode*, string>>& pathTracker){
        string path = "";
        
        // Construct the path
        while (pathTracker.count(node)){
            // Add the directions in reverse order and move on to the previous node.
            path += pathTracker[node].second;
            node = pathTracker[node].first;
        }
        
        reverse(path.begin(), path.end());
        return path;
    }
    
    void populateParentMap(TreeNode* node, unordered_map<int, TreeNode*>& parentMap){
        if (!node) return;
        
        // Add children to the map and recurse further
        if (node -> left){
            parentMap[node -> left -> val] = node;
            populateParentMap(node -> left, parentMap);
        }
        
        if (node -> right){
            parentMap[node -> right -> val] = node;
            populateParentMap(node -> right, parentMap);
        }
    }
    
    TreeNode* findStartNode(TreeNode* node, int startValue){
        if (!node) return nullptr;
        
        if (node -> val == startValue) return node;
        
        TreeNode* leftResult = findStartNode(node -> left, startValue);
        // If left subtree returns a node, it must be a start node. Return it. Otherwise, return whatever
        // is returned by right subtree.
        if (leftResult) return leftResult;
        
        return findStartNode(node -> right, startValue);
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Map to store the parent nodes
        unordered_map<int, TreeNode*> parentMap;
        
        // Find the start node and populate the parent map
        TreeNode* startNode = findStartNode(root, startValue);
        populateParentMap(root, parentMap);
        
        // Perform BFS to find the path.
        queue<TreeNode*> q;
        q.push(startNode);
        unordered_set<TreeNode*> visitedNodes;
        
        // Key: next node, Value: {current node, direction}
        unordered_map<TreeNode*, pair<TreeNode*, string>> pathTracker;
        visitedNodes.insert(startNode);
        
        while (!q.empty()){
            TreeNode* currNode = q.front(); q.pop();
            
            // If the destination is reached, return the path.
            if (currNode -> val == destValue)
                return backtrackPath(currNode, pathTracker);
            
            // Check and add parent node
            if (parentMap.count(currNode -> val)){
                TreeNode* parentNode = parentMap[currNode -> val];
                if (!visitedNodes.count(parentNode)){
                    q.push(parentNode);
                    pathTracker[parentNode] = {currNode, "U"};
                    visitedNodes.insert(parentNode);
                }
            }
            
            // Check and add left child
            if (currNode -> left && !visitedNodes.count(currNode -> left)){
                q.push(currNode -> left);
                pathTracker[currNode -> left] = {currNode, "L"};
                visitedNodes.insert(currNode -> left);
            }
            
            // Check and add right child
            if (currNode -> right && !visitedNodes.count(currNode -> right)){
                q.push(currNode -> right);
                pathTracker[currNode -> right] = {currNode, "R"};
                visitedNodes.insert(currNode -> right);
            }
        }
        
        // This line should never be reached if the tree is valid.
        return "";
    }
};