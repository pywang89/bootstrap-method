#include<iostream>
#include<math.h>
using namespace std;
int main()
{

	double swap_rate[7]={2.26, 2.275, 2.285, 2.320, 2.355, 2.3975, 2.44};
	double zero_rate[7];
	double temp,period;
	
	zero_rate[0] = log(1 + swap_rate[0]/100); //log()肚把计礛癸计(base-e癸计)
	
	for (int i = 1; i < 7; i++)
	{
		period = 0;
		for (int j = 0; j < i; j++)
		{
			period+= (swap_rate[i]/100) * exp(-zero_rate[j] * (j+1));
		}
		
		temp =1-period;	
		zero_rate[i] = log((1 + (swap_rate[i]/100))  / temp) / (i + 1);
	}
	
	for (int i = 0; i < 7; i++)
	{	
		cout << "The " << i + 1 << "-th zero rate is "; 
		printf("%.5f%\n",zero_rate[i]*100);
	}
	
	return 0;
}
