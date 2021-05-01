/**
 * @file 0202_class_name_score_bubble_sort.cpp
 * @author HailayLin (hailay@qq.com)
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021  Hailay.site & Xihe.ai
 * 
 */

/**
 * 要求：输入人名 分数，按照分数从大到小将人排序，用对象
 */ 

#include<iostream>
#include<string>
using namespace std;

class Student {
    private:
        string name;
        double score;
    public:
        //初始化名字分数
        void setns(string n, double score);
        //打印名字和分数
        void printns();
        //返回分数
        double shows();
};

void Student::setns(string n, double s) {
    name = n;
    score = s;
}

void Student::printns() {
    cout << "name:" << name << "\tscore:" << score << endl;
}

double Student::shows() {
    return score;
}

int main() {
    int n;
    double score;
    string name;
    cin >> n;
    //创建动态对象数组
    Student *stu = new Student[n+1];
    //输入名字和分数
    for (int i=1; i<=n; i++) {
        cin >> name >> score;
        stu[i].setns(name, score);
    }
    //冒泡排序
    for (int i=1; i<=n-1; i++)
        for (int j=1; j<=n-i; j++)
            if (stu[j].shows()<stu[j+1].shows()) {
                Student tmp = stu[j+1];
                stu[j+1] = stu[j];
                stu[j] = tmp;
            }
    //输出
    for (int i=1; i<=n; i++) {
        stu[i].printns();
    }
}
