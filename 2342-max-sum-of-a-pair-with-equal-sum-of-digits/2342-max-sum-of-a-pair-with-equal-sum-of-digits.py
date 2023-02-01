class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        digit_sum_lookup, max_val = defaultdict(list), float('-inf')
        for num in nums:
            n, digit_sum = num, 0
            while n != 0:
                digit_sum += n % 10
                n //= 10
            digit_sum_lookup[digit_sum].append(num)
            
        for key, value in digit_sum_lookup.items():
            if len(value) >= 2:
                value.sort(reverse = True)
                max_val = max(max_val, value[0] + value[1])
        print(digit_sum_lookup)
        
        return -1 if max_val == float('-inf') else max_val