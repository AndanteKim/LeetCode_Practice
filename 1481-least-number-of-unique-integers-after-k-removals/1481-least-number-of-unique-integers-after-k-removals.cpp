class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> frequencies;
        
        for (int num : arr) ++frequencies[num];
        vector<pair<int, int>> combo;
        for (auto& [key, val] : frequencies) combo.push_back({key, val});
        
        sort(combo.begin(), combo.end(), [](pair<int, int>& a, pair<int, int>& b){return a.second > b.second;});
        
        while (k != 0){
            auto [key, val] = combo.back();
            combo.pop_back();
            
            if (--val > 0) combo.push_back({key, val});
            --k;
        }
        return combo.size();
    }
};