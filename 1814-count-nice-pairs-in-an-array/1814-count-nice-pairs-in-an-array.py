class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(num: int) -> int:
            res = 0
            while num:
                res = res * 10 + num % 10
                num //= 10
            
            return res
        
        arr = []
        for i in range(len(nums)):
            arr.append(nums[i] - rev(nums[i]))
            
        dic = defaultdict(int)
        ans, MOD = 0, 10 ** 9 + 7
        for num in arr:
            ans = (ans + dic[num]) % MOD
            dic[num] += 1
        
        return ans