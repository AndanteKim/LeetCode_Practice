class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        dic = defaultdict(int)
        for num in nums:
            dic[num] += 1
        
        ans = 0
        for key, val in dic.items():
            if val == 1:
                ans += key
        return ans
        