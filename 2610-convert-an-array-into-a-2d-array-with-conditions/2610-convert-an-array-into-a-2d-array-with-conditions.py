class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        freq, ans = [0] * (len(nums) + 1), []
        
        for n in nums:
            if freq[n] >= len(ans):
                ans.append([])
                
            # Store the integer in the list corresponding to its current frequency.
            ans[freq[n]].append(n)
            freq[n] += 1
        
        return ans