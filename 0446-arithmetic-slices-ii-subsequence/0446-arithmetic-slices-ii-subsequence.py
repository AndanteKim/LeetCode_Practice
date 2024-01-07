class Solution:
    def dp(self, nums: List[int], i: int, diff: int, cnt: int, counter: DefaultDict[int, List[int]], memo: Dict[int, Tuple[int]]) -> int:
        if (i, diff, cnt) in memo:
            return memo[(i, diff, cnt)]
        
        ans = 0
        if cnt >= 3:
            ans += 1
        
        if nums[i] + diff in counter:
            for j in counter[nums[i] + diff]:
                if j > i:
                    ans += self.dp(nums, j, diff, cnt + 1, counter, memo)
        
        memo[(i, diff, cnt)] = ans
        return ans
    
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n, counter = len(nums), defaultdict(list)
        
        for i in range(n):
            counter[nums[i]].append(i)
            
        ans, memo = 0, dict()
        
        for i in range(n):
            for j in range(i + 1, n):
                ans += self.dp(nums, j, nums[j] - nums[i], 2, counter, memo)
        
        return ans