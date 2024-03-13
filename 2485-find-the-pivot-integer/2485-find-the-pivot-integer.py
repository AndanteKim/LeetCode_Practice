class Solution:
    def pivotInteger(self, n: int) -> int:
        left_value, right_value = 1, n
        sum_left, sum_right = left_value, right_value
        
        if n == 1:
            return n
        
        # Iterate until the pointers meet
        while left_value < right_value:
            # Adjust sums and pointers based on comparison
            if sum_left < sum_right:
                sum_left += left_value + 1
                left_value += 1
            else:
                sum_right += right_value - 1
                right_value -= 1
                
            # Check for pivot condition
            if sum_left == sum_right and left_value + 1 == right_value - 1:
                return left_value + 1
        
        return -1 # Return -1 if no pivot is found