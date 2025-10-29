class Solution:
    def smallestNumber(self, n: int) -> int:
        
        for num in range(n, n << 1 + 1):
            curr, is_all_sets = num, True

            while curr > 0:
                if curr & 1 == 0:
                    is_all_sets = False
                    break
                curr >>= 1
            if is_all_sets:
                return num

        return -1