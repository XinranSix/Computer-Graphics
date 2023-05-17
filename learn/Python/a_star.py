move_map = {'up': -3, 'down': 3, 'left': -1, 'right': 1}


def create(array1, array2):
    p = array1[:]
    p.insert(0, array2)
    for i in close:
        if i[0] == p[0]:
            return
    open.append(p)


def hx(current):
    count = 0
    end = [1, 2, 3, 8, 0, 4, 7, 6, 5]
    for i in range(len(current)):
        if current[i] == end[i]:
            count += 1
    return count


def show(li):
    for j in range(len(li)):
        if j % 3 == 0:
            print('\t')
        print(li[j], end=' ')
    print('\t')


if __name__ == "__main__":
    start = [2, 8, 3, 1, 0, 4, 7, 6, 5]
    end = [1, 2, 3, 8, 0, 4, 7, 6, 5]
    open = []
    close = []
    step = 0
    open.append([start])
    while True:
        this = open.pop(0)
        close.append(this)
        if this[0] == end:
            print('搜索成功')
            for i in this[::-1]:
                show(i)
            exit()

        if this[0].index(0) > 2:
            node = this[0].copy()
            a = this[0].index(0)
            b = a + move_map['up']
            node[a], node[b] = node[b], node[a]
            create(this, node)

        if this[0].index(0) < 6:
            node = this[0].copy()
            a = this[0].index(0)
            b = a + move_map['down']
            node[a], node[b] = node[b], node[a]
            create(this, node)

        if this[0].index(0) != 0 and this[0].index(0) != 3 and this[0].index(0) != 6:
            node = this[0].copy()
            a = this[0].index(0)
            b = a + move_map['left']
            node[a], node[b] = node[b], node[a]
            create(this, node)

        if this[0].index(0) != 2 and this[0].index(0) != 5 and this[0].index(0) != 8:
            node = this[0].copy()
            a = this[0].index(0)
            b = a + move_map['right']
            node[a], node[b] = node[b], node[a]
            create(this, node)

        open.sort(key=lambda x: x[0])
