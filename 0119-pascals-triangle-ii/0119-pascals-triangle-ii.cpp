class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex <= 1){
            if (rowIndex == 0)
                return vector<int>{1};
            return vector<int>{1, 1};
        }
        
        vector<int> prevDp{{1, 1}}, dp;
        
        for (int num = 2; num <= rowIndex; ++num){
            dp.assign(num + 1, 1);
            for (int i = 1; i < num; ++i)
                dp[i] = prevDp[i - 1] + prevDp[i];
            prevDp = dp;
        }
        
        return dp;
    }
};