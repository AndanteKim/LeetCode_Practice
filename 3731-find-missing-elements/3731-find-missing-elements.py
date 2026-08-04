class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        sort, mn, mx = [0] * 101, float('inf'), float('-inf')

        for num in nums:
            sort[num] += 1
            mx = max(mx, num)
            mn = min(mn, num)

        ans = []
        for i in range(mn, mx + 1):
            if not sort[i]:
                ans.append(i)
        
        return ans