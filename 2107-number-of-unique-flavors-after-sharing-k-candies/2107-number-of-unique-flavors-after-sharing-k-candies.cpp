class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int totalFlavors = 0, n = candies.size(), lostFlavors = 0;
        unordered_map<int, int> countFlavors;
        
        for (int candy : candies){
            if (countFlavors[candy] == 0)
                ++totalFlavors;
            ++countFlavors[candy];
        }
        
        int ans = 0, left = 0;
        for (int right = 0; right < n; ++right){
            while (right - left >= k){
                if (countFlavors[candies[left]] == 0)
                    --lostFlavors;
                ++countFlavors[candies[left++]];
            }
            
            --countFlavors[candies[right]];
            if (countFlavors[candies[right]] == 0)
                ++lostFlavors;
            
            if (right >= max(0, k - 1))
                ans = max(ans, totalFlavors - lostFlavors);
        }
        
        return ans;
    }
};