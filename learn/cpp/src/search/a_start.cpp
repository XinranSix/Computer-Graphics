#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
//定义默认目标状态
static int target[9] = {1, 2, 3, 8, 0, 4, 7, 6, 5};

//八数码类
class EightNum {
private:
    int num[9];
    int diffnum; //与目标状态位置不同的数的个数.
    int deapth;  //派生的深度.
    int evalfun; //状态的估价值
public:
    EightNum *parent;     //生成当前状态的父状态.
    EightNum *state_pre;  //当前状态前生成状态.
    EightNum *state_next; //当前状态后生成状态.
    //成员函数声明
    EightNum(void);

    EightNum(int initnum[9]);

    int get_evalfun();

    void eval_func();

    void getnum(int num1[9]);

    void setnum(int num1[9]);

    void show(void);

    void show_spec(int i);

    int null_position(void);

    EightNum &operator=(EightNum &NewEightN);

    EightNum &operator=(int num2[9]);

    int operator==(EightNum &NewEightN);

    int operator==(int num2[9]);
}; //八数码类定义

//八数码类成员函数定义
EightNum::EightNum(void) { //初始化数组num[]
    for (int i = 0; i < 9; i++)
        num[i] = i;
}

EightNum::EightNum(int initnum[9]) { //用输入的数组初始化num[]
    for (int i = 0; i < 9; i++)
        num[i] = initnum[i];
}

int EightNum::get_evalfun() { //返回估价值
    return evalfun;
}

void EightNum::eval_func() { //估价函数
    int i, temp;
    temp = 0;
    for (i = 0; i < 9; i++) {
        if (num[i] != target[i])
            temp++;
    }
    diffnum = temp;
    if (this->parent == NULL)
        deapth = 0;
    else
        deapth = this->parent->deapth + 1;
    evalfun = deapth + temp;
}

void EightNum::getnum(int num1[9]) { //取出八数码数值
    for (int i = 0; i < 9; i++)
        num1[i] = num[i];
}

void EightNum::setnum(int num1[9]) { //写入八数码数值
    for (int i = 0; i < 9; i++)
        num[i] = num1[i];
}

void EightNum::show() { //八数码输出函数
    for (int i = 0; i < 9; i++) {
        cout << num[i] << " ";
        if ((i + 1) % 3 == 0)
            cout << "\n";
    }
}

void EightNum::show_spec(int i) { //结果步骤输出函数
    cout << num[i];
    cout << "<--";
}

int EightNum::null_position() { //查找空格位置
    int i, j;
    for (i = 0; i < 9; i++) {
        if (num[i] == 0)
            j = i;
    }
    return j;
}

EightNum &EightNum::operator=(EightNum &NewEightN) { //"="重载,针对八数码类的引用
    for (int i = 0; i < 9; i++)
        num[i] = NewEightN.num[i];
    diffnum = NewEightN.diffnum;
    deapth = NewEightN.deapth + 1;
    evalfun = diffnum + deapth;
    return *this;
}

EightNum &EightNum::operator=(int num2[9]) { //"="重载,用于数组赋值
    for (int i = 0; i < 9; i++)
        num[i] = num2[i];
    return *this;
}

int EightNum::operator==(EightNum &NewEightN) { //"=="重载,用于八数码类中状态的比较
    int compere = 1;
    for (int i = 0; i < 9; i++)
        if (num[i] != NewEightN.num[i]) {
            compere = 0;
            break;
        }
    if (compere == 0)
        return 0;
    else
        return 1;
}

int EightNum::operator==(int num2[9]) { //"=="重载,用于数组的比较
    int compere = 1;
    for (int i = 0; i < 9; i++)
        if (num[i] != num2[i]) {

            compere = 0;
            break;
        }
    if (compere == 0)
        return 0;
    else
        return 1;
}
//八数码类函数定义结束

int solve(int num[9], int target[9]) { //判断是否有解的函数,利用逆序数的奇偶性来判断
    int i, j;
    int num_con = 0, tar_con = 0;
    for (i = 0; i < 9; i++)
        for (j = 0; j < i; j++) {
            if (num[j] < num[i] && num[j] != 0)
                num_con++;
            if (target[j] < target[i] && target[j] != 0)
                tar_con++;
        }
    num_con = num_con % 2;
    tar_con = tar_con % 2;
    if ((num_con == 0 && tar_con == 0) || (num_con == 1 && tar_con == 1))
        return 1;
    else
        return 0;
}

//空格移动函数
int moveup(int num[9]) { //空格上移
    for (int i = 0; i < 9; i++) {

        if (num[i] == 0)
            break;
        if (i < 3)
            return 0;
        else {
            num[i] = num[i - 3];
            num[i - 3] = 0;
            return 1;
        }
    }
}

int movedown(int num[9]) { //空格下移
    for (int i = 0; i < 9; i++) {

        if (num[i] == 0)
            break;
        if (i > 5)
            return 0;
        else {
            num[i] = num[i + 3];
            num[i + 3] = 0;
            return 1;
        }
    }
}

int moveleft(int num[9]) { //空格左移
    for (int i = 0; i < 9; i++) {

        if (num[i] == 0)
            break;
        if (i == 0 || i == 3 || i == 6)
            return 0;
        else {
            num[i] = num[i - 1];
            num[i - 1] = 0;
            return 1;
        }
    }
}

int moveright(int num[9]) { //空格右移
    for (int i = 0; i < 9; i++) {

        if (num[i] == 0)
            break;
        if (i == 2 || i == 5 || i == 8)
            return 0;
        else {
            num[i] = num[i + 1];
            num[i + 1] = 0;
            return 1;
        }
    }
}

