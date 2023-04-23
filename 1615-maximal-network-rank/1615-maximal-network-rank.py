class Solution:   
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        degrees = [0] * n
        
        for start, end in roads:
            degrees[start] += 1
            degrees[end] += 1
        
        first, second = 0, 0
        for degree in degrees:
            if degree > first:
                second, first = first, degree
            elif degree == first:
                continue
            elif degree > second:
                second = degree
        
        first_count, second_count = 0, 0
        for degree in degrees:
            if degree == first:
                first_count += 1
            elif degree == second:
                second_count += 1
        
        if first_count == 1:
            count = 0
            for start, end in roads:
                if degrees[start] == first and degrees[end] == second:
                    count += 1
                elif degrees[end] == first and degrees[start] == second:
                    count += 1
            return first + second - (0 if second_count > count else 1)
        else:
            count = 0
            for start, end in roads:
                if degrees[start] == first and degrees[end] == first:
                    count += 1
            return first + first - (0 if (first_count * (first_count - 1) / 2) > count else 1)