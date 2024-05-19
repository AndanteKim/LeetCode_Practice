class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        sum_val, count = 0, 0
        pos_min = 1 << 30
        neg_max = -1 * (1 << 30)
        
        for node_val in nums:
            operated = node_val ^ k
            sum_val += node_val
            net_change = operated - node_val
            
            if net_change > 0:
                pos_min = min(pos_min, net_change)
                sum_val += net_change
                count += 1
                
            else:
                neg_max = max(neg_max, net_change)
                
        # If the number of postive net_change values is even, return the sum.
        if count % 2 == 0:
            return sum_val
        
        # Otherwise return the maximum of both discussed cases.
        return max(sum_val - pos_min, sum_val + neg_max)