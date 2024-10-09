#include <stdio.h>

int main() {
    int value1, value2;
    int res;
   
    printf("first number: ");
    scanf("%d", &value1);
    printf("second number: ");
    scanf("%d", &value2);

   
    if (value1>value2){
    
        

        res = value1-value2;
        printf("Sub: %d\n", res);
    } 
    
    else if (value1<value2) {
      
        res = value1+value2;
        printf("Add: %d\n", res);
    } 
    
    else {
      
        res = value1*value2;
        printf("Mult result: %d\n", res);
    }

   
}
