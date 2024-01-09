/*this is a simple digital clock in c (for windows).This code not only
shows a digital clock for current time but also handles cases where user
might give invalid inputs like fractional numbers or numbers greater than the range
 */

#include<stdio.h>
#include<stdlib.h>//for system clear function in windows
#include<windows.h>//for Sleep function
int main ()
{
//ask user for current time;
float h,m,s;//took variable as float so that if any user gives floating point it can show invalid input and accept input again.
printf("It will take input separately for hour,minute and second.\n");
do{
printf("Enter the current hour(0-23): ");
scanf("%f",&h);
if(h!=(int)h||h<0||h>23){
   printf("Sorry,invalid input.\nPlease type again.\n");
   h=-1;
}
}while(h<0||h>23);
do{
printf("Enter the current minute(0-59): ");
scanf("%f",&m);
if(m!=(int)m||m<0||m>59){
   printf("Sorry,invalid input.\nPlease type again.\n");
   m=-1;
}
}while(m<0||m>59);
do{
printf("Enter the current second(0-59): ");
scanf("%f",&s);
if(s!=(int)s||s<0||s>59){
printf("Sorry,invalid input.\nPlease type again.\n");
s=-1;
}
}while(s<0||s>59);
while(1){
    /*printf("\r%02d:%02d:%02d",h,m,s) like we could use \r instead of system("cls") .basically this \r takes the cosole to the brginning si it
    overwrites previous content.*/
   /*also we used %02d .so that even if the user gives one integer as input it prints in a 2 integer format. like 8=08*/
   printf("%02g:%02g:%02g\n\n",h,m,s);/*here i used 02g so that it always gives output in 2 digits
                                    if i would use %f then there would be 6 more digit after decimal point.*/
   s++;
   if(s==60){
      s=00;
      m++;
   }
   if(m==60){
      m=00;
      h++;
   }
   if(h==24)
   h=00;
   /*we used sleep function so that the execution stops for 1 second. as second changes after a second has passed.
   also note that it should be capital letter Sleep.argument of the function should be in millisecond*/
   Sleep(1000);
   system("cls");
}
return 0;
}