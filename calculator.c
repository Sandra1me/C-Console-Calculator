/*
    Simple Calculator
    ----------------------
    Simple calculator with support for basic operations, trigonometric functions, and factorial.

    Author: [Sandra Martin Elias]
    Date: [2025/07/29]
*/

#include<stdio.h>
#include<math.h>

void clean_bufer();
float ask_number(char var);

int main()
{
    // Variables for operations, selections and results
    int operacion, seleccion, i, isnuma, isnumb;
    float a,b, result, resultados[5]={0};
    char contin='y', guardar='n';
    
    while (contin=='y') // Main loop, keeps running until user decides to exit
    {
        seleccion=0;
        isnuma=0;
        isnumb=0;
        
        while(guardar!='y' && guardar!='n') // Ask if the user wants to keep the previous result or insert a new value
        {   
            printf("Keep the previous result %f? y/n: ",result);
            scanf(" %c",&guardar);
        }
        while (seleccion==0) // Loop to ask for operation until a valid one is selected
        { 
            printf("What do you want to do?\n 0=exit\n 1=add\n 2=substract\n 3=multiply\n 4=divide\n 5=power\n 6=root\n 7=sin\n 8=cos\n 9=factorial\n");
            scanf("%d",&operacion);
            
            if (operacion >0 && operacion <10)
            {   
                if (guardar=='n') // If the user does not want to keep the previous result, ask for a new value
                {  
                    a=ask_number('a');
                } else {
                    a=result;
                }
                if (operacion >0 && operacion <7) // Ask for a second value only for operations that require it
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
        
        switch (operacion) { // Perform the selected operation

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
            case 4: // Division with zero check
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
            case 6: // Root calculation
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
            case 9: // Factorial calculation with check for negative and non-integer values
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
        
        while (contin!='y' && contin!='n') // Ask if the user wants to continue with another operation
        {
            printf("Do you wish to do another operation? y/n:");
            scanf(" %c",&contin);
        }
        
        guardar='x';
        
        printf("Previous results: "); // Update and display the results array
        for (i=1;i<=4;i++)
        {
            resultados[i-1]=resultados[i];
            printf("%f, ",resultados[i-1]);
        }
            
        resultados[4]=result;
        printf("%f\n",resultados[4]);
    }
    
    printf("Thank you and have a nice day\n"); // Exit message
    
    return 0;
}

void clean_bufer() // Clean input buffer to avoid invalid reads
{
    while (getchar() != '\n' && getchar() != EOF); // Limpia el búfer
}

float ask_number(char var) // Function to ask for a number, ensuring valid input
{
    int isnum=0;
    float a;
   
    while (isnum==0) // Keep asking until a valid number is entered
    {
        printf("Value for %c= ",var);
       
        if(scanf("%f",&a)!=1) // If input is invalid, ask again after cleaning the buffer
        {
            printf("Not valid value for a. Press enter to try again\n");
            clean_bufer(); // Limpia el búfer
            continue;
        }
        
        isnum=1;
    }
    
    return a;

}
