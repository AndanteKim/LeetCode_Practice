class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        for i in range(len(digits) - 1, -1, -1):
            digit = digits[i] + carry
            digits[i] = digit % 10
            carry = digit // 10

        return [carry] + digits if carry == 1 else digits