class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        op_brackets, min_required = 0, 0

        for c in s:
            if c == '(':
                op_brackets += 1
            else:
                if op_brackets > 0:
                    op_brackets -= 1
                else:
                    min_required += 1

        return min_required + op_brackets