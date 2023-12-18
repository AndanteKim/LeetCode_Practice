class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        def computing(i: int, count: int) -> int:
            product = 1
            if i == 0:
                while i < len(count_sort) and count < 2:
                    if count_sort[i]:
                        product *= i
                        count_sort[i] -= 1
                        count += 1
                    else:
                        i += 1
            else:
                while i >= 0 and count < 2:
                    if count_sort[i]:
                        product *= i
                        count_sort[i] -= 1
                        count += 1
                    else:
                        i -= 1
            return product
        
        max_num = max(nums)
        count_sort = [0] * (max_num + 1)
        for num in nums:
            count_sort[num] += 1
        
        max_pair, min_pair = computing(max_num, 0), computing(0, 0)
        return max_pair - min_pair