class Solution:
    def partition(self, left: int, right: int, pivot_index: int) -> int:
        pivot_frequency = self.counts[self.unique[pivot_index]]
        
        self.unique[pivot_index], self.unique[right] = self.unique[right], self.unique[pivot_index]
        
        store_index = left
        for i in range(left, right):
            if self.counts[self.unique[i]] < pivot_frequency:
                self.unique[store_index], self.unique[i] = self.unique[i], self.unique[store_index]
                store_index += 1
        self.unique[right], self.unique[store_index] = self.unique[store_index], self.unique[right]
        return store_index
    
    def quickselect(self, left: int, right: int, k_smallest: int) -> None:
        if left == right:
            return
        
        pivot_index = random.randint(left, right)
        pivot_index = self.partition(left, right, pivot_index)
        
        if k_smallest == pivot_index:
            return
        
        elif k_smallest < pivot_index:
            self.quickselect(left, pivot_index - 1, k_smallest)
        else:
            self.quickselect(pivot_index + 1, right, k_smallest)
    
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        self.counts = Counter(nums)
        self.unique = list(self.counts.keys())
        
        n = len(self.unique)
        self.quickselect(0, n - 1, n - k)
        return self.unique[n - k:]