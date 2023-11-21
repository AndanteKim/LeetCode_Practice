class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def rev(x: int) -> int:
            stack = []
            while x > 0:
                stack.append(x % 10)
                x //= 10
            num, digit = 0, 0
            while stack:
                num = (num + stack.pop() * (10 ** digit)) % (10 ** 9 + 7)
                digit += 1
            return num

        ans, pairs = 0, dict()
        for num in nums:
            diff = num - rev(num)
            pairs[diff] = pairs.get(diff, 0) + 1
        
        for _, freq in pairs.items():
            ans = (ans + ((freq * (freq - 1)) >> 1)) % (10 ** 9 + 7)
        
        return ans