class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        count, ans = Counter(stones), 0
        
        for c in jewels:
            ans += count[c]
        return ans