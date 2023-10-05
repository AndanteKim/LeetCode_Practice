# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        low, high = 1, n
        
        while low <= high:
            mid1, mid2 = low + ((high - low) // 3), high - ((high - low) // 3)
            res1, res2 = guess(mid1), guess(mid2)
            if res1 == 0:
                return mid1
            if res2 == 0:
                return mid2
            elif res1 < 0:
                high = mid1 - 1
            elif res2 > 0:
                low = mid2 + 1
            else:
                low = mid1 + 1
                high = mid2 - 1
        
        return -1
            