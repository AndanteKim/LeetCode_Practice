class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = []
        r = 0   # unjudged minimum index
        n = len(nums)

        for j in range(n):
            if nums[j] == key:
                l, r = max(r, j - k), min(n - 1, j + k) + 1
                for i in range(l, r):
                    ans.append(i)
        
        return ans