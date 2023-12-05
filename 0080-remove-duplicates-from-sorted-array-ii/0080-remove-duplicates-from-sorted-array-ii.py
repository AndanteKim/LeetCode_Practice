class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Initialize the counte and the second pointer
        j, count = 1, 1
        
        # Start from the second element of the array and process element one by one
        for i in range(1, len(nums)):
            # If the current element is a duplicate,
            # increment the count
            if nums[i] == nums[i - 1]:
                count += 1
            else:
                # Reset the count since we encountered a different element
                # than the previous one
                count = 1
        
            # For a count <= 2, we copy the element over thus
            # overwriting the element at index "j" in the array
            if count <= 2:
                nums[j] = nums[i]
                j += 1
        
        return j
        
        