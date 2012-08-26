import urllib.request
import pickle

f = urllib.request.urlopen('http://www.pythonchallenge.com/pc/def/banner.p')

result = pickle.Unpickler(f).load()

line = ''
for n in result:
    for m in n:
        line += m[0] * m[1]
    print(line + '\n')
    line = ''
