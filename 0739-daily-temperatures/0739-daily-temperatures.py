class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n, stack = len(temperatures), []
        ans = [0] * n
        
        for i in range(n):
            while stack and temperatures[stack[-1]] < temperatures[i]:
                ans[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        
        return ans