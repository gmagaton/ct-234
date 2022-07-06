#include <stdio.h>

int min(int a, int b)
{
    return a > b ? b : a;
}

int DCMakeChange(int *moedas, int qtMoedas, int troco)
{
    if (troco == 0)
        return 0;
    int q = troco;
    for (int i = 0; i < qtMoedas; i++)
    {
        if (moedas[i] > troco)
            continue;
        q = min(q, 1 + DCMakeChange(moedas, qtMoedas, troco - moedas[i]));
    }

    return q;
}

int main()
{
    int moedas[] = {1, 2, 3, 6};
    int qtMoedas = sizeof(moedas) / sizeof(moedas[0]);
    int troco = 13;
    int qt = DCMakeChange(moedas, qtMoedas, troco);
    printf("%d moedas no total", qt);
    return 0;
}
