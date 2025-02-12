class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        def find_sum_digits(num: int) -> int:
            sum_digits = 0
            while num > 0:
                sum_digits += num % 10
                num //= 10

            return sum_digits

        seen = defaultdict(list)
        for num in nums:
            heappush(seen[find_sum_digits(num)], -num)
        
        ans = -1
        for key in seen:
            if len(seen[key]) >= 2:
                ans = max(ans, -(heappop(seen[key]) + heappop(seen[key])))
        
        return ans