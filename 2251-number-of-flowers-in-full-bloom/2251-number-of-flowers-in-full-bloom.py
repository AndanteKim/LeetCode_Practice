class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        flowers.sort()
        sorted_people = sorted(people)
        heap, dic = [], dict()
        
        i = 0
        for t in sorted_people:
            while i < len(flowers) and flowers[i][0] <= t:
                heappush(heap, flowers[i][1])
                i += 1
            
            while heap and heap[0] < t:
                heappop(heap)
            
            dic[t] = len(heap)
        
        return [dic[person] for person in people]