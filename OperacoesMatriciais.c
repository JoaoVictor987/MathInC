#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double** SomaSubtMatrizf(int Linha,int Coluna,double Matriz1[][Coluna],double Matriz2[][Coluna])
{
    if(Linha == Coluna)
    {
        double **MatrizResultado = malloc(Coluna * sizeof(double *));
        for(int i=0; i<Coluna;i++)
        {
            MatrizResultado[i] = malloc(Linha * sizeof(double));
        }
        for(int i=0; i<Coluna; i++)
        {
            for(int j=0; j<Linha; j++)
            {
                MatrizResultado[i][j] = Matriz1[i][j] + Matriz2[i][j];
            }
        }
        return MatrizResultado;
    }
    else
    {
        printf("Linhas e Colunas devem ter o mesmo tamanho para dada operação!");
        return NULL;
    }
}
double** ProdutoMatrizf(int Linha1,int Coluna1,int Linha2,int Coluna2,double Matriz1[][Coluna1],double Matriz2[][Coluna2])
{
    if(Coluna1 == Linha2)
    {
        //double acc[];
        double **MatrizResultado = malloc(Coluna2 * sizeof(double *));
        for(int i=0; i<Coluna2;i++)
        {
            MatrizResultado[i] = malloc(Linha1 * sizeof(double));
        }
        for(int i = 0; i<Linha1; i++)
        {
            for(int j = 0; j<Coluna1; j++)
            {
                MatrizResultado[i][j] = 0;
                for(int k = 0; k< Coluna1; k++)
                {
                    MatrizResultado[i][j] +=  Matriz1[i][k]*Matriz2[k][j];
                }
            }
        }
        return MatrizResultado;
    }
    else
    {
        printf("Para multiplicação de Matrizes a Coluna da primeira matriz deve coincidir com a Linha da segunda!");    
        return NULL;
    }

}
double** EscalarMatrizf(int Linha,int Coluna,double Matriz1[][Coluna],double Escalar)
{
    double **MatrizResultado = malloc(Coluna * sizeof(double *));
    for(int i=0; i<Coluna;i++)
    {
        MatrizResultado[i] = malloc(Linha * sizeof(double));
    }
    for(int i=0; i<Coluna; i++)
    {
        for(int j=0; j<Linha; j++)
        {
            MatrizResultado[i][j] = Matriz1[i][j] * Escalar;
        }
    }
    return MatrizResultado;
}





int main()
{
    int Linha, Coluna, Linha2, Coluna2;
    int Escolha;    
    printf("Operacao 1, Produto por Escalar\nOperacao 2, Soma de Matrizes\nOperacao 3, Produto entre Matrizes");
    printf("\nOperacao: ");
    scanf("%d", &Escolha);
    //Escolha = 3;
    printf("\nInforme o tamanho desejado da Matriz 1: \n");
    scanf("%d %d", &Linha,&Coluna);
    double Matriz[Linha][Coluna];
    printf("\033[H\033[2J");
    printf("Informe os elementos para Matriz 1: ");
    for (int i=0; i<Linha; i++)
        {
            for(int j=0; j<Coluna; j++)
            {
                scanf("%lf",&Matriz[i][j]);
            }
        }
    if(Escolha == 1)
    {
        double Escalar;
        printf("Escalar: ");
        scanf("%lf",&Escalar);
        double **RecebeEscalarM;
        RecebeEscalarM = EscalarMatrizf(Linha,Coluna,Matriz,Escalar);
        for(int i=0; i<Linha; i++)
        {
            printf("\033[H\033[2J");
            for(int j=0; j<Coluna; j++)
            {
                printf("%.1lf ",RecebeEscalarM[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    printf("\033[H\033[2J");
    printf("Informe o tamanho desejado da Matriz 2: \n");
    scanf("%d %d",&Linha2,&Coluna2);
    double Matriz2[Linha2][Coluna2];
    printf("\nInforme os elementos para Matriz 2: ");
    for (int i=0; i<Linha; i++)
    {
        for(int j=0; j<Coluna; j++)
        {
            scanf("%lf",&Matriz2[i][j]);       
        }
    }
    if(Escolha == 2)
    {
        double **RecebeSomaM;
        RecebeSomaM = SomaSubtMatrizf(Linha,Coluna,Matriz,Matriz2);
        printf("\033[H\033[2J");
        for(int i=0; i<Linha; i++)
        {
            for(int j=0; j<Coluna; j++)
            {
                printf("%.1lf",RecebeSomaM[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    else if(Escolha == 3)
    {
        double **RecebeProdutoM;
        RecebeProdutoM = ProdutoMatrizf(Linha,Coluna,Linha2,Coluna2,Matriz,Matriz2);
        printf("\033[H\033[2J");
        for(int i=0; i<Linha; i++)
        {
            for(int j=0; j<Coluna; j++)
            {
                printf("%.1lf ",RecebeProdutoM[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
}