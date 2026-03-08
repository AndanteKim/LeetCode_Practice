class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n, candidates = len(nums), set()
        
        for num in nums:
            dec = 0
            for i in range(n - 1, -1, -1):
                dec += (ord(num[i]) - 48) * (1 << (n - 1 - i))
            candidates.add(dec)

        for digit in range((1 << n)):
            if digit not in candidates:
                ans = []
                while digit > 0:
                    ans.append(chr(digit % 2 + 48))
                    digit >>= 1
                ans = ans[::-1]
                prefix = "0" * (n - len(ans))

                return prefix + "".join(ans)

        return ""