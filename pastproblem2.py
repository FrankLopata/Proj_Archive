



def first_chars(lst : list[str]):
    storage = ""
    if(len(lst)>0):
        index = 0
        while index < len(lst):
            con = lst[index]
            if type(con)==str:
                storage = storage + con[0]
                index = index + 1
            else:
                storage = storage + first_chars(lst[index])
                index = index+1
    else:
        storage = lst[0]
    return storage

def count_bigger(lst: list, num: int):
    out = 0
    if(len(lst)>0):
        index = 0
        while index < len(lst):
            con = lst[index]
            if (type(con)==str):
                index = index +1
                continue
            if(type(con)==list):
                out = out + count_bigger(lst[index], num)
            elif(type(con) == int or float):
                if lst[index] > num:
                    out = out + 1
            index = index + 1
    return out
            



assert(first_chars(['boo', 'was', ['sleeping', 'deeply'], 'that', 'night', ['as', ['usual']]]))
assert(count_bigger([ 32, "was", [2, 'deeply'], 'that', 11, [13, ['usual']]],17))
assert(count_bigger(['boo', [3.0, 'is', 'perfect'], 'today', 5], 3))
assert(count_bigger([1, 2, 3, 4, 5, 6], 2.5))