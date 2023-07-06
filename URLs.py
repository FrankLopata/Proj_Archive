from urllib.parse import urljoin
import urllib.request


def command_func(valid_com: list):
    print("Please input a command:")
    command = input()
    for i in valid_com:
        loc = i.split(":")
        com = loc[0].split(",")
        for x in com:
            if(command.lower == x.lower):
                return loc[1]

def readurl(url: str,location: str):
    try:
        request = urllib.request.Request(urljoin(url,location))
        response = urllib.request.urlopen(request)
        file = response.read()
        response.close()
        text = file.decode(encoding = 'utf-8')
        text = text.splitlines()
        if "TEXT" in text[0] and len(text[0] > 4):
            title = text[0]
            print(title[5:])
            if(text[1] == "DESCRIPTION" and text[2] != "END DESCRIPTION"):
                index = 2
                while index < len(text) and text[index] != "END DESCRIPTION":
                    print(text[index])
                    index = index + 1
                index = index + 1  
                if(text[index]=="COMMANDS" and text[index + 1] != "END COMMANDS"):
                    print("Commands:")
                    index = index + 1
                    valid_com = []
                    for i in text[index:]:
                        if(i=="END COMMANDS"):
                            break
                        valid_com.append(i)
                        print(i)
                    return command_func(valid_com)
                elif(text[len(text)] == "GAME OVER"):
                    print("GAME OVER")
                    return "GAME OVER"
                                             
        print("Invalid URL")
        return
    except:
        print("Invalid URL")
        return


if __name__ == '__main__':
    print("please input base URL :")
    url = input()
    loc = readurl(url,"start.dat")
    markofdeath=1
    while(markofdeath == 1):
       loc = readurl(url,loc)
       if(loc == "GAME OVER"):
           markofdeath = 0 





    