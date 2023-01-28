class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        counts = defaultdict(int)
        counts[0] = 1 # for length 1 subarray
        ans = curr = 0
        
        for num in nums:
            curr += num
            ans += counts[curr - k]
            counts[curr] += 1
        return ans
        