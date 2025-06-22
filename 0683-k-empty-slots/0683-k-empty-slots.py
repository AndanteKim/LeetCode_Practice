class MinQueue(deque):
    def __init__(self):
        deque.__init__(self)
        self.mins = deque()

    def append(self, x: int) -> None:
        deque.append(self, x)
        while self.mins and x < self.mins[-1]:
            self.mins.pop()
        self.mins.append(x)

    def popleft(self):
        x = deque.popleft(self)
        if self.mins[0] == x:
            self.mins.popleft()
        return x
    
    def min(self):
        return self.mins[0]

class Solution:
    def kEmptySlots(self, bulbs: List[int], k: int) -> int:
        days = [0] * len(bulbs)
        for day, position in enumerate(bulbs, 1):
            days[position - 1] = day
        
        window, ans = MinQueue(), len(days)

        for i, day in enumerate(days):
            window.append(day)
            if k <= i and i < len(days) - 1:
                window.popleft()
                if k == 0 or days[i - k] < window.min() and window.min() > days[i + 1]:
                    ans = min(ans, max(days[i - k], days[i + 1]))

        return ans if ans < len(days) else -1