class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        n, min_heap = len(classes), []

        for numerator, denominator in classes:
            ratio, next_ratio = numerator / denominator, (numerator + 1) / (denominator + 1)
            heappush(min_heap, (-(next_ratio - ratio), numerator, denominator))
        
        for _ in range(extraStudents):
            _, numerator, denominator = heappop(min_heap)
            numerator += 1
            denominator += 1
            ratio, next_ratio = numerator / denominator, (numerator + 1) / (denominator + 1)
            heappush(min_heap, (-(next_ratio - ratio), numerator, denominator))
        
        total_avg = 0.0
        while min_heap:
            _, numerator, denominator = heappop(min_heap)
            total_avg += numerator / denominator
        
        return total_avg / n