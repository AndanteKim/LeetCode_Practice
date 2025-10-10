class Solution {
private:
    int n, k;

    int dp(int index, vector<int>& energy, vector<int>& memo){
        if (index >= n) return 0;

        if (memo[index] != -1) return memo[index];

        return memo[index] = energy[index] + dp(index + k, energy, memo);
    }

public:
    int maximumEnergy(vector<int>& energy, int k) {
        this -> k = k;
        this -> n = energy.size();
        int maxEnergy = std::numeric_limits<int>::min();
        vector<int> memo(n, -1);

        for (int i = 0; i < n; ++i){
            maxEnergy = max(maxEnergy, dp(i, energy, memo));
        }

        return maxEnergy;
    }
};