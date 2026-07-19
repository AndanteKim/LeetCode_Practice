class Solution:
    def smallestSubsequence(self, s: str) -> str:
        visited, nums = [0] * 26, [0] * 26

        for ch in s:
            nums[ord(ch) - 97] += 1
        
        stack = []
        for c in s:
            i = ord(c) - 97
            if not visited[i]:
                while stack and stack[-1] > c:
                    top_i = ord(stack[-1]) - 97
                    if nums[top_i] > 0:
                        visited[top_i] = 0
                        stack.pop()
                    else:
                        break
                visited[i] = 1
                stack.append(c)
            nums[i] -= 1

        return "".join(stack)