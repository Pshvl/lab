﻿#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double FindAn(double x, int n)
{
    return ((pow(-1, n) * pow(2, (2 * n) - 1) * pow(x, ((2 * n) - 1))) / (4 * n + 1));
}



int main()
{
    bool fl;
    int counter = 1;
    double x1 = 2;
    vector<double> s_an;
    vector<double> s_S;
    vector<double> s_aln;

    do
    {
        setlocale(LC_ALL, "rus");
        double x, al, S = 0, an = 0;
        int n = 1;
        cout << "Введите значение x от -1/4 до 1/2 " << endl;
        cin >> x;
        while (x > 0.5 || x < -0.25)
        {
            cout << "Некорректный ввод. Попробуйте снова" << endl;
            cin >> x;
        }

        cout << "Введите значение точности (alfa>0)" << endl;
        cin >> al;
        while (al < 0)
        {
            cout << "Некорректный ввод.  Попробуйте снова" << endl;
            cin >> al;
        }

        double  aln = al + 1;//!!!!!

        if (x == x1)
        {
            cout << "Вы ввели то же значение" << endl;
            int i;
            for (i = 0; i < s_an.size(); i++)
            {
                cout << " Итерация: " << n << " ";
                cout << " Последний член: " << s_an[i] << " ";
                cout << " Текущая частичная сумма: " << s_S[i] << " ";
                cout << " Точность: " << s_aln[i] << endl;
                n++;
            }
            cout << " Значения выше взяты из памяти" << endl;
            double chek;
            chek = s_aln.back();
            aln = chek;
            if (int(al) != al)
            {
                while (abs(aln) > al)
                {
                    an = FindAn(x, n);
                    S += an;
                    aln = abs((FindAn(x, n + 1)) / S);
                    cout << " Итерация: " << n << " ";
                    cout << " Последний член: " << an << " ";
                    cout << " Текущая частичная сумма: " << S << " ";
                    cout << " Точность: " << aln << endl;

                    s_an.push_back(an);
                    s_S.push_back(S);
                    s_aln.push_back(aln);
                    n++;
                }
            }
            else
            {
                while (n <= al)
                {
                    an = FindAn(x, n);
                    S += an;
                    aln = abs((FindAn(x, n + 1)) / S);
                    cout << " Итерация: " << n << " ";
                    cout << " Последний член: " << an << " ";
                    cout << " Текущая частичная сумма: " << S << " ";
                    cout << " Точность: " << aln << endl;

                    s_an.push_back(an);
                    s_S.push_back(S);
                    s_aln.push_back(aln);
                    n++;
                }
            }
        }



        else
        {
            if (counter > 1)
            {
                s_an.clear();
                s_S.clear();
                s_aln.clear();
            }
            if (int(al) != al)
            {
                while (abs(aln) > al)
                {
                    an = FindAn(x, n);
                    S += an;
                    aln = abs((FindAn(x, n + 1)) / S);
                    cout << " Итерация: " << n << " ";
                    cout << " Последний член: " << an << " ";
                    cout << " Текущая частичная сумма: " << S << " ";
                    cout << " Точность: " << aln << endl;

                    s_an.push_back(an);
                    s_S.push_back(S);
                    s_aln.push_back(aln);
                    n++;
                }
            }
            else
            {
                while (n <= al)
                {
                    an = FindAn(x, n);
                    S += an;
                    aln = abs((FindAn(x, n + 1)) / S);
                    cout << " Итерация: " << n << " ";
                    cout << " Последний член: " << an << " ";
                    cout << " Текущая частичная сумма: " << S << " ";
                    cout << " Точность: " << aln << endl;

                    s_an.push_back(an);
                    s_S.push_back(S);
                    s_aln.push_back(aln);
                    n++;
                }
            }
        }
        S = atan(2) + S;
        cout << endl << "Итоговая сумма = " << S << endl;
        counter++;
        cout << "Повторить? (да - 1; нет - 0)" << endl;
        cin >> fl;
        x1 = x;
    } while (fl);
}
