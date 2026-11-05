#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double** IdentidadeQuadradaf(int Linha,int Coluna)
{      
    double **MatrizIdentidade = malloc(Coluna * sizeof(double *));
    for(int i=0; i<Coluna;i++)
    {
        MatrizIdentidade[i] = malloc(Linha * sizeof(double));
    }
    if(MatrizIdentidade == NULL)
    {
        printf("Alocacao de Memoria falhou!\n");
        return NULL;
    }
    /////
    for(int i=0; i<Linha;i++)
    {
        for(int j=0; j<Coluna;j++)
        {
            if(j==i)
            {
                MatrizIdentidade[i][j] = 1;
            }
            else
                MatrizIdentidade[i][j] = 0;
        }
    }
    printf("Matriz Identidade: \n");
    return MatrizIdentidade;
}

double* TypeMatriz0f(int Linha, int Coluna, double Matriz[][Coluna])
{
    
    if(Linha == 1)
    {
        printf("\nPreencher Matriz: \n");
        for(int m=0; m<Coluna; m++)
        {
            scanf("%lf",&Matriz[0][m]);
        }
        double* MatrizLinha = malloc(Coluna * sizeof(double));
        if(MatrizLinha == NULL)
        {
            printf("Alocacao de Memoria falhou!\n");
            return NULL;
        }
        for(int i=0; i<Coluna;i++)
        {
            MatrizLinha[i] = Matriz[0][i];
        }
        printf("Matriz Linha Transposta: \n");
        return MatrizLinha;

    }
    else if(Coluna == 1)
    {
        printf("\nPreencher Matriz: \n");
        for(int m=0; m<Linha; m++)
        {
            scanf("%lf",&Matriz[m][0]);
        }
        double* MatrizColuna = malloc(Linha * sizeof(double));
        if(MatrizColuna == NULL)
        {
            printf("Alocacao de Memoria falhou!\n");
            return NULL;
        }
        for(int i=0; i<Linha;i++)
        {
            MatrizColuna[i] = Matriz[i][0];
        }
        printf("Matriz Coluna Transposta: \n");
        return MatrizColuna;
    }
    else 
        return NULL;
    
}
double** TypeMatriz1f (int Linha, int Coluna, double Matriz[][Coluna])
{
    if(Coluna == 0 && Linha == 0)
    {
        printf("Nao eh permitido Matrizes com tamanho nulo");
        return NULL;
    }
    printf("\nPreencher Matriz: \n");
    for(int n=0; n<Linha; n++)
    {
       for(int m=0; m<Coluna; m++)
        {
            scanf("%lf",&Matriz[n][m]);
        }
    }
    double **MatrizTranposta = malloc(Coluna * sizeof(double *));
    for(int i=0; i<Coluna;i++)
    {
        MatrizTranposta[i] = malloc(Linha * sizeof(double));
    }
    if(MatrizTranposta == NULL)
        {
            printf("Alocacao de Memoria falhou!\n");
            return NULL;
        }
    for(int i=0; i<Coluna;i++)
    {
        for(int j=0; j<Linha;j++)
        {
            MatrizTranposta[i][j] = Matriz[j][i];
        }
    }
    printf("Matriz Transposta: \n");
    return MatrizTranposta;
}


int main()
{
    int Linha, Coluna;
    printf("Linha e Coluna: ");
    scanf("%d %d",&Linha,&Coluna);
    double *RecebeLinha,*RecebeColuna,**RecebeTransp,**RecebeIdentidade;
    double Matriz[Linha][Coluna];
    if(Coluna == 0 || Linha == 0)
    {
        printf("Nao eh permitido Matrizes com tamanho nulo");
    }
    else
    {
        if(Coluna==1)
        {
            RecebeColuna = TypeMatriz0f(Linha,Coluna,Matriz);
            for(int k=0; k<Linha; k++)
            {
                printf("%.1lf",RecebeColuna[k]);
                printf("\n");
            }
            free(RecebeColuna);
        }
        else if(Linha==1)
        {
            RecebeLinha = TypeMatriz0f(Linha,Coluna,Matriz);
            for(int k=0; k<Coluna; k++)
            printf("%.1lf ",RecebeLinha[k]);
            free(RecebeLinha);
        }
        else if(Linha==Coluna )
        {
            RecebeTransp = TypeMatriz1f(Linha,Coluna,Matriz);
            for(int k=0; k<Coluna; k++)
            {
                for(int l=0; l<Linha; l++)
                {
                    printf("%.1lf ",RecebeTransp[k][l]);
                }
                printf("\n");
            }
            RecebeIdentidade = IdentidadeQuadradaf(Linha,Coluna);
            for(int k=0; k<Coluna; k++)
            {
                for(int l=0; l<Linha; l++)
                {
                    printf("%.1lf ",RecebeIdentidade[k][l]);
                }
                printf("\n");
            }
            for(int i = 0;i<Coluna;i++)
                free(RecebeIdentidade[i]);
            
            free(RecebeIdentidade);
            for(int i = 0;i<Coluna;i++)
                free(RecebeTransp[i]);
            
            free(RecebeTransp);
        }
        else
        {
            RecebeTransp = TypeMatriz1f(Linha,Coluna,Matriz);
            for(int k=0; k<Coluna; k++)
            {
                for(int l=0; l<Linha; l++)
                {
                    printf("%.1lf ",RecebeTransp[k][l]);
                }
                printf("\n");
            }
            for(int i = 0;i<Coluna;i++)
                free(RecebeTransp[i]);
            
            free(RecebeTransp);
        }
    }
}
