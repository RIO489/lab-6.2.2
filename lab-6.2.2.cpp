#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int n, const int Low, const int High,int i)
{
    if (i < n)
    {
        a[i] = Low + rand() % (High - Low + 1);
        return Create(a, n, Low, High, i + 1);
    }
}

void Print(int* a, const int n, int i)
{
    cout << "a[i] = " << a[i] << setw(4) << endl;
    if (i < n - 1)
        Print(a, n, i + 1);
    else
        cout << endl;
}

int Sum(int* a, const int n, int i)
{
    if (i < n)
    {
        if (a[i] % 2 != 0)
            return a[i] + Sum(a, n, i + 1);
        else
            return Sum(a, n, i + 1);
    }
        else
        return 0;
}

int Count(const int a[], const int n, int i)
{
    if (i < n)
    {
        if (a[i] % 2 != 0)
            return 1 + Count(a, n, i + 1);
        else
            return Count(a, n, i + 1);
    }
    else return 0;
}

double Arif(int* a, const int n,int i)
{
    return Sum(a, n, i) / Count(a, n, i);


}

int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n = "; cin >> n;
    int* a = new int [n];
    int Low = -20;
    int High = 50;
    Create(a, n, Low, High,0);
    Print(a, n,0);
    cout << "S = " << Sum(a, n,0) << endl;
    cout << "Count =  " << Count(a, n, 0) << endl;
    cout << "A = " << Arif(a, n,0) << endl;
    delete[]a;
    return 0;
}

