class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        # Find the max element of nums
        max_element = max(nums)
        ans = left = max_elements_in_window = 0
        
        for right in range(len(nums)):
            # When the value of nums[right] is the max element
            if nums[right] == max_element:
                max_elements_in_window += 1
            
            # Count the number of subarrays until the frequency of max element is equal to k
            while max_elements_in_window == k:
                if nums[left] == max_element:
                    max_elements_in_window -= 1
                left += 1
            ans += left
        
        return ans