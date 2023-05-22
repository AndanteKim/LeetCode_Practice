class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key = lambda x: (-x[1], -x[0]))
        ans, curr_boxes = 0, 0
        
        for boxes, units in boxTypes:
            if curr_boxes + boxes < truckSize:
                ans += boxes * units
                curr_boxes += boxes
            else:
                ans += (truckSize - curr_boxes) * units
                break
        
        return ans