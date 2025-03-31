#include <stdio.h>
#include <math.h>
int main()
{
 int ma[100][100];
 ma[0][0]=0;
 for(int i=1;i<100;i++)
  ma[0][i]=1;
  ma[1][0]=1;
 for(int i=1;i<100;i++)
  ma[1][i]=4;
 for(int i=2;i<100;i++)
  for(int j=0;j<100;j++)
   ma[i][j]=1;
 int n;
 while(scanf("%d",&n)!=-1)
 {
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<n;j++)
    printf("%d ",ma[i][j]);
   printf("/n");
  }
  return 0;
 }
}
