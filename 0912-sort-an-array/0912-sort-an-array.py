class Solution:
    def radix_sort(self, nums: List[int]) -> List[int]:
        max_element = nums[0]
        
        for val in nums:
            max_element = max(abs(val), max_element)
        
        max_digits = 0
        while max_element > 0:
            max_digits += 1
            max_element //= 10
        
        place_value = 1
        
        def bucket_sort():
            buckets = [[] for i in range(10)]
            for val in nums:
                digit = abs(val) / place_value
                digit = int(digit % 10)
                buckets[digit].append(val)
            
            index = 0
            for digit in range(10):
                for val in buckets[digit]:
                    nums[index] = val
                    index += 1
        
        for _ in range(max_digits):
            bucket_sort()
            place_value *= 10
        
        positives = [val for val in nums if val >= 0]
        negatives = [val for val in nums if val < 0]
        negatives.reverse()
        return negatives + positives
        
    
    def sortArray(self, nums: List[int]) -> List[int]:
        return self.radix_sort(nums)