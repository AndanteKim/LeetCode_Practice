class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        # Hint: two pointer and sort
        i, j = 0, 0
        m, n = len(slots1), len(slots2)
        
        slots1.sort()
        slots2.sort()
        
        while i < m and j < n:
            if slots1[i][1] < slots2[j][0]:
                i += 1
            elif slots2[j][1] < slots1[i][0]:
                j += 1
            else:
                if duration <= min(slots1[i][1], slots2[j][1]) - max(slots1[i][0], slots2[j][0]):
                    return [max(slots1[i][0], slots2[j][0]), max(slots1[i][0], slots2[j][0]) + duration]
                elif i + 1 < m and slots1[i + 1][0] + duration <= slots1[i + 1][1] and slots1[i + 1][0] + duration <= slots2[j][1]:
                    i += 1
                elif j + 1 < n and slots2[j + 1][0] + duration <= slots1[i][1] and slots2[j + 1][0] + duration <= slots2[j + 1][1]:
                    j += 1
                else:
                    i += 1
                    j += 1
        
        
        # If there's no answer
        return []