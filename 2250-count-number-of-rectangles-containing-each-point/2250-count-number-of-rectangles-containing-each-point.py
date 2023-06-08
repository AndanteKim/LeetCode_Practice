class Solution:
    def countRectangles(self, rectangles: List[List[int]], points: List[List[int]]) -> List[int]:
        ans = []
        rectangles_sort = defaultdict(list)
        
        for length, height in rectangles:
            rectangles_sort[height].append(length)
        
        for height, lengths in rectangles_sort.items():
            rectangles_sort[height].sort()
        
        for x_i, y_i in points:
            curr = 0
            
            for height, lengths in rectangles_sort.items():
                if height >= y_i:
                    left, right = 0, len(lengths)
                    
                    while left < right:
                        mid = (left + right) // 2
                        x_j = rectangles_sort[height][mid]
                        
                        if x_i <= x_j:
                            right = mid
                        else:
                            left = mid + 1

                    curr += len(lengths) - left
            
            ans.append(curr)
            
        
        return ans
                    