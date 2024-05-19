class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        n = len(nums)
        net_change = [(nums[i] ^ k) - nums[i] for i in range(n)]
        node_sum = sum(nums)
        
        net_change.sort(reverse = True)
        
        for i in range(0, n, 2):
            # If net_change coins odd number of elements break the loop
            if i + 1 == n:
                break
                
            pair_sum = net_change[i] + net_change[i + 1]
            
            # Include in node_sum if pair_sum is positive
            if pair_sum > 0:
                node_sum += pair_sum
                
        return node_sum
        