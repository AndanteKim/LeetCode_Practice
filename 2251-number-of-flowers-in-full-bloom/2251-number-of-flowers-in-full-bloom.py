class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        positions = set()
        
        for start, end in flowers:
            positions.add(start)
            positions.add(end + 1)
            
        positions = sorted(list(positions))
        
        idx = {positions[i] : i for i in range(len(positions))}
        tmp = [0] * (1 + len(positions))
        
        for start, end in flowers:
            tmp[idx[start]] += 1
            tmp[idx[end + 1]] -= 1
            
        prefix_sum = [0] * (1 + len(positions))
        
        for i in range(len(positions)):
            prefix_sum[i + 1] = prefix_sum[i] + tmp[i]
        
        ans = []
        
        for person in people:
            idx = bisect_right(positions, person)
            ans.append(prefix_sum[idx])
        
        return ans