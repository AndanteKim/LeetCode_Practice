class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        def calculate(x: str) -> int:
            if len(x) < len(s):
                return 0

            if len(x) == len(s):
                return 1 if x >= s else 0
            
            count, suffix = 0, x[len(x) - len(s) :]
            pre_len = len(x) - len(s)

            for i in range(pre_len):
                if limit < int(x[i]):
                    count += (limit + 1) ** (pre_len - i)
                    return count
                count += int(x[i]) * (limit + 1) ** (pre_len - 1 - i)

            if suffix >= s:
                count += 1
            return count

        start_ = str(start - 1)
        finish_ = str(finish)
        return calculate(finish_) - calculate(start_)