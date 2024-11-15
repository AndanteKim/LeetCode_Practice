class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int ans = 0;
        unordered_map<int, int> d;
        for (int candy : candies){
            ++d[candy];
        }
        
        for (int i = 0; i < candies.size(); ++i){
            --d[candies[i]];
            if (d[candies[i]] == 0) d.erase(candies[i]);
            
            if (i >= k)
                ++d[candies[i - k]];
            
            if (i >= k - 1)
                ans = max(ans, (int)d.size());
        }
        
        return ans;
    }
};