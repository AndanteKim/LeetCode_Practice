class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        
        for i in range(len(digits) - 1, -1, -1):
            carry, digits[i] = (digits[i] + carry) // 10, (digits[i] + carry) % 10
            
        if carry:
            digits = [1] + digits
            
        return digits