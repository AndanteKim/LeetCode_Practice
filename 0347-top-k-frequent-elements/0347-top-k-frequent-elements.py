class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hash_table = defaultdict(int)
        for num in nums:
            hash_table[num] += 1
        
        ans = []
        
        for num in hash_table:
            ans.append((num, hash_table[num]))
            
        ans.sort(key = lambda x: -x[1])
            
        return [num for num, freq in ans][:k]