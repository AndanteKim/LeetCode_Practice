class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        # Dictionary to store the length of square streak for each number
        streak_lengths = dict()
        nums.sort()
        
        for num in nums:
            root = int(num ** 0.5)
            
            # Check if the number is perfect square and its square root is in the dictionary
            if root * root == num and root in streak_lengths:
                # Extend the streak from its square root
                streak_lengths[num] = streak_lengths[root] + 1
            else:
                # Start a new streak
                streak_lengths[num] = 1
        
        # Find the maximum streak length
        longest_streak = max(streak_lengths.values(), default = 0)
        
        # Return -1 if no valid streak found, otherwise return the longest streak
        return longest_streak if longest_streak > 1 else -1