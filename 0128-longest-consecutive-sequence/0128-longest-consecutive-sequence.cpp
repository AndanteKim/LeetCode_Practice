class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestStreak = 0;
        unordered_set<int> numSets(nums.begin(), nums.end());
        
        for (int num : nums){
            if (!numSets.contains(num - 1)){
                int currentStreak = 0, currentNum = num; 
                
                while (numSets.contains(currentNum++))
                    ++currentStreak;
                
                longestStreak = max(longestStreak, currentStreak);
            }
            
        }
        
        return longestStreak;
    }
};