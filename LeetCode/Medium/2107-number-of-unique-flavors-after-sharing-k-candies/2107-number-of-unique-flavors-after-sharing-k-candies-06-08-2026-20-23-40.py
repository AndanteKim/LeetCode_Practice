class Solution:
    def shareCandies(self, candies: List[int], k: int) -> int:
        freq = Counter(candies)

        unique, windows = len(freq), 0
        for i in range(k):
            freq[candies[i]] -= 1
            if freq[candies[i]] == 0:
                windows += 1

        ans = unique - windows

        for i in range(k, len(candies)):
            freq[candies[i - k]] += 1
            if freq[candies[i - k]] == 1:
                windows -= 1

            freq[candies[i]] -= 1
            if freq[candies[i]] == 0:
                windows += 1

            ans = max(ans, unique - windows)

        return ans