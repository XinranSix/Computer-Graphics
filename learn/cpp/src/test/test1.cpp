#include <iostream>

using namespace std;

class Score {
private:
    int mid_exam;
    int fin_exam;
    static int count;
    static float sum;
    static float ave;

public:
    Score(int m, int f);
    ~Score();
    static void show_count_sum_ave();
};

Score::Score(int m, int f) {
    mid_exam = m;
    fin_exam = f;
    ++count;
    sum += fin_exam;
    ave = sum / count;
}

Score::~Score() {}

/*** 静态成员初始化 ***/
int Score::count = 0;
float Score::sum = 0.0;
float Score::ave = 0.0;

void Score::show_count_sum_ave() {
    cout << "学生人数: " << count << endl;
    cout << "期末累加成绩: " << sum << endl;
    cout << "期末平均成绩: " << ave << endl;
}

int main() {
    Score sco[3] = {Score(90, 89), Score(78, 99), Score(89, 88)};
    sco[2].show_count_sum_ave();
    Score::show_count_sum_ave();

    return 0;
}
