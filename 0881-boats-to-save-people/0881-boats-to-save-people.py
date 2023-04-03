class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        count = [0] * (limit + 1)
        for p in people:
            count[p] += 1
            
        idx = 0
        for val in range(1, limit + 1):
            while count[val] > 0:
                people[idx] = val
                idx += 1
                count[val] -= 1
        
        ans, left, right = 0, 0, len(people) - 1
        
        while left <= right:
            if people[left] + people[right] <= limit:
                left += 1
                right -= 1
            else:
                right -= 1
            ans += 1
        return ans