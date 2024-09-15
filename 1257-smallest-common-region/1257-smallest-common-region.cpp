class Solution {
private:
    // Function to return an array representing the path from the root node
    // to the current node.
    void fetchToPath(string& currNode, unordered_map<string, string>& childParentMap, vector<string>& path){
        // Start by adding the current node to the path.
        path.push_back(currNode);
        
        // Traverse upwards through the tree by finding the parent of the current node.
        // Continue until the root node is reached.
        while (childParentMap.count(currNode)){
            string parentNode = childParentMap[currNode];
            path.push_back(parentNode);
            currNode = parentNode;
        }
        
        reverse(path.begin(), path.end());
    }
    
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        // Hash map to store (child -> parent) relationships for each region.
        unordered_map<string, string> childParentMap;
        
        // Populate the 'childParentMap' using the provided 'regions' list.
        for (const auto& currRegion : regions){
            for (int i = 1; i < currRegion.size(); ++i){
                childParentMap[currRegion[i]] = currRegion[0];
            }
        }
        
        // Store the paths from the root node to 'region1' and 'region2'
        // nodes in their respective arrays.
        vector<string> path1, path2;
        fetchToPath(region1, childParentMap, path1);
        fetchToPath(region2, childParentMap, path2);
            
        int i = 0, j = 0;
        string lowestCommonAncestor = "";
        
        // Traverse both paths simultansiously until the paths diverge.
        // The last common node is the lowest common ancestor.
        while (i < path1.size() && j < path2.size() && path1[i] == path2[j]){
            lowestCommonAncestor = path1[i];
            ++i;
            ++j;
        }
        
        // Reuturn the lowest common ancestor of 'region1' and 'region2'.
        return lowestCommonAncestor;
    }
};