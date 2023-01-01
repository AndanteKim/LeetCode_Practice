class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = -1, sum;
        for (const auto &account:accounts){
            sum = accumulate(account.begin(),account.end(), 0);
            if (sum > max) max = sum;
        }
        return max;
    }
};