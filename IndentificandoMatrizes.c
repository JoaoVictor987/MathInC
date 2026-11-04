#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int typef(int i,int j)
{
    //printf("Entrei na função");
    if(j==0)
    {
        return 1;
    }
    else if(i==0)
    {
        
        return 2; 
    }
    else if(i==j)
    {
        return 3;
    }
    else 
        return 0;
}
void Indentf(int i,int j)
{   
    i--;
    j--;
    int acc=0;
    printf("Matriz Identidade: \n");
    for(int m=0; m<=i;m++)
    {
        for(int n=0; n<=j;n++)
        {
            if(n==acc)
            {
                //printf("n %d acc %d\n",n,acc);

                printf("1 ");
            }
            else
                printf("0 ");
        }
        acc++;
        printf("\n");

    }
}
void Transpf(int i, int j,double Matriz[][j])
{
    j--;
    i--;
    printf("Elementos da Matriz: \n");
    for(int m=0; m<=i;m++)
    {
        for(int n=0; n<=j;n++)
        {
            scanf("%lf",&Matriz[m][n]);
            //printf("%.1lf ",Matriz[m][n]);
        }
    }
    printf("\033[H\033[J");
    printf("Matriz Transposta: \n");
    for(int n=0; n<=j;n++)
    {
        //printf("ColRef: %d LinRef: %d\n",i,j);
        for(int m=0; m<=i;m++)
        {
            printf("%.1lf ", Matriz[m][n]);
        }
        printf("\n");
    }
}

int main()
{
    int i,j;
    printf("Escolha i e j\n");
    scanf("%d %d",&i,&j);
    double Matriz[i][j];
    printf("\033[H\033[J");
    if(typef(i,j)==1)
    {
        printf("Matriz Coluna");
    }
    else if(typef(i,j)==2)
    {
        printf("Matriz Linha");
    }
    else if(typef(i,j)==3)
    {
        Transpf(i,j,Matriz);
        Indentf(i,j);
    }
    else
    {
        Transpf(i,j,Matriz);
    }
}