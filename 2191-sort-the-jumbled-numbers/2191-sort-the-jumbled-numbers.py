class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        store_pairs = []
        
        for i in range(len(nums)):
            # Convert current value to string
            num = str(nums[i])
            formed = ""
            
            for j in range(len(num)):
                formed += str(mapping[int(num[j])])
            
            # Store the mapped value.
            mapped_value = int(formed)
            # Push a pair consisting of mapped value and original value's index.
            store_pairs.append((mapped_value, i))
            
        # Sort the array in non-decreasing order by the first value (default).
        store_pairs.sort()
        
        return [nums[pair[1]] for pair in store_pairs]
        