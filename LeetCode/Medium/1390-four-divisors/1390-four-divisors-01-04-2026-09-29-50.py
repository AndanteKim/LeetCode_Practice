class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        divisors, divisors_count, max_num = [0] * (10 ** 5 + 1), [0] * (10 ** 5 + 1), max(nums)
        
        for i in range(1, max_num + 1):
            curr = i
            while curr <= max_num:
                divisors[curr] += i
                divisors_count[curr] += 1
                curr += i
        
        ans = 0
        for num in nums:
            if divisors_count[num] == 4:
                ans += divisors[num]

        return ans