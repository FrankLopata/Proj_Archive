# duck_typing.py
#
# ICS 32A Fall 2021
# Code Example
#

import math



def zero_calc(n):
    return 0


def squared(n):
    return n * n



def cubed(n):
    return n * n * n



def length(n):
    n=str(n)
    return len(n)



def square_root_calc(n):
    return math.sqrt(n)



def multiplyby3(n):
    return 3 * n

def convert_to_int(n):
    try:
        return int(n)
    except:
        return ValueError

def returnVal(func):
    return func

def if_3_in(n):
    n=str(n)
    n.split()
    if '3' in n:
        return True
    return False


def run_calcs(calcs: list, starting_value):
    current_value = starting_value

    for calc in calcs:
        current_value = calc(current_value)

    return current_value
    

