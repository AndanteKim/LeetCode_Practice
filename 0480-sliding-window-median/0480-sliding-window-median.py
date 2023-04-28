class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        ans, window = [], []
        
        for i in range(len(nums)):
            if i >= k:
                window.pop(bisect.bisect(window, nums[i - k]) - 1)
            bisect.insort(window, nums[i])
            
            if i >= k - 1:
                ans.append(float((window[k // 2] if k & 1 > 0 else (window[k // 2 - 1] + window[k // 2]) * 0.5)))
        return ans