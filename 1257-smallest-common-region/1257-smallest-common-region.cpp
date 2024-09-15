class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        // Simplify LCA with time complexity: O(n) where n is the total regions, space complexity: O(n)
        unordered_map<string, string> parents;
        for (const auto& region : regions){
            for (int i = 1; i < region.size(); ++i)
                parents[region[i]] = region[0];
        }
        
        string r1 = region1;
        unordered_set<string> ancestryHistory;
        ancestryHistory.insert(region1);
        while (parents.count(r1)){
            r1 = parents[r1];
            ancestryHistory.insert(r1);
        }
        
        string r2 = region2;
        while (!ancestryHistory.count(r2))
            r2 = parents[r2];
        return r2;
    }
};