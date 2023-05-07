class Solution:
    def partition(self, left: int, right: int, pivot_index: int, nums: List[int]) -> int:
        pivot = nums[pivot_index]
        nums[pivot_index], nums[right] = nums[right], nums[pivot_index]
        
        store_index = left
        for i in range(left, right):
            if nums[i] < pivot:
                nums[store_index], nums[i] = nums[i], nums[store_index]
                store_index += 1
        
        nums[right], nums[store_index] = nums[store_index], nums[right]
        
        return store_index
    
    def select(self, left: int, right: int, k_smallest: int, nums: List[int]) -> int:
        if left == right:
            return nums[left]
        
        pivot_index = randint(left, right)
        
        pivot_index = self.partition(left, right, pivot_index, nums)
        
        if k_smallest == pivot_index:
            return nums[k_smallest]
        elif k_smallest < pivot_index:
            return self.select(left, pivot_index - 1, k_smallest, nums)
        else:
            return self.select(pivot_index + 1, right, k_smallest, nums)
    
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.select(0, len(nums) - 1, len(nums) - k, nums)