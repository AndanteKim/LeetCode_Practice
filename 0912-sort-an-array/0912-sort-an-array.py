class Solution:
    def heapify(self, arr: List[int], n: int, i: int) -> None:
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2
        
        if left < n and arr[left] > arr[largest]:
            largest = left
        
        if right < n and arr[right] > arr[largest]:
            largest = right
        
        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            self.heapify(arr, n, largest)
        
    def heapSort(self, arr: List[int]) -> None:
        n = len(arr)
        for i in range(n//2 - 1, -1, -1):
            self.heapify(arr, n, i)
        
        for i in range(n-1, -1, -1):
            arr[0], arr[i] = arr[i], arr[0]
            self.heapify(arr, i, 0)
    
    def sortArray(self, nums: List[int]) -> List[int]:
        self.heapSort(nums)
        return nums