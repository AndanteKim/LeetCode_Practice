class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        m, u = max(nums), 1

        while u <= m:
            u <<= 1

        s, n = [False] * u, len(nums)
        
        for i in range(n):
            for j in range(i, n):
                s[nums[i] ^ nums[j]] = True
        
        t = [False] * u
        for x in range(u):
            if not s[x]:
                continue
            
            for v in nums:
                t[x ^ v] = True
        
        return sum(1 for b in t if b)