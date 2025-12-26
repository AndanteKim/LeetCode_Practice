class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        open_penalty, close_penalty = 0, sum([1 if c == 'Y' else 0 for c in customers])
        ans, curr_penalty = 0, open_penalty + close_penalty

        for i, visit in enumerate(customers):
            if visit == 'N':
                open_penalty += 1
            else:
                close_penalty -= 1
            
            if curr_penalty > open_penalty + close_penalty:
                ans = i + 1
                curr_penalty = open_penalty + close_penalty

        return ans