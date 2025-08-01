#include<stdio.h>
#include<math.h>

void clean_bufer();
float ask_number(char var);

int main()
{
    int operacion, seleccion, i, isnuma, isnumb;
    float a,b, result, resultados[5]={0};
    char contin='y', guardar='n';
    
    while (contin=='y')
    {
        seleccion=0;
        isnuma=0;
        isnumb=0;
        
        while(guardar!='y' && guardar!='n')
        {
            printf("Keep the previous result %f? y/n: ",result);
            scanf(" %c",&guardar);
        }
        while (seleccion==0)
        {
            printf("What do you want to do?\n 0=exit\n 1=add\n 2=substract\n 3=multiply\n 4=divide\n 5=power\n 6=root\n 7=sin\n 8=cos\n 9=factorial\n");
            scanf("%d",&operacion);
            
            if (operacion >0 && operacion <10)
            {   
                if (guardar=='n')
                {
                    a=ask_number('a');
                } else {
                    a=result;
                }
                if (operacion >0 && operacion <7)
                {
                    b=ask_number('b');
                }
                
                seleccion=1;
                contin='x';
            } else if (operacion==0) {
                seleccion=1;
            } else {
                printf("Not a valid selection\n");
            }
        }
        
        switch (operacion) {
        case 1:
            result=a+b;
            printf("%f + %f = %f\n",a,b,result);
            break;
        case 2:
            result=a-b;
            printf("%f - %f = %f\n",a,b,result);
            break;
        case 3:
            result=a*b;
            printf("%f * %f = %f\n",a,b,result);
            break;
        case 4:
            if (b==0)
                printf("Can't divide by zero\n");
            else
            {
                result=a/b;
                printf("%f / %f = %f\n",a,b,result);
            }
            break;
        case 5:
            result=pow(a,b);
            printf("%f^%f = %f\n",a,b,result);
            break;
        case 6:
            result=pow(a,1/b);
            printf("%f root of %f = %f\n",b,a,result);
            break;
        case 7:
            result=sin(a);
            printf("sin(%f) = %f\n",a,result);
            break;
        case 8:
            result=cos(a);
            printf("cos(%f) = %f\n",a,result);
            break;
        case 9:
            if (a<0 || a!=floor(a)) // Check if a is negative or not an integer
            {
                printf("Can't calculate factorial of negative numbers or non integers\n");
                result=0;
            } else {
                result=1;
                for (i=1;i<=a;i++)
                    result*=i;
                printf("%f! = %f\n",a,result);
            }
            break;
        default:
            contin='n';
        }
        
        while (contin!='y' && contin!='n')
        {
            printf("Do you wish to do another operation? y/n:");
            scanf(" %c",&contin);
        }
        
        guardar='x';
        
        printf("Previous results: ");
        for (i=1;i<=4;i++)
        {
            resultados[i-1]=resultados[i];
            printf("%f, ",resultados[i-1]);
        }
            
        resultados[4]=result;
        printf("%f\n",resultados[4]);
    }
    
    printf("Thank you and have a nice day\n");
    
    return 0;
}

void clean_bufer()
{
    while (getchar() != '\n' && getchar() != EOF); // Limpia el búfer
}

float ask_number(char var)
{
    int isnum=0;
    float a;
   
    while (isnum==0)
    {
        printf("Value for %c= ",var);
       
        if(scanf("%f",&a)!=1)
        {
            printf("Not valid value for a. Press enter to try again\n");
            clean_bufer(); // Limpia el búfer
            continue;
        }
        
        isnum=1;
    }
    
    return a;
}