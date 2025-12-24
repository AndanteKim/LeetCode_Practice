class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort(reverse = True)
        ans, i, m, box_remain = 0, 0, len(capacity), 0
        for a in apple:
            while a > box_remain and i < m:
                box_remain += capacity[i]
                i += 1
                ans += 1
            box_remain -= a
        
        return ans