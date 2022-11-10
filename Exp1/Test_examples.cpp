#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void menu()
{
    printf("[1]分治法查找最大最小值\n");
    printf("[2]分治法实现合并排序\n");
    printf("[3]字典序问题\n");
    printf("[4]金币阵列问题\n");
}

string Q3()
{
    int nums = (rand() % 2) + 1;
    string s;
    char ch = 'a';
    for (int i = 0; i < nums; i++)
        s += '\0';
    int prev = rand() % (26 - nums);
    int last = 26;
    for (int i = 0; i < nums; i++)
    {
        s[i] = ch + prev;
        last -= (prev + 1);
        prev = rand() % (last - nums + i + 1);
        ch = s[i] + 1;
    }
    return s;
}

int main()
{
    ofstream out("D:/VS Code C++ works/AlgorithmHomeworks/Exp1/examples.txt", ios::trunc);
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
    int arrlen = 10; // 1,2题的数组长度
    cin >> n;
    int num = 1; //测试用例个数
    clock_t start_time = clock();
    switch (n)
    {
    case 1:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            out << arrlen << endl;
            for (int i = 0; i < arrlen; i++)
            {
                int a = (rand() << 15) + rand();
                out << a << endl;
            }
        }
        printf("操作成功！\n");
        break;
    case 2:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            out << arrlen << endl;
            for (int i = 0; i < arrlen; i++)
            {
                int a = (rand() << 15) + rand();
                out << a << endl;
            }
        }
        printf("操作成功！\n");
        break;
    case 3:
        out << num << endl;
        srand(unsigned(time(0)));
        while (num--)
        {
            out << Q3() << endl;
        }
        printf("操作成功！\n");
        break;
    case 4:
        out << num << endl;
        num /= 2;
        srand(unsigned(time(0)));
        while (num--)
        {
            x = rand() % 50 + 1;
            y = rand() % 50 + 1;
            out << x << " ";
            out << y << endl;
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    temp = rand() % 2;
                    out << temp << " ";
                }
                out << endl;
            }
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    temp = rand() % 2;
                    out << temp << " ";
                }
                out << endl;
            }
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