class Solution:
    def merge(self, arr: List[int], left: int, mid: int, right: int, tempArr: List[int]) -> None:
        start1 = left
        start2 = mid + 1
        n1 = mid - left + 1
        n2 = right - mid
        
        for i in range(n1):
            tempArr[start1 + i] = arr[start1 + i]
        
        for i in range(n2):
            tempArr[start2 + i] = arr[start2 + i]
        
        i = j = 0
        k = left
        
        while (i < n1 and j < n2):
            if tempArr[start1 + i] <= tempArr[start2 + j]:
                arr[k] = tempArr[start1 + i]
                i += 1
            else:
                arr[k] = tempArr[start2 + j]
                j += 1
            k += 1
            
        while i < n1:
            arr[k] = tempArr[start1 + i]
            i += 1
            k += 1
        
        while j < n2:
            arr[k] = tempArr[start2 + j]
            j += 1
            k += 1
            
    
    def mergeSort(self, arr: List[int], left: int, right: int, tempArr: List[int]) -> None:
        if left >= right: return;
        
        mid = left + (right - left) // 2
        self.mergeSort(arr, left, mid, tempArr)
        self.mergeSort(arr, mid + 1, right, tempArr)
        self.merge(arr, left, mid, right, tempArr)
    
    def sortArray(self, nums: List[int]) -> List[int]:
        tempArray = [0] * len(nums)
        self.mergeSort(nums, 0, len(nums) - 1, tempArray)
        return nums
        