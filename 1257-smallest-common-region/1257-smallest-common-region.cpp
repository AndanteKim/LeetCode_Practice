class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        // LCA(Lowest Common Ancestor) method
        unordered_map<string, string> childToParent;
        
        for (const auto& region : regions){
            for (int i = 1; i < region.size(); ++i){
                childToParent[region[i]] = region[0];
            }
        }
        
        string r1Ancestor = region1;
        
        // Find the lowest common ancestor
        while (!r1Ancestor.empty()){
            string r2Ancestor = region2;
            while (!r2Ancestor.empty()){
                if (r1Ancestor == r2Ancestor)
                    return r1Ancestor;
                r2Ancestor = childToParent[r2Ancestor];
            }
            r1Ancestor = childToParent[r1Ancestor];
        }
        
        return "";
    }
};