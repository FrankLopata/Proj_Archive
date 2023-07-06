from os import path
from pathlib import Path

def lines_of_code(path: Path):
    try:
        counter = 0
        lines = []
        with open(path) as p:
            lines = p.readlines()
        for line in lines:
            "".join(line.split())
            if line[0] == '#':
                lines.remove(line)
                continue
            if line == '':
                lines.remove(line)
                continue
            counter = counter + 1
        return counter
    except Exception as e:
        print(e)
