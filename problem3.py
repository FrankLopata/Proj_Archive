import urllib.request

def webcrawler(path: str)->list:
    request = urllib.request.Request(path)
    response = urllib.request.urlopen(request)
    file = response.read()
    response.close()
    text = file.decode(encoding = 'utf-8')
    text = text.split('\n')
    dir =  path.rsplit("/",1)
    dir = dir[0] + "/"
    output = []
    output.append(path)
    for lines in text:
        if lines[0:4]=="LINK":
            pathway = dir + lines[5:]
            output.append(webcrawler(pathway))
    return output

