class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        length, count = [0] * n, [0] * n
        
        def calculate_dp(i: int) -> None:
            if length[i] != 0:
                return
            
            length[i], count[i] = 1, 1
            
            for j in range(i):
                if nums[j] < nums[i]:
                    calculate_dp(j)
                    if length[j] + 1 > length[i]:
                        length[i] = length[j] + 1
                        count[i] = 0
                    if length[j] + 1 == length[i]:
                        count[i] += count[j]
                        
        max_length, ans = 0, 0
        for i in range(n):
            calculate_dp(i)
            max_length = max(max_length, length[i])
            
        for i in range(n):
            if length[i] == max_length:
                ans += count[i]
        return ans
        