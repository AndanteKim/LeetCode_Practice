class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        lookup = defaultdict(int)
        ans = 0
        
        for num in nums:
            complement = k - num
            if lookup[complement] > 0:
                # remove complement from the map
                lookup[complement] -= 1
                ans += 1
            else:
                # add current element in the map
                lookup[num] += 1
        
        return ans