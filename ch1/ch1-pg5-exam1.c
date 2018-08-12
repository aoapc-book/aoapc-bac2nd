#include<stdio.h>
#include<math.h>

int main()
{
   //const double PI = acos(-1.0);
   double r,h;
   double s1, s2, area;
 
   scanf("%lf%lf", &r, &h);

   s1 = 2 * M_PI * r * h;
   s2 = M_PI * pow(r, 2);
   area = s1 + 2 * s2;

   printf("Area = %.3f\n", area);

   return 0;
}
