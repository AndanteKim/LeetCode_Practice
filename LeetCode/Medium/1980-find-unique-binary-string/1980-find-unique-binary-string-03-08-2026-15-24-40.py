class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        ans, n = [], len(nums)
        for i in range(n):
            curr = nums[i][i]
            ans.append("1" if curr == "0" else "0")
        
        return "".join(ans)