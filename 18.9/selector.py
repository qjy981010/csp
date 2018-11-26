n, m = [int(x) for x in input().split()]

def process(lines, idx):
    line = lines[idx]
    striped_line = line.strip('.')
    level = (len(line) - len(striped_line)) // 2
    result = striped_line.split()
    result = [result[0].lower()] if len(result)==1 else [result[0].lower(), result[1]]
    idx += 1
    line = lines[idx]
    striped_line = line.strip('.')
    next_level = ((len(line) - len(striped_line)) // 2)
    if next_level < level:
        return result, idx
    elif next_level == level:
        return result, idx