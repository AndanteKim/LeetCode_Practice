class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        def is_valid(curr: int, dir: int, remain: int) -> bool:
            temp = nums[:]
            
            while remain > 0 and 0 <= curr < n:
                if temp[curr] > 0:
                    temp[curr] -= 1
                    dir *= -1
                    if temp[curr] == 0:
                        remain -= 1
                curr += dir

            return remain == 0
        
        n, ans, non_zero = len(nums), 0, sum(1 for num in nums if num > 0)
        
        for i in range(n):
            if nums[i] == 0:
                ans += is_valid(i, -1, non_zero)
                ans += is_valid(i, 1, non_zero)
        
        return ans
