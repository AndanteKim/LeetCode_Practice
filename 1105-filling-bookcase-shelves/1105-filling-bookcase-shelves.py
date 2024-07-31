class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        # dp[i] will store the minimum height of the bookcase containing all
        # books up to and excluding i
        dp = [0] * (n + 1)
        dp[1] = books[0][1]
        
        for i in range(2, n + 1):
            # new shelf built to hold current book
            remain, max_height = shelfWidth - books[i - 1][0], books[i - 1][1]
            dp[i] = books[i - 1][1] + dp[i - 1]
            
            j = i - 1
            # Calculate the height when previous books are added to new shelf
            while j > 0 and remain - books[j - 1][0] >= 0:
                max_height = max(max_height, books[j - 1][1])
                remain -= books[j - 1][0]
                dp[i] = min(dp[i], max_height + dp[j - 1])
                j -= 1
            
        return dp[n]