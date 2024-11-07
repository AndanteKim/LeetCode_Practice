class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Map to store the length of square streak for each number
        unordered_map<int, int> streakLengths;
        sort(nums.begin(), nums.end());
        
        for (const int num : nums){
            int root = (int)sqrt(num);
            
            // Check if the number is a perfect square and its square root is in the map
            if (root * root == num && streakLengths.count(root)){
                // If so, extend the streak from its square root
                streakLengths[num] = streakLengths[root] + 1;
            }
            else
                // Otherwise, start a new streak
                streakLengths[num] = 1;
        }
        
        // Find the maximum streak length
        int longestStreak = 0;
        for (const auto& [_, streak] : streakLengths)
            longestStreak = max(longestStreak, streak);
        
        // Return -1 if no valid streak found, otherwise return the longest streak
        return (longestStreak > 1)? longestStreak : -1;
    }
};