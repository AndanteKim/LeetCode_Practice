class Solution:
    def clearStars(self, s: str) -> str:
        remove = set()
        min_heap = []

        for i, c in enumerate(s):
            if c == '*':
                remove.add(i)
                remove.add(-heappop(min_heap)[1])
            else:
                heappush(min_heap, (c, -i))
        
        return "".join(c for i, c in enumerate(s) if i not in remove)