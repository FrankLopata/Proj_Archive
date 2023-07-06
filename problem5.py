
def in_reverse(function):
    def func(a, b):
        return function(b, a)

    return func

def compose(func1,func2):
    def functotal(a):
        try:
            return func1(func2(a))
        except:
            return func2(func1(a))
    return functotal


def make_accumulator(func):
    def outputfunc(a,b):
        output = a[0]
        a = a[1:]
        for num in a:
            output = func(output,num)
        output = func(output,b)
        return output
    return outputfunc

def divide(a, b):
        return a / b

def square(n):
        return n * n

def multiply(a, b):
        return a * b

def add(a, b):
        return a + b

reverse_divide = in_reverse(divide)
assert(reverse_divide(8, 2)==0.25)
assert(reverse_divide(4, 20)==5.0)

square_of_length = compose(square, len)
assert(square_of_length('Boo')==9)
assert(square_of_length([1, 2, 3, 4, 5, 6, 7])==49)

sum_all = make_accumulator(add)
assert(sum_all([1, 2, 3, 4, 5], 0)==15)

product_all = make_accumulator(multiply)
assert(product_all((5, 4, 3, 2), 1)==120)