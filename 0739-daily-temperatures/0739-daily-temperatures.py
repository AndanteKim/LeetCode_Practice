class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n, stack = len(temperatures), []
        ans = [0] * n
        
        for i in range(n):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                j = stack.pop()
                ans[j] = i - j
            stack.append(i)
            
        return ans