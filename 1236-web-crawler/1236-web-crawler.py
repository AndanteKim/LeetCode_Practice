# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        def dfs(url: str) -> None:
            if url in visited:
                return
            
            visited.add(url)
            checks1 = url.split('/')
            branches = htmlParser.getUrls(url)
            for branch in branches:
                checks2 = branch.split('/')
                if checks1[2] != checks2[2]:
                    continue
                dfs(branch)
        
        visited = set()
        dfs(startUrl)
        return list(visited)