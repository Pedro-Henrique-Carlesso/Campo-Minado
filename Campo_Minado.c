#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializaTela(int matriz[9][9])
{
    int linha;
    int coluna;
    int bombas = 0;

    while (bombas < 10)
    {
        linha = rand() % 9;
        coluna = rand() % 9;

        if (matriz[linha][coluna] != -1)
        {
            matriz[linha][coluna] = -1;
            bombas++;
        }
    }

    for (linha = 0; linha < 9; linha++)
    {
        for (coluna = 0; coluna < 9; coluna++)
        {
            if (matriz[linha][coluna] != -1)
            {
                int bombasAoRedor = 0;

                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        int novaLinha = linha + i;
                        int novaColuna = coluna + j;

                        if (novaLinha >= 0 && novaLinha < 9 &&
                            novaColuna >= 0 && novaColuna < 9)
                        {
                            if (i != 0 || j != 0)
                            {
                                if (matriz[novaLinha][novaColuna] == -1)
                                {
                                    bombasAoRedor++;
                                }
                            }
                        }
                    }
                }
                matriz[linha][coluna] = bombasAoRedor;
            }
        }
    }
}

void revelaAoRedor(int matriz[9][9], int matrizComNumeros[9][9], int linha, int coluna)
{
    if (linha < 0 || linha > 8 || coluna < 0 || coluna > 8)
        return;
    if (matrizComNumeros[linha][coluna] == 1)
        return;
    if (matriz[linha][coluna] == -1)
        return;

    matrizComNumeros[linha][coluna] = 1;

    if (matriz[linha][coluna] == 0)
    {
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (i != 0 || j != 0)
                    revelaAoRedor(matriz, matrizComNumeros, linha + i, coluna + j);
    }
}

void imprimeTelaJogador(int matriz[9][9], int matrizComNumeros[9][9])
{
    printf("      ");
    for (int coluna = 0; coluna < 9; coluna++)
        printf("%d  ", coluna);
    printf("\n");

    printf("   +--");
    for (int coluna = 0; coluna < 9; coluna++)
        printf("---");
    printf("\n");

    for (int linha = 0; linha < 9; linha++)
    {
        printf(" %d | ", linha);
        for (int coluna = 0; coluna < 9; coluna++)
        {
            if (matrizComNumeros[linha][coluna] == 1)
            {
                printf(" %d ", matriz[linha][coluna]);
            }
            else
            {
                printf(" X ");
            }
        }
        printf("\n");
    }
}

void imprimeTelaOriginal(int matriz[9][9])
{
    printf("      ");
    for (int coluna = 0; coluna < 9; coluna++)
        printf("%d  ", coluna);
    printf("\n");

    printf("   +--");
    for (int coluna = 0; coluna < 9; coluna++)
        printf("---");
    printf("\n");

    for (int linha = 0; linha < 9; linha++)
    {
        printf(" %d | ", linha);
        for (int coluna = 0; coluna < 9; coluna++)
        {
            printf(" %2d ", matriz[linha][coluna]);
        }
        printf("\n");
    }
}


int verificaVitoria(int matriz[9][9], int matrizComNumeros[9][9])
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (matriz[i][j] != -1 && matrizComNumeros[i][j] == 0)
                return 0;
    return 1;
}

int main()
{
    srand(time(NULL));

    int linha, coluna;
    int perdeu = 0;
    int matriz[9][9] = {0};
    int matrizComNumeros[9][9] = {0};

    inicializaTela(matriz);

    while (perdeu == 0)
    {
        imprimeTelaJogador(matriz, matrizComNumeros);

        printf("Digite a linha: ");
        scanf("%d", &linha);
        printf("Digite a coluna: ");
        scanf("%d", &coluna);

        
        if (linha < 0 || linha > 8 || coluna < 0 || coluna > 8)
        {
            printf("Posicao invalida! Escolha outra:\n");
            continue;
        }

        if (matriz[linha][coluna] == -1)
        {
            
            revelaAoRedor(matriz, matrizComNumeros, linha, coluna);
            printf("BOOM! Voce perdeu!\n");
            imprimeTelaOriginal(matriz);
            perdeu = 1;
        }
        else
        {
            
            revelaAoRedor(matriz, matrizComNumeros, linha, coluna);

            if (verificaVitoria(matriz, matrizComNumeros))
            {
                imprimeTelaJogador(matriz, matrizComNumeros);
                printf("Parabens! Voce venceu!\n");
                perdeu = 1; 
            }
        }
    }
    return 0;
}