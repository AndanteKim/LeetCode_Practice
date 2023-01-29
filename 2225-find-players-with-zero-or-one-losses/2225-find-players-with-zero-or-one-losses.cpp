class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost_lookup;
        
        for (const auto &match : matches) {
            ++lost_lookup[match[1]];
            lost_lookup[match[0]] += 0;
        }
        vector<int> zero_cnt, one_cnt;
        
        for (const auto&[loser, cnt] : lost_lookup) {
            if (cnt == 0) zero_cnt.push_back(loser);
            else if (cnt == 1) one_cnt.push_back(loser);
        }
        sort(zero_cnt.begin(), zero_cnt.end());
        sort(one_cnt.begin(), one_cnt.end());
        return {zero_cnt, one_cnt};
    }
};