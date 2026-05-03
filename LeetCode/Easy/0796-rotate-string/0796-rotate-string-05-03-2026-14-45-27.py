class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if s == goal:
            return True
        
        s_dq, goal_dq = deque([c for c in s]), deque([c for c in goal])
        n = len(s)

        for _ in range(n):
            s_dq.append(s_dq.popleft())

            if s_dq == goal_dq:
                return True

        return False