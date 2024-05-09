class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), [](int a, int b){return a > b;});
        
        long long ans = 0, curr = 0;
        
        for (int i = 0; i < k; ++i){
            if (curr > happiness[i]) break;
            ans += happiness[i] - (curr++);
        }
        
        return ans;
    }
};