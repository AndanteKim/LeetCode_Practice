class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        pairs = []
        
        for n, h in zip(names, heights):
            pairs.append((n, h))
        
        pairs.sort(key = lambda x: -x[1])
        
        return [n for n, h in pairs]