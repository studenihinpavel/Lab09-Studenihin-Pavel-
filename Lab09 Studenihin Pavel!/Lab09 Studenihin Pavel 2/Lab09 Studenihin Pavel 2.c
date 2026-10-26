#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{
    setlocale(LC_ALL, "RUS");

    long long x, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12;
    int ost;
    long long col3 = 0, last = 0, colchet = 0, col5 = 0, nechet = 0, sum7 = 0, mnog = 1;
    long long penult_second = 0, sum_chet_except_last = 0, half1 = 0, half2 = 0;

    printf("Введите число: ");
    scanf_s("%lld", &x);
    x1 = x2 = x3 = x4 = x5 = x6 = x7 = x8 = x9 = x10 = x11 = x12 = x;
    while (x1 > 0) //1)
    {
        ost = x1 % 10;
        if (ost == 3)
        {
            col3++;
        }
        x1 = x1 / 10;
    }
    printf("Количество 3 в числе = %lld\n", col3);
    ost = x2 % 10; //2)
    while (x2 > 0)
    {
        if (x2 % 10 == ost)
        {
            last++;
        }
        x2 = x2 / 10;
    }
    printf("Количество одинаковых чисел на конце = %lld\n", last);
    while (x3 > 0)//3)
    {
        if (x3 % 10 % 2 == 0)
        {
            colchet++;
        }
        x3 = x3 / 10;
    }
    printf("Количество четных цифр в числе = %lld\n", colchet);
    while (x4 > 0) //4)
    {
        if (x4 % 10 > 5)
        {
            col5++;
        }
        x4 = x4 / 10;
    }
    printf("Количество цифр больше 5 = %lld\n", col5);
    while (x5 > 0) //5)
    {
        if (x5 % 10 % 2 != 0)
        {
            nechet += x5 % 10;
        }
        x5 = x5 / 10;
    }
    printf("Сумма нечетных цифр числа = %lld\n", nechet);
    while (x6 > 0) //6)
    {
        if (x6 % 10 >= 7)
        {
            sum7 += x6 % 10;
        }
        x6 = x6 / 10;
    }
    printf("Сумма цифр больше 7 = %lld\n", sum7);
    while (x7 > 0) //7)
    {
        if (x7 % 10 != 0)
        {
            mnog = x7 % 10 * mnog;
        }
        x7 = x7 / 10;
    }
    printf("Произведения всех цифр, исключая 0: %lld\n", mnog);
    int step8 = 1;//8)
    while (x8 > 0)
    {
        if (step8 == 2)
        {
            long long temp = x8;
            while (temp >= 100)
            {
                temp /= 10;
            }
            penult_second = (temp % 10) * (x8 % 10);
        }
        x8 /= 10;
        step8++;
    }
    printf("Произведение предпоследней и второй цифры = %lld\n", penult_second);
    int step9 = 1;//9)
    while (x9 > 0)
    {
        if (step9 > 1 && (x9 % 10 % 2 == 0))
        {
            sum_chet_except_last += x9 % 10;
        }
        x9 /= 10;
        step9++;
    }
    printf("Сумма четных цифр (кроме последней) = %lld\n", sum_chet_except_last);
    int pred = -1;//10)
    printf("Одинаковые цифры рядом: ");
    while (x10 > 0) {
        if (x10 % 10 == pred)
        {
            printf("%d и %d; ", pred, x10 % 10);
        }
        pred = x10 % 10;
        x10 /= 10;
    }
    printf("\n");
    long long count_digits = 0;//11)
    long long temp_x = x11;
    while (temp_x > 0)
    {
        count_digits++; temp_x /= 10;
    }
    if (count_digits % 2 == 0) {
        int step11 = 1;
        while (x11 > 0) {
            if (step11 <= count_digits / 2)
            {
                half1 += x11 % 10;
            }
            else
            {
                half2 += x11 % 10;
            }
            x11 /= 10;
            step11++;
        }
        if (half1 == half2) printf("Сумма половин равна\n");
        else printf("Сумма половин не равна\n");
    }
    else
    {
        printf("Нечетное количество цифр, нельзя разделить пополам\n");
    }
    int step12 = 1;//12)
    long long sum_chet_pos = 0, sum_nechet_pos = 0;
    while (x12 > 0)
    {
        if (step12 % 2 == 0)
        {
            sum_chet_pos += x12 % 10;
        }
        else
        {
            sum_nechet_pos += x12 % 10;
        }
        x12 /= 10;
        step12++;
    }
    printf("Произведение сумм четных и нечетных разрядов = %lld\n", sum_chet_pos * sum_nechet_pos);

    system("pause");
    return 0;
}