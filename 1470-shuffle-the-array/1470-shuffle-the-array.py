class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        x_sec, y_sec = len(nums) // 2, len(nums)
        ans = []
        for i in range(x_sec):
            x_n = nums[i]
            y_n = nums[x_sec + i]
            ans.extend([x_n, y_n])
            
        return ans