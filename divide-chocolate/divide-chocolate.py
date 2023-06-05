class Solution:
    def maximizeSweetness(self, sweetness: List[int], k: int) -> int:
        num_of_people = k + 1
        left, right = min(sweetness), sum(sweetness) // num_of_people
        
        while left <= right:
            mid = (left + right + 1) // 2
            cur_sweetness, people_with_chocolate = 0, 0
            
            for s in sweetness:
                cur_sweetness += s
                
                if cur_sweetness >= mid:
                    people_with_chocolate += 1
                    cur_sweetness = 0
                
            if people_with_chocolate >= num_of_people:
                left = mid + 1
            else:
                right = mid - 1
        
        return right
        