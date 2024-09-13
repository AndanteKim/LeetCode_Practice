class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # In-place method and use carry for flipping digits
        carry = 1
        
        # Move along the input array starting from the end
        for i in range(len(digits) - 1, -1, -1):
            carry, digits[i] = (digits[i] + carry) // 10, (digits[i] + carry) % 10
        
        # If carry is larger than 0, then insert 1 at the digits' begin.
        if carry:
            digits = [1] + digits
            
        return digits