import urllib.request
import re

pattern = r'\d+$'

num = '12345'

while (num) :
    f = urllib.request.urlopen('http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing=%s'% num)
    result = f.read()
    f.close()
    print(result)
    result = result.decode('GBK')
    num = ''.join(re.findall(pattern, result))
