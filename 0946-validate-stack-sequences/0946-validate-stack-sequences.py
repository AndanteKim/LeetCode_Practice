class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        queue = deque(popped)
        stack = []
        for num in pushed:
            while stack and stack[-1] == queue[0]:
                stack.pop()
                queue.popleft()
            stack.append(num)
            
        while stack and stack[-1] == queue[0]:
            stack.pop()
            queue.popleft()
                
        return stack == []
        