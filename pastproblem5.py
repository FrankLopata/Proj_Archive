def lines_of_code(path):
    output= 0
    lines = []
    with open(path) as file:
        for line in file:
            if line.strip() and not line.strip().startswith("#"):
                output += 1

                lines.append(line)
    return output

