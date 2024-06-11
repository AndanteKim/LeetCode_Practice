class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        count_sort, ans = [0] * (max(arr1) + 1), []
        for e1 in arr1:
            count_sort[e1] += 1
        
        for e2 in arr2:
            while count_sort[e2] > 0:
                ans.append(e2)
                count_sort[e2] -= 1
                
        for i in range(len(count_sort)):
            while count_sort[i] > 0:
                ans.append(i)
                count_sort[i] -= 1
        
        return ans