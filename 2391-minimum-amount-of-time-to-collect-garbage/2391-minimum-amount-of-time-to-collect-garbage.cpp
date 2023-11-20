class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for (int i = 1; i < travel.size(); ++i)
            travel[i] = travel[i - 1] + travel[i];
        
        int ans = 0;
        unordered_map<char, int> garbageLastPos;
        for (int i = 0; i < garbage.size(); ++i){
            for (char& c : garbage[i])
                garbageLastPos[c] = i;
            ans += garbage[i].size();
        }
        
        string type = "MPG";
        for (char& c : type){
            ans += (garbageLastPos[c] == 0? 0 : travel[garbageLastPos[c] - 1]);
        }
        return ans;
    }
};