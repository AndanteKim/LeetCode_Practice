class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        def gcd(a: int, b: int) -> int:
            while b > 0:
                a %= b
                a, b = b, a
            return a
        
        def add(t: str, start: int) -> str:
            original = int(t[start])
            min_val, times = 10, 0

            for i in range(10):
                added = (original + i * a) % 10
                if added < min_val:
                    min_val = added
                    times = i
            
            t_list = list(t)
            for i in range(start, n, 2):
                t_list[i] = str((int(t_list[i]) + times * a) % 10)
            return "".join(t_list)

        n, ans = len(s), s
        s += s
        g = gcd(n, b)

        for i in range(0, n, g):
            t = s[i : i + n]
            t = add(t, 1)
            if b % 2:
                t = add(t, 0)
            
            if t < ans:
                ans = t
        
        return ans
