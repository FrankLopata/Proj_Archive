from collections import namedtuple
from pathlib import Path
import os.path


Student = namedtuple('Student', ['scores', 'grade'])

def build_grade_report(path : Path, range : dict):
    d=dict()
    
    with open(path) as file:
        for line in file.readlines():
            if line[0] != '#' and line.isspace() == False:
                assert file.readlines(0) != ' '
                assert file.readlines(0) != "#"
                things = []
                studtotal=0
                for numbers in line.split():
                    assert numbers != " "
                    assert numbers != "#"
                    #gives all number and id in one line
                    if numbers.isdigit():
                        things.append(int(numbers))
                        #if grade
                        studtotal= studtotal + things[len(things)-1]
                        assert type(studtotal)==int
                    else:
                        things.append(numbers)
                        #if student ID
                for grades in range:
                    alloy = range[grades]
                    if(alloy[0] <= studtotal):
                        d[things[0]]= Student(things[1:len(things)],grades)
                        break
    print(d)

