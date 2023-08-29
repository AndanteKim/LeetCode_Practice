class Solution:
    def maximumNumberOfOnes(self, width: int, height: int, sideLength: int, maxOnes: int) -> int:
        m, n = height, width
        ans = maxOnes * ((m // sideLength) * (n // sideLength))
        rest = maxOnes
        
        use1 = min((m % sideLength) * (n % sideLength), rest)
        ans += ((m // sideLength) + (n // sideLength) + 1) * use1
        rest -= use1
        
        if m // sideLength > n // sideLength:
            use2 = min(((n % sideLength) * sideLength) - ((m % sideLength) * (n % sideLength)), rest)
            ans += (m // sideLength) * use2
            rest -= use2
            use3 = min(((m % sideLength) * sideLength) - ((m % sideLength) * (n % sideLength)), rest)
            ans += (n // sideLength) * use3
            rest -= use3
        else:
            use2 = min(((m % sideLength) * sideLength) - ((m % sideLength) * (n % sideLength)), rest)
            ans += (n // sideLength) * use2
            rest -= use2
            use3 = min(((n % sideLength) * sideLength) - ((m % sideLength) * (n % sideLength)), rest)
            ans += (m // sideLength) * use3
            rest -= use3
        
        return ans