class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n, ans = len(nums), 0
        cnt = [defaultdict(int) for _ in range(n)]
        
        for i in range(1, n):
            for j in range(i):
                delta = nums[i] - nums[j]
                total = 0
                if delta in cnt[j]:
                    total = cnt[j][delta]
                cnt[i][delta] += total + 1
                ans += total
                
                
        return ans
        