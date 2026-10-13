
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp, xk, dx, eps;
    double x, a, S, R, f;
    int n;

    cout << "xp = ";
    cin >> xp;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << "eps = ";
    cin >> eps;

    if (dx <= 0 || eps <= 0 || xp > xk)
    {
        cout << "Incorrect input!" << endl;
        return 0;
    }

    cout << fixed;
    cout << "---------------------------------------------------------------"
        << endl;
    cout << "|" << setw(9) << "x"
        << " |" << setw(15) << "f(x)"
        << " |" << setw(15) << "S"
        << " |" << setw(8) << "n" << " |" << endl;
    cout << "---------------------------------------------------------------"
        << endl;

    for (x = xp; x <= xk + dx * 1e-9; x += dx)
    {
        if (abs(x) <= 1)
        {
            cout << "|" << setw(9) << setprecision(3) << x
                << " |" << setw(15) << "undefined"
                << " |" << setw(15) << "-"
                << " |" << setw(8) << "-" << " |" << endl;
            continue;
        }

        // Точне значення функції
        f = log((x + 1) / (x - 1));

        // Перший доданок
        a = 2.0 / x;
        S = a;
        n = 1;

        // Рекурентне обчислення наступних доданків
        do
        {
            R = ((2.0 * n - 1) / (2.0 * n + 1))
                / (x * x);

            a *= R;
            S += a;
            n++;
        } while (abs(a) >= eps);

        cout << "|" << setw(9) << setprecision(3) << x
            << " |" << setw(15) << setprecision(8) << f
            << " |" << setw(15) << setprecision(8) << S
            << " |" << setw(8) << n << " |" << endl;
    }

    cout << "---------------------------------------------------------------"
        << endl;

    return 0;
}