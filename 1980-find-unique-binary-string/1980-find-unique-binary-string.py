class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        def generate(curr: str) -> str:
            if len(curr) == n:
                if curr not in nums:
                    return curr
                return ""
            
            add_zero = generate(curr + "0")
            if add_zero:
                return add_zero
            return generate(curr + "1")
        
        n, nums = len(nums), set(nums)
        return generate("")
        