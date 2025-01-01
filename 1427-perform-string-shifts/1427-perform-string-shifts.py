class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        dq = deque([c for c in s])

        for direction, amount in shift:
            if direction == 0:
                for _ in range(amount):
                    dq.append(dq.popleft())
            else:
                for _ in range(amount):
                    dq.appendleft(dq.pop())

        return "".join(dq)