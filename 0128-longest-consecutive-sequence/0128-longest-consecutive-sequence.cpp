class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestStreak = 0;
        unordered_set<int> numSets(nums.begin(), nums.end());
        
        for (int num : nums){
            if (!numSets.count(num - 1)){
                int currentStreak = 1, currentNum = num; 
                
                while (numSets.count((currentNum++) + 1))
                    ++currentStreak;
                
                longestStreak = max(longestStreak, currentStreak);
            }
            
        }
        
        return longestStreak;
    }
};