class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freqs, ans = Counter(nums), 0
        mx = max(val for _, val in freqs.items())
        
        for _, val in freqs.items():
            if val == mx:
                ans += val
                
        return ans