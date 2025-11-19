class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
            sets, curr = set(nums), original

            while curr in sets:
                curr *= 2

            return curr