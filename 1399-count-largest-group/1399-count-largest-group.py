class Solution:
    def countLargestGroup(self, n: int) -> int:
        ans, digit_count, largest = 0, dict(), 0

        for i in range(1, n + 1):
            s = 0
            
            while i > 0:
                s += i % 10
                i //= 10
            
            digit_count[s] = digit_count.get(s, 0) + 1
            largest = max(digit_count[s], largest)

        for d in digit_count.keys():
            if largest == digit_count[d]:
                ans += 1
        
        return ans