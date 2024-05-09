class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // sort in descending order
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long ans = 0;
        int turns = 0;
        
        // Calculate the maximum happiness sum
        for (int i = 0; i < k; ++i){
            // Adjust happiness and ensure it's not negative
            ans += max(happiness[i] - turns, 0);
            
            // Increment turns for the next iteration
            ++turns;
        }
        
        return ans;
    }
};