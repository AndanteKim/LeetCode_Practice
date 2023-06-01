class Solution {
    double findProbability(int index, int target, int n, vector<vector<double>>& memo, vector<double>& prob){
        if (target < 0) return 0;
        
        if (index == n){
            if (target == 0) return 1;
            return 0;
        }
        
        if (memo[index][target] != -1.0) return memo[index][target];
        
        return memo[index][target] = findProbability(index + 1, target - 1, n, memo, prob) * prob[index] + findProbability(index + 1, target, n, memo, prob) * (1 - prob[index]);
    }
    
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> memo(n, vector<double>(target + 1, -1));
        
        return findProbability(0, target, n, memo, prob);
    }
};