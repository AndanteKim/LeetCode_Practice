class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        freq1, freq2, union = defaultdict(int), defaultdict(int), set()
        
        for num in nums1:
            freq1[num] += 1
            union.add(num)
        
        for num in nums2:
            freq2[num] += 1
            union.add(num)
            
        ans = []
        for n in union:
            for _ in range(min(freq1[n], freq2[n])):
                ans.append(n)
                
        return ans
        
        
            
        