class Solution:
    def maxLength(self, ribbons: List[int], k: int) -> int:
        def cut_ribbons(target: int) -> int:
            nums = 0
            for ribbon in ribbons:
                nums += ribbon // target
                
            return nums
        
        ans, left, right = 0, 1, max(ribbons)
        while left <= right:
            mid = left + ((right - left) >> 1)
            
            ribs = cut_ribbons(mid)
            if ribs >= k:
                ans = mid
                left = mid + 1
            elif ribs < k:
                right = mid - 1
                
        return ans