class Solution:
    def findLucky(self, arr: List[int]) -> int:
        max_lucky = -1
        
        for key, val in Counter(arr).items():
            if key == val:
                max_lucky = max(max_lucky, key)
        
        
        
        return max_lucky