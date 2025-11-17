class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        x = 0

        for num in nums:
            x = (x << 1) | num

        if x == 0 or k == 0:
            return True

        while x & 1 == 0:
            x >>= 1
        
        while x != 1:
            x >>= 1

            count = 0
            while x & 1 == 0:
                x >>= 1
                count += 1
            
            if count < k:
                return False

        return True