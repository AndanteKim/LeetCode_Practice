class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if a == '0' and b == '0':
            return '0'

        a_dec, b_dec, exp = 0, 0, 0

        for i in range(len(a) - 1, -1, -1):
            a_dec += (ord(a[i]) - 48) * (2 ** exp)
            exp += 1

        exp = 0
        for i in range(len(b) - 1, -1, -1):
            b_dec += (ord(b[i]) - 48) * (2 ** exp)
            exp += 1

        total, ans = a_dec + b_dec, []
        while total > 0:
            ans.append(chr(total % 2 + 48))
            total >>= 1

        return "".join(ans[::-1])