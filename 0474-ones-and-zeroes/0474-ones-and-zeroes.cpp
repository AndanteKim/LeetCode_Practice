class Solution {
private:
    int dp(int i, vector<vector<vector<int>>>& memo, vector<string>& strs, int remM, int remN){
        if (i < 0) return 0;
        if (remM == 0 && remN == 0) return 0;
        if (memo[i][remM][remN] != -1) return memo[i][remM][remN];
        
        int countM = count(strs[i].begin(), strs[i].end(), '0'), take = 0, notTake = 0;
        int countN = strs[i].size() - countM;
        if (countM <= remM && countN <= remN)
            take = 1 + dp(i - 1, memo, strs, remM - countM, remN - countN);
        notTake = dp(i - 1, memo, strs, remM, remN);
        return memo[i][remM][remN] = max(take, notTake);
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = strs.size();
        vector memo(length, vector(m + 1, vector<int>(n + 1, -1)));
        return dp(length - 1, memo, strs, m, n);
    }
};