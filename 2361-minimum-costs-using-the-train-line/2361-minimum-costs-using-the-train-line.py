class Solution:
    def minimumCosts(self, regular: List[int], express: List[int], expressCost: int) -> List[int]:
        n = len(regular)
        prev_regular_lane = 0
        prev_express_lane = expressCost
        
        ans = []
        
        for i in range(1, n + 1):
            regular_lane_cost = regular[i - 1] + min(prev_regular_lane, prev_express_lane)
            express_lane_cost = express[i - 1] + min(prev_regular_lane + expressCost, prev_express_lane)
            ans.append(min(regular_lane_cost, express_lane_cost))
            
            prev_regular_lane = regular_lane_cost
            prev_express_lane = express_lane_cost
        
        return ans