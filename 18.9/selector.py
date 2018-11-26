# .lower() !!!

n, m = [int(x) for x in input().split()]


def process_doc(lines, idx):
    line = lines[idx]
    striped_line = line.strip('.')
    level = (len(line) - len(striped_line)) // 2
    result = striped_line.split()
    result = [idx, result[0].lower(), (None if len(result)==1 else result[1]), []]

    while True:
        if idx == len(lines)-1:
            break
        line = lines[idx+1]
        striped_line = line.strip('.')
        next_level = ((len(line) - len(striped_line)) // 2)
        if next_level > level:
            child, idx = process_doc(lines, idx+1)
            result[3].append(child)
        else:
            break
    return result, idx


def select(doc, selector):
    result = set()
    # print(selector)
    splited_selector = selector.split()
    first_selector = splited_selector[0]
    length = len(splited_selector)
    for sub_doc in doc:
        if first_selector==sub_doc[2] or first_selector.lower()==sub_doc[1]:
            if length == 1:
                result.add(sub_doc[0])
                result.update(select(sub_doc[3], first_selector))
            else:
                result.update(select(sub_doc[3], ' '.join(splited_selector[1:])))
        else:
            result.update(select(sub_doc[3], selector))
    return result


lines = [input() for _ in range(n)]
doc, idx = process_doc(lines, 0)

result = [select([doc], input()) for _ in range(m)]
for each in result:
    one = list(each)
    one.sort()
    one = ' '.join([str(x+1) for x in one])
    one = ' '.join([str(len(each)), one])
    print(one)
