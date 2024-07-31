class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        def dp(i: int, remain: int, max_height_prev: int, memo: List[List[int]]) -> int:
            # Base case
            if i == n:
                return max_height_prev
            
            if memo[i][remain] != -1:
                return memo[i][remain]
            
            min_height = float('inf')
            # Check the remain of shelfwidth whether it's ok to put on
            if remain >= books[i][0]:
                min_height = min(dp(i + 1, remain - books[i][0], max(max_height_prev, books[i][1]), memo), max_height_prev + dp(i + 1, shelfWidth - books[i][0], books[i][1], memo))
            else:
                min_height = max_height_prev + dp(i + 1, shelfWidth - books[i][0], books[i][1], memo)
                
            memo[i][remain] = min_height
            return min_height
        
        n = len(books)
        memo = [[-1] * (shelfWidth + 1) for _ in range(n + 1)]
        return dp(0, shelfWidth, 0, memo)