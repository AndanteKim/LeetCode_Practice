class Solution:
    def pathSum(self, nums: List[int]) -> int:
        mapping = dict()

        for num in nums:
            coord, val = num // 10, num % 10
            mapping[coord] = val

        return self.dfs(nums[0] // 10, 0, mapping)
    
    def dfs(self, root_coord: int, pre_sum: int, coords: Dict[int, int]) -> int:
        level, pos = root_coord // 10, root_coord % 10

        left = (level + 1) * 10 + pos * 2 - 1
        right = (level + 1) * 10 + pos * 2
        curr_sum = pre_sum + coords[root_coord]

        if not (left in coords or right in coords):
            return curr_sum
        
        left_sum = self.dfs(left, curr_sum, coords) if left in coords else 0
        right_sum = self.dfs(right, curr_sum, coords) if right in coords else 0
        return left_sum + right_sum