class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        max_element, ans = max(nums), 0
        indices_of_max_elements = []
        
        for i in range(len(nums)):
            if nums[i] == max_element:
                indices_of_max_elements.append(i)
            
            freq = len(indices_of_max_elements)
            if freq >= k:
                ans += indices_of_max_elements[-k] + 1
            
        return ans