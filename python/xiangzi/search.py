import urllib   
import re   
class SearchThief:   
    " " "the google thief " " "   
    global path,targetURL   
    path = "pages\\ "   
    # targetURL = "http://www.google.cn/search?complete=1&hl=zh-CN&q= "   
    targetURL = "http://www.baidu.com/s?wd= "   
    def __init__(self,key):   
        self.key = key   
    def getPage(self):   
        webStr = urllib.urlopen(targetURL+self.key).read() # get the page string form the url   
        self.setPageToFile(webStr)   
    def setPageToFile(self,webStr):   
        reSetStr = re.compile( "\r ")   
        self.key = reSetStr.sub( " ",self.key) # replace the string "\r "   
        targetFile = file(path+self.key+ ".html ", "w ") # open the file for "w "rite   
        targetFile.write(webStr)   
        targetFile.close()   
        print "done "   

inputKey = raw_input( "Enter you want to search --> ")   
obj = SearchThief(inputKey)   
obj.getPage() 
