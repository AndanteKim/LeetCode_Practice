class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        n, seen = len(digits), set()

        for i in range(n):
            for j in range(n):
                for k in range(n):
                    curr = digits[i] * 100 + digits[j] * 10
                    if i == j or j == k or i == k:
                        continue
                    curr += digits[k]
                    if curr >= 100 and curr % 2 == 0:
                        seen.add(curr)
        
        return len(seen)