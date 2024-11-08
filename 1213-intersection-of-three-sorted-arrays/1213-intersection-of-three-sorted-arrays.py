class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        ans = []
        
        # Concatenate them together
        counter = Counter(arr1 + arr2 + arr3)
        
        for item in counter:
            if counter[item] == 3:
                ans.append(item)
                
        return ans