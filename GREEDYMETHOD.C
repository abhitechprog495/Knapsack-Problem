#include<stdio.h>
#include<conio.h>
void knapsack(float capacity, int n, float weight[], float profit[])
{
	float x[20],maxprofit=0,y;
	int i,j;
	y=capacity;
	for(i=0;i<n;i++)
		x[i]=0.0;
	for(i=0;i<n;i++)
	{
		if(weight[i]>y)
			break;
		else
		{
			x[i]=1.0;
			maxprofit=maxprofit+profit[i];
			y=y-weight[i];
		}
	}
	if(i<n)
		x[i]=y/weight[i];
	maxprofit=maxprofit+(x[i]*profit[i]);
	printf("\nMaximum Profit = %f\n\n",maxprofit);
}
int main()
{
	float weight[20],profit[20],ratio[20], temp1,temp2,temp3,capacity;
	int i,j,n;
	printf("Enter The Number Of Objects : ");
	scanf("%d",&n);
	printf("Enter The Capacity Of Knapsack : ");
	scanf("%f", &capacity);
	printf("Enter The Profit And Weight Of Each Object : \n");
	for(i=1;i<=n;i++)
	{
		printf("Profit And Weight Of Object[%d]\n",i);
		printf("Profit : ",i);
		scanf("%f",&profit[i]);
		printf("Weight : ",i);
		scanf("%f",&weight[i]);
		ratio[i]=profit[i]/weight[i];
	}
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
		{
			if(ratio[i]>ratio[j])
			{
				temp1=ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=temp1;
				temp2=weight[i];
				weight[i]=weight[j];
				weight[j]=temp2;
				temp3=profit[i];
				profit[i]=profit[j];
				profit[j]=temp3;
			}
		}
	knapsack(capacity,n,weight,profit);
	getch();
}

