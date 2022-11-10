#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void menu()
{
    printf("[1]���η����������Сֵ\n");
    printf("[2]���η�ʵ�ֺϲ�����\n");
    printf("[3]�ֵ�������\n");
    printf("[4]�����������\n");
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
        printf("�ļ���ʧ��,���������\n");
        exit(1);
    }
    menu();
    int n;
    int x;
    int y;
    int temp;
    int arrlen = 10; // 1,2������鳤��
    cin >> n;
    int num = 1; //������������
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
        printf("�����ɹ���\n");
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
        printf("�����ɹ���\n");
        break;
    case 3:
        out << num << endl;
        srand(unsigned(time(0)));
        while (num--)
        {
            out << Q3() << endl;
        }
        printf("�����ɹ���\n");
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