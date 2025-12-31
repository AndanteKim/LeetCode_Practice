class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        exist = [False] * (n + 1)

        for num in nums:
            exist[num] = True
        
        ans = []
        for i in range(1, n + 1):
            if not exist[i]:
                ans.append(i)

        return ans