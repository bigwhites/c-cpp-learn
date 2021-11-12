#include<stdio.h>
#include<math.h>
int main(void)
{
     double pi0=1.0,min=0.0;
     double i=1.0,pin;
     int mu=1,flag=1,cnt=1;
     printf("put in min to get pi\n");
     scanf("%lf",&min);
     pin=3.14/4.0;
     while(fabs(i)>min){
      mu=mu+2;
          flag=-flag;
          i=(flag*1.0)/mu;
          pi0=pi0+i;
          cnt++;
          printf("%f,%d\n",pi0*4,cnt);
        }
        printf("pi=%f,it run %d time\n",4.0*pi0,cnt);

     

}
