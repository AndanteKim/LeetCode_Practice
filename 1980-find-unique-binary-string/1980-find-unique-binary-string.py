class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        def backtrack(i: int, curr: str) -> None:
            nonlocal ans
            if len(curr) == n:
                convert = "".join(curr)
                if convert not in nums:
                    ans = convert
                return
            
            curr.append('0')
            backtrack(i + 1, curr)
            curr.pop()
            
            curr.append('1')
            backtrack(i + 1, curr)
            curr.pop()
        
        n, curr, ans = len(nums), [], ""
        backtrack(0, curr)
        return ans