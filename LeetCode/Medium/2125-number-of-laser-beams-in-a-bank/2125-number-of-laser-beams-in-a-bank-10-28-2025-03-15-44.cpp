class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size();
        int ans = 0;
        vector<int> devicesCount;

        for (int i = 0; i < m; ++i){
            int curr = 0;
            for (int j = 0; j < n; ++j){
                curr += bank[i][j] - '0';
            }

            if(curr > 0)
                devicesCount.push_back(curr);
        }

        for (int i = 0; i < (int)devicesCount.size() - 1; ++i)
            ans += devicesCount[i] * devicesCount[i + 1];

        return ans;
    }
};