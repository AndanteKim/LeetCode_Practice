class Solution:
    def pathSum(self, nums: List[int]) -> int:
        # Base case
        if not nums:
            return 0
        
        # BFS
        tree = dict()
        
        # Store the data in hashmap, with the coordinates as key and the node value as the value.
        for num in nums:
            tree[num // 10] = num % 10
            
        ans, queue = 0, deque([(nums[0] // 10, 0)])
        
        while queue:
            root_position, pre_sum = queue.popleft()
            
            level, position = root_position // 10, root_position % 10
            curr_sum = pre_sum + tree[root_position]
            
            left, right = (level + 1) * 10 + 2 * position - 1, (level + 1) * 10 + 2 * position
            
            # If it 's a leaf node (no left and right children), add the current sum to the answer
            if not (left in tree or right in tree):
                ans += curr_sum
                continue
                
            # Add the left child to the queue if it exists.
            if left in tree:
                queue.append((left, curr_sum))
                
            # Add the right child to the queue if it exists.
            if right in tree:
                queue.append((right, curr_sum))
                
        return ans
        