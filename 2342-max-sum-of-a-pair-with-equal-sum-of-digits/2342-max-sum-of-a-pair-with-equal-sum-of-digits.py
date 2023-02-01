class Solution:
    def get_digit_sum(self, num: int) -> int:
        digit_sum = 0
        while num:
            digit_sum += num % 10
            num //= 10
        
        return digit_sum
    
    def maximumSum(self, nums: List[int]) -> int:
        dic = defaultdict(int)
        ans = -1
        for num in nums:
            digit_sum = self.get_digit_sum(num)
            if digit_sum in dic:
                ans = max(ans, num + dic[digit_sum])
            dic[digit_sum] = max(dic[digit_sum], num)
        
        return ans