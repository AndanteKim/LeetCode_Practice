class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int maxSatisfaction = 0, suffixSum = 0;
        
        for (int i = satisfaction.size() - 1; i >= 0 && satisfaction[i] + suffixSum > 0; --i){
            suffixSum += satisfaction[i];
            maxSatisfaction += suffixSum;
        }
        return maxSatisfaction;
    }
};