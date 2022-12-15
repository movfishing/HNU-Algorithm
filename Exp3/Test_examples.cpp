#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void menu()
{
    printf("[1]独立任务最优调度问题\n");
    printf("[2]石子合并问题\n");
    printf("[3]直线k中值问题\n");
    printf("[4]汽车加油问题\n");
}

int main()
{
    ofstream out("D:/VS Code C++ works/AlgorithmHomeworks/Exp3/examples.txt", ios::trunc);
    if (!out.is_open())
    {
        printf("文件打开失败,请检查后重试\n");
        exit(1);
    }
    menu();
    int n;
    int x;
    int y;
    int temp;
    cin >> n;
    int num = 1000; // 测试用例组数
    clock_t start_time = clock();
    switch (n)
    {
    case 1:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            int len = 10000;
            out << len << endl;
            for (int i = 0; i < len; i++)
            {
                int a = rand() % 10 + 1;
                out << a << " ";
            }
            out << endl;
            for (int i = 0; i < len; i++)
            {
                int b = rand() % 10 + 1;
                out << b << " ";
            }
            out << endl;
        }
        printf("操作成功！\n");
        break;
    case 2:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            int len = 100;
            out << len << endl;
            for (int i = 0; i < len; i++)
            {
                int a = rand() % 10 + 1;
                out << a << " ";
            }
            out << endl;
        }
        printf("操作成功！\n");
        break;
    case 3:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            int len = 300;
            out << len << endl;
            int k = rand() % len + 1;
            out << k << endl;
            int prevx = 0;
            int nextx = 0;
            for (int i = 0; i < len; i++)
            {
                nextx += 3;
                int x = (rand() % (nextx - prevx)) + prevx + 1;
                out << x << " ";
                prevx = x;
                out << rand() % 9 + 1 << " ";
                out << rand() % 9 + 1 << endl;
            }
        }
        printf("操作成功！\n");
        break;
    case 4:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            int len = rand() % 10 + 1;
            out << len << " ";
            int k = 10000; // 加油站个数
            out << k << endl;
            int choose = rand() % 100;
            for (int i = 0; i <= k; i++)
            {
                int a;
                if (choose == 99)
                {
                    a = rand() % (len + 1) + 1;
                }
                else
                    a = rand() % len + 1;
                out << a << " ";
            }
            out << endl;
        }
        printf("操作成功！\n");
        break;
    default:
        printf("闰土都没你会找茬\n");
        break;
    }
    out.close();
    system("pause");
    return 0;
}