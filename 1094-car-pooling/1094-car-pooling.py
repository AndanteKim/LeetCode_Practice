class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort(key = lambda x: x[2])
        status = [0] * (trips[-1][2] + 1)
        for n, start, end in trips:
            for day in range(start, end):
                if status[day] + n > capacity:
                    return False
                status[day] += n
                
        return True