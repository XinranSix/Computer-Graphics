import numpy as np
import queue
import prettytable as pt

'''
初始状态:             目标状态:
2 8 3                1 2 3
1 6 4                8   4
7   5                7 6 5   
'''
start_data = np.array([[2, 8, 3], [1, 6, 4], [7, 0, 5]])
end_data = np.array([[1, 2, 3], [8, 0, 4], [7, 6, 5]])

# 找空格(0)号元素在哪的函数
def find_zero(num):
    tmp_x, tmp_y = np.where(num == 0)
    # 返回0所在的x坐标与y坐标
    return tmp_x[0], tmp_y[0]


# 交换位置的函数 移动的时候要判断一下是否可以移动(是否在底部)
# 记空格为0号,则每次移动一个数字可以看做对空格(0)的移动,总共有四种可能

def swap(num_data, direction):
    x, y = find_zero(num_data)
    num = np.copy(num_data)
    if direction == 'left':
        if y == 0:
            # print('不能左移')
            return num
        num[x][y] = num[x][y - 1]
        num[x][y - 1] = 0
        return num
    if direction == 'right':
        if y == 2:
            # print('不能右移')
            return num
        num[x][y] = num[x][y + 1]
        num[x][y + 1] = 0
        return num
    if direction == 'up':
        if x == 0:
            # print('不能上移')
            return num
        num[x][y] = num[x - 1][y]
        num[x - 1][y] = 0
        return num
    if direction == 'down':
        if x == 2:
            # print('不能下移')
            return num
        else:
            num[x][y] = num[x + 1][y]
            num[x + 1][y] = 0
            return num


# 编写一个用来计算w(n)的函数
def cal_wcost(num):
    '''
    计算w(n)的值,及放错元素的个数
    :param num: 要比较的数组的值
    :return: 返回w(n)的值
    '''
    # return sum(sum(num != end_data)) - int(num[1][1] != 0)
    con = 0
    for i in range(3):
        for j in range(3):
            tmp_num = num[i][j]
            compare_num = end_data[i][j]
            if tmp_num != 0:
                con += tmp_num != compare_num
    return con


# 将data转化为不一样的数字 类似于hash
def data_to_int(num):
    value = 0
    for i in num:
        for j in i:
            value = value * 10 + j
    return value


# 编写一个给open表排序的函数
def sorte_by_floss():
    tmp_open = opened.queue.copy()
    length = len(tmp_open)
    # 排序,从小到大,当一样的时候按照step的大小排序
    for i in range(length):
        for j in range(length):
            if tmp_open[i].f_loss < tmp_open[j].f_loss:
                tmp = tmp_open[i]
                tmp_open[i] = tmp_open[j]
                tmp_open[j] = tmp
            if tmp_open[i].f_loss == tmp_open[j].f_loss:
                if tmp_open[i].step > tmp_open[j].step:
                    tmp = tmp_open[i]
                    tmp_open[i] = tmp_open[j]
                    tmp_open[j] = tmp
    opened.queue = tmp_open


# 编写一个比较当前节点是否在open表中,如果在,根据f(n)的大小来判断去留
def refresh_open(now_node):
    '''
    :param now_node: 当前的节点
    :return:
    '''
    tmp_open = opened.queue.copy()  # 复制一份open表的内容
    for i in range(len(tmp_open)):
        '''这里要比较一下node和now_node的区别,并决定是否更新'''
        data = tmp_open[i]
        now_data = now_node.data
        if (data == now_data).all():
            data_f_loss = tmp_open[i].f_loss
            now_data_f_loss = now_node.f_loss
            if data_f_loss <= now_data_f_loss:
                return False
            else:
                print('')
                tmp_open[i] = now_node
                opened.queue = tmp_open  # 更新之后的open表还原
                return True
    tmp_open.append(now_node)
    opened.queue = tmp_open  # 更新之后的open表还原
    return True


# 创建Node类 (包含当前数据内容,父节点,步数)
class Node:
    f_loss = -1  # 启发值
    step = 0  # 初始状态到当前状态的距离（步数）
    parent = None,  # 父节点

    # 用状态和步数构造节点对象
    def __init__(self, data, step, parent):
        self.data = data  # 当前状态数值
        self.step = step
        self.parent = parent
        # 计算f(n)的值
        self.f_loss = cal_wcost(data) + step


'算法'
opened = queue.Queue()  # open表
start_node = Node(start_data, 0, None)
opened.put(start_node)

closed = {}  # close表


def method_a_function():
    con = 0
    while len(opened.queue) != 0:
        node = opened.get()
        if (node.data == end_data).all():
            print(f'总共耗费{con}轮')
            return node

        closed[data_to_int(node.data)] = 1  # 奖取出的点加入closed表中
        # 四种移动方法
        for action in ['left', 'right', 'up', 'down']:
            # 创建子节点
            child_node = Node(swap(node.data, action), node.step + 1, node)
            index = data_to_int(child_node.data)
            if index not in closed:
                refresh_open(child_node)
        # 排序
        '''为open表进行排序,根据其中的f_loss值'''
        sorte_by_floss()
        con += 1


result_node = method_a_function()


def output_result(node):
    all_node = [node]
    for i in range(node.step):
        father_node = node.parent
        all_node.append(father_node)
        node = father_node
    return reversed(all_node)


node_list = list(output_result(result_node))
tb = pt.PrettyTable()
tb.field_names = ['step', 'data', 'f_loss']
for node in node_list:
    num = node.data
    tb.add_row([node.step, num, node.f_loss])
    if node != node_list[-1]:
        tb.add_row(['---', '--------', '---'])
print(tb)
