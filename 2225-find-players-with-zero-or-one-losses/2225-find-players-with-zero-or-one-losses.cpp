class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int lost_cnt[100001];
        memset(lost_cnt, -1, sizeof(lost_cnt));
        for (const vector<int>& match : matches) {
            if (lost_cnt[match[0]] == -1) lost_cnt[match[0]] = 0;
            if (lost_cnt[match[1]] == -1) lost_cnt[match[1]] = 1;
            else ++lost_cnt[match[1]];
        }
        vector<int> zero_cnt, one_cnt;
        for (int i = 0; i <= 100000; ++i){
            if (lost_cnt[i] == 0) zero_cnt.push_back(i);
            else if (lost_cnt[i] == 1) one_cnt.push_back(i);
        }
        return {zero_cnt, one_cnt};
    }
};