class Solution {
    int findMaxSatisfaction(vector<int>& satisfaction, vector<vector<int>>& memo, int index, int time){
        if (index == satisfaction.size()) return 0;
        
        if (memo[index][time] != -1) return memo[index][time];
        
        return memo[index][time] = max(satisfaction[index] * time + findMaxSatisfaction(satisfaction, memo, index + 1, time + 1),\
                                      findMaxSatisfaction(satisfaction, memo, index + 1, time));
    }
    
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int m = satisfaction.size();
        vector<vector<int>> memo(m + 1, vector<int>(m+1, -1));
        return findMaxSatisfaction(satisfaction, memo, 0, 1);
    }
};