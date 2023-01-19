class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        counts = Counter()
        running_sum, res = 0, 0
        
        for num in nums:
            running_sum += num
            if running_sum % k == 0:
                res += 1
            res += counts[running_sum % k]
            counts[running_sum % k] += 1
        return res