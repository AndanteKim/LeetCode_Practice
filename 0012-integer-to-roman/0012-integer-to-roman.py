class Solution:
    def intToRoman(self, num: int) -> str:
        values = [
            (1, "I"), (4, "IV"), (5, "V"),\
            (9, "IX"), (10, "X"), (40, "XL"),\
            (50, "L"), (90, "XC"), (100, "C"),\
            (400, "CD"), (500, 'D'), (900, "CM"),\
            (1000, 'M')
        ]
        
        ans, n = "", len(values) - 1
        while num > 0:
            i = n
            for i in range(n, -1, -1):
                val, roman = values[i]
                while num >= val:
                    ans += roman
                    num -= val
        
        return ans