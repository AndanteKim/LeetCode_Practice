class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        for i in range(1, len(travel)):
            travel[i] = travel[i - 1] + travel[i]
        
        garbage_last_pos, ans = dict(), 0
        
        for i in range(len(garbage)):
            for c in garbage[i]:
                garbage_last_pos[c] = i
            ans += len(garbage[i])
        
        for c in ('M', 'G', 'P'):
            # No travel time is required if the last house is at index 0
            ans += (0 if garbage_last_pos.get(c, 0) == 0 else travel[garbage_last_pos[c] - 1])
        
        return ans