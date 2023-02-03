class Solution {
public:
    string frequencySort(string s) {
        vector<vector<char>> bucket(s.size() + 1);
        unordered_map<char, int> m;
        string ans;
        
        for (const char &c : s) ++m[c];
        
        for (const auto&[key, value] : m){
            bucket[value].push_back(key);
        }
        
        for (int i = bucket.size() - 1; i > 0; --i){
            for (int j = 0 ; j < bucket[i].size(); ++j){
                for (int count = i; count > 0; --count) ans += bucket[i][j];
            }
        }
        return ans;
    }
};