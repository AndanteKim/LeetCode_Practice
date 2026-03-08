class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        def backtrack(curr: str) -> str:
            if len(curr) == n:
                if curr not in nums:
                    return curr

                return ""
            
            add_zero = backtrack(curr + "0")
            if add_zero:
                return add_zero
            return backtrack(curr + "1")

        n, nums = len(nums), set(nums)
        return backtrack("")
