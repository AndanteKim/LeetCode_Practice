class Solution:
    def maximumBooks(self, books: List[int]) -> int:
        def cal_sum(l: int, r: int) -> int:
            cnt = min(books[r], r - l + 1)
            return (2 * books[r] - (cnt - 1)) * cnt >> 1
        
        n, st = len(books), []
        dp = [0] * n

        for i in range(n):
            curr = 0
            while st and books[st[-1]] - st[-1] >= books[i] - i:
                st.pop()
            
            if not st:
                dp[i] = cal_sum(0, i)
            else:
                j = st[-1]
                dp[i] = dp[j] + cal_sum(j + 1, i)

            st.append(i)

        return max(dp)