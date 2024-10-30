class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        def getLS(v: List[int]) -> List[int]:
            lis_len = [1] * len(v)
            lis = [v[0]]
            
            for i in range(1, len(v)):
                idx = bisect_left(lis, v[i])
                
                # Add to the list if v[i] is greater than the last element
                if idx == len(lis):
                    lis.append(v[i])
                else:
                    # Replace the element at index with v[i]
                    lis[idx] = v[i]
                
                lis_len[i] = len(lis)
                
            return lis_len
            
        n = len(nums)
        
        lis_len = getLS(nums)
        
        nums = nums[::-1]
        # Reverse the length array to correctly depic the length of longest decreasing subsequence for each index.
        lds_len = getLS(nums)
        lds_len.reverse()
        
        min_removals = float("inf")
        for i in range(n):
            if lis_len[i] > 1 and lds_len[i] > 1:
                min_removals = min(min_removals, n - (lis_len[i] + lds_len[i] - 1))
        
        return min_removals