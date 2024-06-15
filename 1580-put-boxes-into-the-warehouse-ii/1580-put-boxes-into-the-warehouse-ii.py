class Solution:
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:
        n = len(warehouse)
        min_height = float('inf')
        effective_heights = [0] * n
        
        # Preprocess the height of the warehouse rooms to
        # get usable heights from the left end
        
        for i in range(n):
            min_height = min(min_height, warehouse[i])
            effective_heights[i] = min_height
        
        min_height = float('inf')
        
        # Update the effective heights considering the right end
        for i in range(n - 1, -1, -1):
            min_height = min(min_height, warehouse[i])
            effective_heights[i] = max(effective_heights[i], min_height)
            
        # Sort the effective heights of the warehouse rooms
        effective_heights.sort()
        
        # Sort the boxes by height
        boxes.sort()
        
        ans, box_idx = 0, 0
        
        # Try to place each box in the warehouse from
        # the smallest room to the largest
        for i in range(n):
            if box_idx < len(boxes) and boxes[box_idx] <= effective_heights[i]:
                # Place the box and move to the next one
                ans += 1
                box_idx += 1
        
        return ans