class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        
        queue, g, n = deque([c for c in s]), [c for c in goal], len(s)
        
        for _ in range(n):
            queue.appendleft(queue.pop())
            
            if list(queue) == g:
                return True
            
        return False