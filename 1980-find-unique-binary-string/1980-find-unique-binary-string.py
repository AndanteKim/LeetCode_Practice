class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        def backtrack(i: int, curr: str) -> None:
            if i == bin_len:
                if curr not in nums:
                    self.ans = curr
                return

            if self.ans != "":
                return

            for c in ('0', '1'):
                backtrack(i + 1, curr + c)
        
        bin_len, self.ans = len(nums), ""

        backtrack(0, "")

        return self.ans