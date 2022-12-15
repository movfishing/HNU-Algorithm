#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void menu()
{
    printf("[1]�����������ŵ�������\n");
    printf("[2]ʯ�Ӻϲ�����\n");
    printf("[3]ֱ��k��ֵ����\n");
    printf("[4]������������\n");
}

int main()
{
    ofstream out("D:/VS Code C++ works/AlgorithmHomeworks/Exp3/examples.txt", ios::trunc);
    if (!out.is_open())
    {
        printf("�ļ���ʧ��,���������\n");
        exit(1);
    }
    menu();
    int n;
    int x;
    int y;
    int temp;
    cin >> n;
    int num = 1000; // ������������
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
        printf("�����ɹ���\n");
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
        printf("�����ɹ���\n");
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
        printf("�����ɹ���\n");
        break;
    case 4:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            int len = rand() % 10 + 1;
            out << len << " ";
            int k = 10000; // ����վ����
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
        printf("�����ɹ���\n");
        break;
    default:
        printf("������û����Ҳ�\n");
        break;
    }
    out.close();
    system("pause");
    return 0;
}