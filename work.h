#ifndef WORK_H
#define WORK_H
#include<iostream>
#include<string>
#include<vector>
#include<ctime>//把日期和时间转换为字符串，
#include<cstdlib>//提供一些常用函数比如rand()-=
using namespace std;
class work
{
public:
    int s;// 作业进入的时间
    int t;//作业的执行时间
    int p;//作业的优先级
    int num;//作业标号
    int ti;//等待时长
    work(int ss=0, int tt=0, int n=-1) {
        s = ss;
        t=tt;
        num = n;
        ti = 0;
        p = t ;
    }
    bool  operator < (work& a) {
        if (this->p == a.p)
            return this->num < a.num;
        else return this->p < a.p;
    }
    bool  operator > (work& a) {
        if (this->p == a.p)
            return this->num > a.num;
        else return this->p > a.p;
    }

    void update(int a,int b) {
        ti += a;
        p -= b;
    }
};

class Heap
{
    vector<work*>v;
public:
    Heap(vector<work*>_v = vector<work*>()) {
        v = _v;
    }
    void insert(work* a) {
        if (v.size() == 0)v.push_back(a);
        else {
            v.push_back(a);
            int n = v.size() - 1, i;
            for (i = n; *v[(i-1) / 2] > *a; i--,i/=2)
            {
                v[i] = v[(i-1) / 2];
                if (i == 0)break;
            }

            v[i] = a;
        }
    }


    void del() {
        int n = v.size()-1, i = 0;
        swap(v[0], v[n]);
        v.pop_back();
        if (n == 0)return;
        work* temp =v[0];
        for (int k = 1; k < n; k = k * 2 + 1) {
            if (k + 1 < n && v[k] > v[k + 1])
                k++;
            if (*temp > * v[k]) {
                v[i] = v[k];
                i = k;
            }
            else break;
        }
        v[i] = temp;
    }
    int size() { return v.size(); }
    work* top() {
        if (v.size() != 0)return v[0];
        return NULL;
    }
};


#endif // WORK_H
