class BrowserHistory:

    def __init__(self, homepage: str):
        self._history, self._future = [], []
        self._current = homepage
        

    def visit(self, url: str) -> None:
        self._history.append(self._current)
        self._current = url
        self._future = []

    def back(self, steps: int) -> str:
        while steps > 0 and self._history:
            self._future.append(self._current)
            self._current = self._history.pop()
            steps -= 1
        return self._current

    def forward(self, steps: int) -> str:
        while steps > 0 and self._future:
            self._history.append(self._current)
            self._current = self._future.pop()
            steps -= 1
        return self._current


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)