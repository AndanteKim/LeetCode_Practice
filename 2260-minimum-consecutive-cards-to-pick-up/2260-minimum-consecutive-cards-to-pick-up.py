class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        dic = defaultdict(list)
        for i in range(len(cards)):
            dic[cards[i]].append(i)
            
        ans = float('inf')
        for key in dic:
            arr = dic[key]
            for i in range(len(arr)-1):
                ans = min(ans, arr[i+1] - arr[i] + 1)
        return -1 if ans == float('inf') else ans