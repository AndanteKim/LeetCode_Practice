class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        prefix_sum = [0] * (len(travel) + 1)
        prefix_sum[1] = travel[0];
        for i in range(1, len(travel)):
            prefix_sum[i + 1] = prefix_sum[i] + travel[i]
        
        # map to store garbage type to the last house index
        garbage_last_pos = dict();
        
        # map to store the total count of each type of garbage in all houses
        garbage_count = dict()
        for i in range(len(garbage)):
            for c in garbage[i]:
                garbage_last_pos[c] = i;
                garbage_count[c] = garbage_count.get(c, 0) + 1
                
        ans = 0
        for c in ('M', 'P', 'G'):
            # add only if there is at least one unit of this garbage
            if garbage_count.get(c, 0) > 0:
                ans += prefix_sum[garbage_last_pos[c]] + garbage_count.get(c, 0)
        
        return ans
        
        
        