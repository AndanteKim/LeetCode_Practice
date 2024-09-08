class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        slots1.sort()
        slots2.sort()
        
        i, j = 0, 0
        m, n = len(slots1), len(slots2)
        
        while i < m and j < n:
            # Find the boundaries of the intersection, or the common slot
            intersect_r = min(slots1[i][1], slots2[j][1])
            intersect_l = max(slots1[i][0], slots2[j][0])
            
            if intersect_r - intersect_l >= duration:
                return [intersect_l, intersect_l + duration]
            
            # Always move the one ending earlier
            if slots1[i][1] < slots2[j][1]:
                i += 1
            else:
                j += 1
                
        return []