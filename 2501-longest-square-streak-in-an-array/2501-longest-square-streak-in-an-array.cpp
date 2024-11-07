class Solution {
private:
    int n;
    // Binary search helper function to efficiently find a value in the sorted array
    bool binarySearch(int target, vector<int>& nums){
        int left = 0, right = n - 1;
        
        while (left <= right){
            int mid = (left + right) >> 1;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return false;
    }
    
public:
    int longestSquareStreak(vector<int>& nums) {
        this -> n = nums.size();
        // Set to keep track of numbers we've already processed
        set<int> processedNumbers;
        int longestStreak = 0;
        
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
        
        // Iterate through each number in the sorted array
        for (int current : nums){
            // Skip if we've already processed this number
            if (processedNumbers.count(current))
                continue;
            
            int streak = current, streakLength = 1;
            // Continue the streak as long as we can find the square of the current number
            while ((long long)streak * streak <= pow(10, 5)){
                // If we find the square, continue the streak
                if (binarySearch((long long)streak * streak, nums)){
                    streak *= streak;
                    processedNumbers.insert(streak);
                    ++streakLength;
                }
                else
                    break;
            }
            
            // Update the longest streak if necessary
            longestStreak = max(longestStreak, streakLength);
        }
        
        // Return -1 if no valid streak found, otherwise return the longest streak
        return longestStreak < 2? -1 : longestStreak;
    }
};