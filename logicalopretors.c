#include <stdio.h>

int main()
{
    int age;

    printf("Enter Your Age\n");
    scanf("%d", &age);

    if (age > 18 && age < 75){

        printf("You Can Drive, Have a Nice Ride :) \n");
    }
    else{
        printf("Sorry Man, You Can not Drive, Dont Ask JUST YOU CANT ;') \n");
    }
    return 0;
    
        
    
}