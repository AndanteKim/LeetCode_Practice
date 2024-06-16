class Solution:
    def maxBoxesInWarehouse(self, boxes: List[int], warehouse: List[int]) -> int:
        # sort boxes by height
        boxes.sort()
        warehouse_sz = len(warehouse)
        left_idx, right_idx = 0, warehouse_sz - 1
        box_count, box_idx = 0, len(boxes) - 1
        
        # Iterate through the boxes from the largest to smallest
        while left_idx <= right_idx and box_idx >= 0:
            # Check if the current box can fit in the
            # leftmost available room
            if boxes[box_idx] <= warehouse[left_idx]:
                box_count += 1
                left_idx += 1
                
            # Check if the current box can fit in the
            # rightmost available room
            elif boxes[box_idx] <= warehouse[right_idx]:
                box_count += 1
                right_idx -= 1
            box_idx -= 1 
        
        return box_count