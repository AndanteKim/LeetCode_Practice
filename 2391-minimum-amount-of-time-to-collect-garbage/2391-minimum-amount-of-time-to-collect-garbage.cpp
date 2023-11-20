class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> prefixSum(travel.size() + 1);
        for (int i = 0; i < travel.size(); ++i)
            prefixSum[i + 1] = prefixSum[i] + travel[i];
        
        // map to store garbage count, type
        unordered_map<char, int> garbageLastPos, garbageCount;
        for (int i = 0; i < garbage.size(); ++i){
            for (char& c : garbage[i]){
                ++garbageCount[c];
                garbageLastPos[c] = i;
            }
        }
        
        int ans = 0;
        for (auto& [c, i]: garbageLastPos){
            // add only if there is at least one unit of this garbage
            if (garbageCount[c] > 0){
                ans += garbageCount[c] + prefixSum[i];
            }
        }
        
        return ans;
    }
};