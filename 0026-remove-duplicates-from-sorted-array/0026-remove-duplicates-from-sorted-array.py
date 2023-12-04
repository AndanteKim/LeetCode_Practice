class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n, insert_index = len(nums), 1
        
        for i in range(1, n):
            # Found unique element
            if nums[i - 1] != nums[i]:
                # Updating insert_index in our main array
                nums[insert_index] = nums[i]
                # Incrementing insert_index count by 1
                insert_index += 1
        
        return insert_index