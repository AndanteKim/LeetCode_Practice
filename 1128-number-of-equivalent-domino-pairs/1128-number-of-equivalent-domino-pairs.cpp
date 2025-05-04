class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        unordered_map<string, int> seen;

        for (const auto& domino : dominoes){
            int a = min(domino[0], domino[1]), b = max(domino[0], domino[1]);
            ++seen[to_string(a) + " " + to_string(b)];
        }

        for (const auto& [p, freq] : seen) ans += freq * (freq - 1) >> 1;
        
        return ans;
    }
};