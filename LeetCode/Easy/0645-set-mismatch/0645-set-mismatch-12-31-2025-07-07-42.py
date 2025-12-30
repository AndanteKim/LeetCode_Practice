class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        freq, n = Counter(nums), len(nums)
        missing, twice = 0, 0

        for i in range(1, n + 1):
            if freq[i] == 2:
                twice = i
            
            if freq[i] == 0:
                missing = i

        return [twice, missing]