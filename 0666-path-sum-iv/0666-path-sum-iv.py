class Solution:
    def pathSum(self, nums: List[int]) -> int:
        def dfs(root_pos: int, pre_sum: int) -> int:
            # Find the level and position values from the root position
            level = root_pos // 10
            pos = root_pos % 10
            
            # Find out the left child and right child positions of the tree.
            left = (level + 1) * 10 + pos * 2 - 1
            right = (level + 1) * 10 + pos * 2
            
            curr_sum = pre_sum + tree[root_pos]
            
            # If left child and right child don't exist, return.
            if not (left in tree or right in tree):
                return curr_sum
            
            # Otherwise, iterate through the left and right children recursively using depth first search
            left_sum = dfs(left, curr_sum) if left in tree else 0
            right_sum = dfs(right, curr_sum) if right in tree else 0
            
            return left_sum + right_sum
        
        if not nums:
            return 0
        
        # Store the data in a hashmap, with the coordinates as the key and the node value as the value
        tree = dict()
        
        for num in nums:
            pos = num // 10
            val = num % 10
            tree[pos] = val
        
        return dfs(nums[0] // 10, 0)