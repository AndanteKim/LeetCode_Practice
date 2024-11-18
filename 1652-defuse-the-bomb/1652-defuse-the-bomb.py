class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        ans = [0] * n
        
        if k == 0:
            return ans
        
        # Define the initial window and initial sum
        start, end, curr_sum = 1, k, 0
        if k < 0:
            start, end = n - abs(k), n - 1
        
        for i in range(start, end + 1):
            curr_sum += code[i]
        
        # Scan through the code array as i moving to the right, update the window sum.
        for i in range(n):
            ans[i] = curr_sum
            curr_sum = curr_sum - code[start % n] + code[(end + 1) % n]
            start += 1
            end += 1
            
        return ans