class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        MOD, n = 1_000_000_007, len(nums)
        T = int(n ** 0.5)
        groups = [[] for _ in range(T)]

        for l, r, k, v in queries:
            if k < T:
                groups[k].append((l, r, v))
            else:
                for i in range(l, r + 1, k):
                    nums[i] = nums[i] * v % MOD
        
        diff = [1] * (n + T)
        for k in range(1, T):
            if not groups[k]:
                continue
            diff[:] = [1] * len(diff)
            for l, r, v in groups[k]:
                diff[l] = diff[l] * v % MOD
                R = ((r - l) // k + 1) * k + l
                diff[R] = diff[R] * pow(v, MOD - 2, MOD) % MOD

            for i in range(k, n):
                diff[i] = diff[i] * diff[i - k] % MOD
            
            for i in range(n):
                nums[i] = nums[i] * diff[i] % MOD
        
        ans = 0
        for x in nums:
            ans ^= x
        
        return ans
        

