class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        
        for (vector<int>& trip : trips) m[trip[1]] += trip[0], m[trip[2]] -= trip[0];
        
        for (auto& [k, v] : m){
            if ((capacity -= v) < 0) return false;
        }
        
        return true;
    }
};