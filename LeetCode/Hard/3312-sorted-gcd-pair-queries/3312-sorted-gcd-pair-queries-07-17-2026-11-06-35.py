class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        m = max(nums)
        cnt = [0] * (m + 1)

        for num in nums:
            cnt[num] += 1
        
        for i in range(1, m + 1):
            for j in range(i * 2, m + 1, i):
                cnt[i] += cnt[j]

        for i in range(1, m + 1):
            cnt[i] = cnt[i] * (cnt[i] - 1) >> 1
        
        for i in range(m, 0, -1):
            for j in range(i * 2, m + 1, i):
                cnt[i] -= cnt[j]
            
        for i in range(1, m+ 1):
            cnt[i] += cnt[i - 1]
        
        ans = []
        for q in queries:
            pos = bisect_left(cnt, q + 1)
            ans.append(pos)
        return ans