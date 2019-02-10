#include<iostream>
using namespace std;
//function for swap using pointers as parameters
int swap(int *x, int *y)
{
	//swapping using pointers
	int temp = *x;
	*x=*y;
	*y=temp;
}	
int partition(int arr[] ,int low,  int high)
{

	int pivot = arr[high] ;
	int o,p;
		for(int o = 0 , p = high-1 ; o < p;)
		{
			if (arr[o]>pivot && arr[p]<pivot )
				{
					swap(arr[o] , arr[p]);
				}
				if(arr[o]<pivot)
				{
					o++;
				}
				if(arr[p]>pivot)
				{
					p--;
				}
				
		}
		swap(arr[high] ,arr[o]);
	return pivot;
}
int qs(int arr[], int high , int low )
{
	int pivot = arr[high] ;
	if(low<high)
	{
		pivot=partition(arr , low , high);
		qs( arr, pivot-1 , low  );
		qs( arr, high , pivot +1 );
	}	
}
int main()
{
	int n;
	cout << "how many numbers you want to sort?";
	cin >> n;
	int sor[n];
	cout << "input the numbers u want to sort ";
	for(int i = 0; i < n; i++)
	{
	cin >> sor[i];	
	}
	qs(sor ,n-1, 0 );
	for(int i = 0; i < n-1; i++)
	{
	cout << sor[i] << " ";	
	}	
}
