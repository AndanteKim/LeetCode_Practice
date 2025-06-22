class Solution:
    def kEmptySlots(self, bulbs: List[int], k: int) -> int:
        n = len(bulbs)
        days = [0] * n

        for day, position in enumerate(bulbs, 1):
            days[position - 1] = day
        
        ans = float('inf')
        left, right = 0, k + 1

        while right < n:
            for i in range(left + 1, right):
                if days[i] < days[left] or days[i] < days[right]:
                    left, right = i, i + k + 1
                    break
            else:
                ans = min(ans, max(days[left], days[right]))
                left, right = right, right + k + 1
        
        return ans if ans != float('inf') else -1