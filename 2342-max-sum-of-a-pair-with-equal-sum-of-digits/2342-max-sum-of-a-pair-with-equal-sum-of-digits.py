class Solution:
    # Helper function to compute the sum digits of a number
    def calculate_digit_sum(self, num: int) -> int:
        digit_sum = 0
        while num > 0:
            digit_sum += num % 10
            num //= 10
        
        return digit_sum
    
    def maximumSum(self, nums: List[int]) -> int:
        digit_sum_pairs = []

        # Store number with their digit sums as pairs
        for num in nums:
            digit_sum = self.calculate_digit_sum(num)
            digit_sum_pairs.append((digit_sum, num))

        # Sort based on digit sums, and if equal, by number value
        digit_sum_pairs.sort()

        ans = -1

        # Iterate through the sorted array to find the maximum sum of pairs
        for idx in range(1, len(digit_sum_pairs)):
            curr_digit_sum, prev_digit_sum = digit_sum_pairs[idx][0], digit_sum_pairs[idx - 1][0]

            # If two consecutive numbers have the same digit sum
            if curr_digit_sum == prev_digit_sum:
                curr_sum = digit_sum_pairs[idx][1] + digit_sum_pairs[idx - 1][1]
                ans = max(ans, curr_sum)

        return ans

        
