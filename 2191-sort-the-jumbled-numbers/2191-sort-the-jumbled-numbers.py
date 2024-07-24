class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        store_pairs = []
        
        for i in range(len(nums)):
            mapped_value, temp = 0, nums[i]
            
            # Start making changes from the units place.
            place = 1
            # If the value initially is 0, return mapping[0] and index.
            if temp == 0:
                store_pairs.append((mapping[0], i))
                continue
                
            # Repeat the process for units, tenths, hundredths.. places.
            while temp != 0:
                mapped_value = place * mapping[temp % 10] + mapped_value
                place *= 10
                temp //= 10
                
            store_pairs.append((mapped_value, i))
            
        # Sort the array in non-decreasing order by the first value (default).
        store_pairs.sort()
        return [nums[pair[1]] for pair in store_pairs]