class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def generate_subsets(i: int, subset: List[int], subsets: List[List[int]]) -> None:
            # Base case: index reached end of nums
            # Add the current subset to subsets
            if i == len(nums):
                subsets.append(subset[:])
                return
            
            # Generate subsets with nums[i]
            subset.append(nums[i])
            generate_subsets(i + 1, subset, subsets)
            subset.pop()
            
            # Generate subsets without nums[i]
            generate_subsets(i + 1, subset, subsets)
            
        # Generate all of the subsets
        subsets = []
        generate_subsets(0, [], subsets)
        
        # Compute the XOR total for each subset and add to the result
        ans = 0
        
        for subset in subsets:
            subset_XOR_total = 0
            for num in subset:
                subset_XOR_total ^= num
            ans += subset_XOR_total
            
        return ans