
class Locator:
    def __init__(self, srl : str):
        
        self._srl = srl
        try:
            index = 0
            while index < len(srl):
                if(srl[index]==srl[index].lower()):
                    if(srl[index:index+3]=="://"):
                        if(srl[index + 3] == "."):
                            return ValueError
                        break
                else:
                    return ValueError
                index = index + 1
            index = index + 3
            while index < len(srl):
                if(srl[index].isalpha==False and srl[index].isdigit()==False):
                    if(srl[index]=="/" and srl[index-1]=="."):
                        return ValueError
                    if(srl[index]=="/" and srl[index+1]=="."):
                        return ValueError
                    if(srl[index]!= "/" or "."):
                            return ValueError
                index = index + 1
            return
        except Exception as e :
            return e

    def srl(self) -> str:
        return self._srl

    def kind(self) -> str:
        kind = ""
        for i in self._srl:
            if i == ":" :
                break
            kind= kind + i
        return kind

    def location(self) -> str:
        start = self._srl.index("://")+3
        fin = self._srl[start:len(self._srl)].index("/") + start
        return self._srl[start:fin]
    
    def location_parts(self) -> list[str] :
        loc = ""
        start = self._srl.index("://")+3
        fin = self._srl[start:len(self._srl)].index("/") + start
        loc = self._srl[start:fin]
        return loc.split(".")
      

    def resource(self):
        checkmark = 0
        index = 0
        for i in self._srl:
            index = index + 1
            if(checkmark == 3):
                break
            if(i=="/"):
                checkmark =  checkmark + 1
        return self._srl[index-1:len(self._srl)]

    def resource_parts(self) -> list[str]:
        
        checkmark = 0
        index = 0
        for i in self._srl:
            index = index + 1
            if(checkmark == 3):
                break
            if(i=="/"):
                checkmark =  checkmark + 1
        parts =self._srl[index-1:len(self._srl)]
        return parts.split("/")

    def parent(self) -> 'Locator':
        slash = 0
        index  = 0
        while index < len(self._srl):
            if self._srl[index] == "/":
                slash = index
            index = index +1
        return self._srl[0:slash]
               
    def within(self, resource_part: str) -> 'Locator':
        return self._srl + "/" + resource_part
    

def test_srl():
    loc = Locator("https://www.ics.uci.edu/thornton/ics32a/Exercises/Set4/index.html")
    assert Locator.srl(loc) == "https://www.ics.uci.edu/thornton/ics32a/Exercises/Set4/index.html"
def test_kind():
    loc = Locator("https://www.ics.uci.edu/thornton/ics32a/Exercises/Set4/index.html")
    assert Locator.kind(loc) == "https"
def test_location():
    loc = Locator("https://www.ics.uci.edu/thornton/ics32a/Exercises/Set4/index.html")
    assert Locator.location(loc) == "www.ics.uci.edu"
    assert Locator.location_parts(loc) == ['www', 'ics', 'uci', 'edu']
def test_resource():
    loc = Locator("https://www.ics.uci.edu/thornton/ics32a/Exercises/Set4/index.html")
    assert Locator.resource(loc) == "thornton/ics32a/Exercises/Set4/index.html"
    assert Locator.resource_parts(loc) == ['thornton', 'ics32a', 'Exercises', 'Set4', 'index.html']
def test_parent():
    loc = Locator("https://www.ics.uci.edu/thornton/ics32a/Exercises/Set4/index.html")
    assert Locator.parent(loc) == "https://www.ics.uci.edu/thornton/ics32a/Exercises/Set4"
def test_within():
    loc = Locator("https://www.ics.uci.edu/thornton/ics32a/Exercises/Set4/index.html")
    assert Locator.within(loc,"safeforworkcomment") == "https://www.ics.uci.edu/thornton/ics32a/Exercises/Set4/index.html/safeforworkcomment"
test_kind()
test_location()
test_parent()
test_resource()
test_within()