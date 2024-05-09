class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        # Sort in descending order
        happiness.sort(reverse = True)
        
        ans, turns = 0, 0
        
        # Calculate the maximum happiness sum
        for i in range(k):
            # Adjust happiness and ensure it's not negative
            ans += max(happiness[i] - turns, 0)
            
            # Increment turns for the next iteration
            turns += 1
        
        return ans