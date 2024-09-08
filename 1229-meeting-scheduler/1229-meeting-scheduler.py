class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        # Build up a heap containing time slots last longer than duration
        timeslots = list(filter(lambda x: x[1] - x[0] >= duration, slots1 + slots2))
        heapify(timeslots)
        
        while len(timeslots) > 1:
            s1, e1 = heappop(timeslots)
            s2, e2 = timeslots[0]
            
            if e1 >= s2 + duration:
                return [s2, s2 + duration]
            
        return []