#include <stdio.h>

int quant[14];
int ultima[14];

int coinChange(int *moedas, int qtMoedas, int troco)
{
    quant[0] = 0;
    ultima[0] = 0;
    for (int cents = 1; cents <= troco; cents++)
    {
        int quantProv = cents;
        int ultProv = 1;
        for (int j = 0; j < qtMoedas; j++)
        {
            if (moedas[j] > cents)
                continue;
            if (quant[cents - moedas[j]] + 1 < quantProv)
            {
                quantProv = quant[cents - moedas[j]] + 1;
                ultProv = moedas[j];
            }
        }
        quant[cents] = quantProv; // solução para troco == cents
        ultima[cents] = ultProv;  // última moeda dessa solução
    }

    printf("\nNR ");
    for (int i = 0; i <= troco; i++)
    {
        printf("%02d ", i);
    }

    printf("\nQT ");
    int qt = sizeof(quant) / sizeof(quant[0]);
    for (int i = 0; i < qt; i++)
    {
        printf("%02d ", quant[i]);
    }

    printf("\nUT ");
    int ut = sizeof(ultima) / sizeof(ultima[0]);
    for (int i = 0; i < ut; i++)
    {
        printf("%02d ", ultima[i]);
    }
    printf("\n");

    return quant[troco]; //
}

int main()
{
    int moedas[] = {1, 2, 3, 6};
    int qtMoedas = sizeof(moedas) / sizeof(moedas[0]);
    int troco = 13;
    int qt = coinChange(moedas, qtMoedas, troco);
    printf("%d moedas no total", qt);
    return 0;
}
