from collections import namedtuple
def pretty_print(tup: namedtuple)-> None:
    dic = tup._asdict()
    lkey = [*dic]
    test_lkey(lkey,dic)
    maximum = len(max(lkey,key=len))
    for keys in lkey:
        if(len(keys)< maximum):
            inx = 0
            while inx < maximum - len(keys):
                keys = " "+keys
            test_max_len(keys,lkey)
        print((str(keys) +": " + str(getattr(tup, keys.strip()))))
    
def test_max_len(key:str,l:list):
    for k in l:
        if key == k:
            return
        if (len(k)!=len(key)):
            return AssertionError
    

def test_lkey(lkey:list,dic:dict):
    try:
        index  = 0
        for key in dic:
            if key != lkey[index]:
                return AssertionError
            index = index + 1
    except:
        return AssertionError





    

        


