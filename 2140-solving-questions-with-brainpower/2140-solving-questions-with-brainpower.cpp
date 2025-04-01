class Solution {
private:
    int n;
    long long dp(int i, vector<long long>& memo, vector<vector<int>>& questions){
        // Base case
        if (i >= n)
            return 0;

        if (memo[i] != -1)  return memo[i];

        memo[i] = max(questions[i][0] + dp(i + 1 + questions[i][1], memo, questions), dp(i + 1, memo, questions));
        return memo[i];
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        this -> n = questions.size();
        vector<long long> memo(n, -1);
        return dp(0, memo, questions);
    }
};