# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        
        # Since there is no duplicate number between guessing number, maintain left = mid + 1, right = mid - 1 instead of left = mid + 1, mid = right
        left, right = 1, n
        while left <= right:
            mid = (left + right) >> 1
            if guess(mid) == 1:
                left = mid + 1
            elif guess(mid) == -1:
                right = mid - 1
            else:
                return mid
            
        return -1
                
                
                