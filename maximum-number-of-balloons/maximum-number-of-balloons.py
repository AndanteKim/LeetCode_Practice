class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        hash_map = Counter(text)
        ans = 0
        while (hash_map['b'] >= 1 and hash_map['a'] >= 1 and hash_map['l'] >= 2 and hash_map['o'] >= 2 and hash_map['n'] >= 1):
            ans += 1
            hash_map['b'] -= 1
            hash_map['a'] -= 1
            hash_map['l'] -= 2
            hash_map['o'] -= 2
            hash_map['n'] -= 1
        
        return ans