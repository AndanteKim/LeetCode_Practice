class Solution {
public:
    bool static comp(pair<int, int> x, pair<int, int> y){
        if (x.first == y.first) return x.second < y.second;
        return false;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> v;
        for (auto x : arr){
            v.push_back({__builtin_popcount(x), x});
        }
        sort(v.begin(), v.end());
        
        vector<int> ans;
        for (auto x:v){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};