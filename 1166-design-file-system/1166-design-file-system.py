class FileSystem:

    def __init__(self):
        self.paths = defaultdict()

    def createPath(self, path: str, value: int) -> bool:
        # Step-1: basic path validations
        if path == "/" or len(path) == 0 or path in self.paths:
            return False
        
        # Step-2: If the parent doesn't exist. Note that "/" is a valid parent.
        parent = path[:path.rfind('/')]
        if len(parent) > 1 and parent not in self.paths:
            return False

        # Step-3: add this new npath and return true.
        self.paths[path] = value
        return True

    def get(self, path: str) -> int:
        return self.paths.get(path, -1)


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.createPath(path,value)
# param_2 = obj.get(path)