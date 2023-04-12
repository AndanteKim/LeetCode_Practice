class Solution:
    def simplifyPath(self, path: str) -> str:
        path = re.sub("[/]+", "/", path)
        
        last_path = ""
        while last_path != path:
            last_path = path
            path = re.sub("/[.]/", "/", path)
        
        path = re.sub("^[.]/", "/", path)
        path = re.sub("/[.]$", "/", path)
        
        path = re.sub("/$", "", path)
        
        path = re.sub("^/", "", path)
        
        path_stack = []
        for frag in path.split('/'):
            if frag != "..":
                path_stack.append(frag)
            elif path_stack:
                path_stack.pop()
        
        return "/" + "/".join(path_stack)