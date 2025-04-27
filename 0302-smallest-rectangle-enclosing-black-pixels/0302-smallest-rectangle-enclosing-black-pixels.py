class Solution:
    def minArea(self, image: List[List[str]], x: int, y: int) -> int:
        def _search_col(i: int, j: int, top: int, bot: int, white2black: bool) -> int:
            while i != j:
                k, mid = top, (i + j) >> 1

                while k < bot and image[k][mid] == '0':
                    k += 1
                # k < bot means the column mid has black pixel
                if (k < bot) == white2black:
                    j = mid # Search the boundary in the smaller half
                else:
                    i = mid + 1
            return i
        
        def _search_row(i: int, j: int, left: int, right: int, white2black: bool) -> int:
            while i != j:
                k, mid = left, (i + j) >> 1

                while k < right and image[mid][k] == '0':
                    k += 1
                
                # k < right means the row mid has black pixel
                if (k < right) == white2black:
                    j = mid
                else:
                    i = mid + 1
            return i

        m, n = len(image), len(image[0])
        left = _search_col(0, y, 0, m, True)
        right = _search_col(y + 1, n, 0, m, False)
        top = _search_row(0, x, left, right, True)
        bot = _search_row(x + 1, m, left, right, False)
        return (right - left) * (bot - top)