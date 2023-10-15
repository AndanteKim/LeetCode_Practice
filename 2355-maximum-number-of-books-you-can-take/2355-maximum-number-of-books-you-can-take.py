class Solution:
    def maximumBooks(self, books: List[int]) -> int:
        n = len(books)
        
        # calculate the sum of books in a given range [l, r]
        def calculate_sum(l: int, r: int) -> int:
            cnt = min(books[r], r - l + 1)
            return (2 * books[r] - (cnt - 1)) * cnt // 2
        
        stack = []
        dp = [0] * n
        
        for i in range(n):
            # While we cannot push i, we pop from the stack
            while stack and books[stack[-1]] - stack[-1] >= books[i] - i:
                stack.pop()
                
            # compute dp[i]
            if not stack:
                dp[i] = calculate_sum(0, i)
            else:
                j = stack[-1]
                dp[i] = dp[j] + calculate_sum(j + 1, i)
            
            # push the current index onto the stack
            stack.append(i)
        
        # return the maximum element in the dp array
        return max(dp)