class Excel:
    class Formula:
        def __init__(self, cells: Dict[str, int], val: int):
            self.cells = cells  # dict: {cell_name: count}
            self.val = val

    def __init__(self, height: int, width: str):
        self.Formulas = [[None] * (ord(width) + 1 - 65) for _ in range(height)]
        self.st = []

    def set(self, row: int, column: str, val: int) -> None:
        self.Formulas[row - 1][ord(column) - 65] = self.Formula(dict(), val)
        self.topological_sort(row - 1, ord(column) - 65)
        self.execute_st()

    def get(self, row: int, column: str) -> int:
        if not self.Formulas[row - 1][ord(column) - 65]:
            return 0

        return self.Formulas[row - 1][ord(column) - 65].val

    def sum(self, row: int, column: str, numbers: List[str]) -> int:
        cells = self.convert(numbers)
        total = self.calculate_sum(row - 1, ord(column) - 65, cells)
        self.set(row, column, total)
        self.Formulas[row - 1][ord(column) - 65] = self.Formula(cells, total)
        return total

    def topological_sort(self, r: int, c: int) -> None:
        for i in range(len(self.Formulas)):
            for j in range(len(self.Formulas[0])):
                if self.Formulas[i][j] is not None and self.Formulas[i][j].cells and \
                f"{chr(65 + c)}{r + 1}" in self.Formulas[i][j].cells:
                    self.topological_sort(i, j)
        self.st.append([r, c])

    def execute_st(self) -> None:
        while self.st:
            top = self.st.pop()
            if self.Formulas[top[0]][top[1]] and self.Formulas[top[0]][top[1]].cells:
                self.calculate_sum(top[0], top[1], self.Formulas[top[0]][top[1]].cells)

    def convert(self, strs: List[str]) -> Dict[str, int]:
        ans = dict()
        
        for st in strs:
            if ":" not in st:
                ans[st] = ans.get(st, 0) + 1
            else:
                cells = st.split(":")
                si = int(cells[0][1:])
                ei = int(cells[1][1:])
                sj = cells[0][0]
                ej = cells[1][0]

                for i in range(si, ei + 1):
                    for j_ch in range(ord(sj), ord(ej) + 1):
                        cell_nm = f"{chr(j_ch)}{i}"
                        ans[cell_nm] = ans.get(cell_nm, 0) + 1
        return ans

    def calculate_sum(self, r: int, c: int, cells: Dict[str, int]) -> int:
        total = 0

        for s, cnt in cells.items():
            x = int(s[1:]) - 1
            y = ord(s[0]) - 65
            cell_val = self.Formulas[x][y].val if self.Formulas[x][y] else 0
            total += cell_val * cnt
        self.Formulas[r][c] = self.Formula(cells, total)
        return total

# Your Excel object will be instantiated and called as such:
# obj = Excel(height, width)
# obj.set(row,column,val)
# param_2 = obj.get(row,column)
# param_3 = obj.sum(row,column,numbers)