int exist(int num[9], EightNum *a) { //判断是否重复搜索函数
    EightNum *t;
    for (t = a; t != NULL; t = t->parent)
        if (*t == num)
            return 1; //调用"=="进行数组比较
        else
            return 0;
}

EightNum *find(EightNum *s) { //寻找估价函数值最小的节点
    EightNum *m, *n;
    int min = s->get_evalfun();
    m = n = s;
    for (m = s; m != NULL; m = m->state_next) {
        if (min > m->get_evalfun()) {
            n = m;
            min = m->get_evalfun();
        }
        return n;
    }
}

int main(void) //主函数
{
    int i, j;
    int flag;
    int num[9];
    int error;

    do { //输入判断
        error = 0;
        cout << "请输入八数码问题的初始状态(用0代表空格,中间用空格隔开):" << endl;
        for (i = 0; i < 9; i++) {
            flag = 0;
            cin >> num[i];
            for (j = 0; j < i; j++)
                if (num[j] == num[i])
                    flag = 1;
            if (num[i] < 0 || num[i] > 8 || flag == 1) {
                error++;
            }
        }
        if (error != 0)
            cout << "输入数据错误!请重新输入!" << endl;
    } while (error != 0);

    cout << "是否改变默认的目标状态?(y/n)";
    char input;
    cin >> input;
    int error1;
    if (input == 'y' || input == 'Y') {
        do {
            error1 = 0;
            cout << "请输入新的目标状态(用0代表空格):" << endl;
            for (i = 0; i < 9; i++) {
                flag = 0;
                cin >> target[i];
                for (j = 0; j < i; j++)
                    if (target[j] == target[i])
                        flag = 1;
                if (target[i] < 0 || target[i] > 9 || flag == 1) {
                    error1++;
                }
            }
            if (error1 != 0)
                cout << "输入数据错误!请重新输入!" << endl;
        } while (error1 != 0);
    }

    //实例化初始状态和目标状态,并输出.
    EightNum start(num), Target(target);
    start.parent = start.state_next = start.state_pre = NULL;
    start.eval_func();
    cout << "初始状态为:" << endl;
    start.show();
    cout << "目标状态为:" << endl;
    Target.show();
    //判断是否有解
    int m = solve(num, target);
    if (m == 0) {
        cout << "此状态无解!" << endl;
        return 0;
    }

    //进入A*算法搜索
    double time;
    clock_t startt, finisht;
    int ok = 0;    //结束标识位
    int space = 0; //所耗费空间

    startt = clock(); //开始时间
    EightNum *BestNode = &start, *Node = &start, *New8Num, *r;
    while (BestNode != NULL && ok != 1) {
        BestNode = find(Node);
        if (*BestNode == Target) { //调用"=="操作符
            ok = 1;
            break;
        }
        r = BestNode->state_pre;

        //生成向上移的节点
        BestNode->getnum(num);
        if (moveup(num) && !exist(num, BestNode)) {
            New8Num = new EightNum;
            New8Num->setnum(num);
            New8Num->parent = BestNode;
            New8Num->eval_func();
            New8Num->state_pre = r;
            if (r == NULL)
                Node = New8Num;
            else
                r->state_next = New8Num;
            r = New8Num;
            space++;
        }

        //生成向下移的节点
        BestNode->getnum(num);
        if (movedown(num) && !exist(num, BestNode)) {
            New8Num = new EightNum;
            New8Num->setnum(num);
            New8Num->parent = BestNode;
            New8Num->eval_func();
            New8Num->state_pre = r;
            if (r == NULL)
                Node = New8Num;
            else
                r->state_next = New8Num;
            r = New8Num;
            space++;
        }

        //生成向左移的节点
        BestNode->getnum(num);
        if (moveleft(num) && !exist(num, BestNode)) {
            New8Num = new EightNum;
            New8Num->setnum(num);
            New8Num->parent = BestNode;
            New8Num->eval_func();
            New8Num->state_pre = r;
            if (r == NULL)
                Node = New8Num;
            else
                r->state_next = New8Num;
            r = New8Num;
            space++;
        }

        //生成向右移的节点
        BestNode->getnum(num);
        if (moveright(num) && !exist(num, BestNode)) {
            New8Num = new EightNum;
            New8Num->setnum(num);
            New8Num->parent = BestNode;
            New8Num->eval_func();
            New8Num->state_pre = r;
            if (r == NULL)
                Node = New8Num;
            else
                r->state_next = New8Num;
            r = New8Num;
            space++;
        }

        r->state_next = BestNode->state_next;
        if (BestNode->state_next != NULL)
            BestNode->state_next->state_pre = r;
        BestNode->state_next = BestNode->state_pre = NULL;
    }
    finisht = clock();

    //输出搜索结果
    if (ok == 1) {
        time = (double) (finisht - startt) * 1000 / CLOCKS_PER_SEC;
        EightNum *p, *q = NULL;
        int step = 0;
        for (p = BestNode->parent; p != NULL; p->parent) {
            if (step == 0) {
                i = 8;
                p->show_spec(i);
                i = p->null_position();
            } else {
                p->show_spec(i);
                i = p->null_position();
            }
            if (step == 8 || step == 18 || step == 28 || step == 38 || step == 48)
                cout << "\n";
            step++;
        }

        cout << "\nA*算法处理结果：所耗时间:";
        cout << time;
        cout << "ms, ";
        cout << "所耗空间:";
        cout << space;
        cout << "块, ";
        cout << "最短路径步数:";
        cout << step;
        cout << "步 !\n ";
    } else
        cout << "\nA*算法无法找到最短路径!\n";
}

