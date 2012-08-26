import re
import zipfile

pattern = r'\d+$'

num = '90052'

comments = []

f = zipfile.ZipFile('channel.zip')

while (num):
    comment = f.getinfo('%s.txt' % num).comment
    comment = comment.decode('GBK')
    comments.append(comment)
    result = f.read('%s.txt' % num)
    print(result)
    result = result.decode('GBK')
    num = ''.join(re.findall(pattern, result))

print(''.join(comments))
