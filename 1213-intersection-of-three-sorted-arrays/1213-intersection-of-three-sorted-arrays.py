class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        def looping(arr: List[int]) -> None:
            for num in arr:
                counting_sort[num] += 1
        counting_sort = [0] * 2001
        looping(arr1)
        looping(arr2)
        looping(arr3)
        
        ans = []
        for i in range(1, 2001):
            if counting_sort[i] == 3:
                ans.append(i)
        
        return ans 