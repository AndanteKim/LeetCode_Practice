class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        # Binary search helper function to efficiently find a value in the sorted array
        def _binary_search(target: int) -> bool:
            left, right = 0, n - 1
            
            while left <= right:
                mid = (left + right) >> 1
                if nums[mid] == target:
                    return True
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
                
            return False
        
        # Sort the array in ascending order
        nums.sort()
        
        # Set to keep track of number we've already processed
        n, processed_numbers, longest_streak = len(nums), set(), 0
        
        # Iterate through each number in the sorted array
        for current in nums:
            # Skip if we've already processed this number
            if current in processed_numbers:
                continue
                
            streak, streak_length = current, 1
            
            # Continue the streak as long as we can find the square of the current number
            while streak * streak <= 10 ** 5:
                if _binary_search(streak * streak):
                    streak *= streak
                    processed_numbers.add(streak)
                    streak_length += 1
                else:
                    break
                    
            # Update the longest streak if necessary
            longest_streak = max(longest_streak, streak_length)
        
        # Return -1 if no valid streak found, otherwise return the longest streak
        return -1 if longest_streak < 2 else longest_streak