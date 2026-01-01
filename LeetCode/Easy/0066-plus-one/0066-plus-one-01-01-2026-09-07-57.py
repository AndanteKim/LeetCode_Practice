class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        integer, digit = 0, 0

        for i in range(len(digits) - 1, -1, -1):
            integer += digits[i] * (10 ** digit)
            digit += 1
        
        integer += 1
        ans = []
        while integer > 0:
            ans.append(integer % 10)
            integer //= 10
        return ans[::-1]