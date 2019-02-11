#include <iostream>
using namespace std;
//function for swap using pointers as parameters
int n;

void output(int arr[], int m)
{

	for (int i = 0; i < m; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int swap(int *x, int *y)
{
	//swapping using pointers
	int temp = *x;
	*x = *y;
	*y = temp;
}
int partition(int arr[], int high, int low)
{
	int pivot = arr[high];
	int o=low, p=high-1;
	while (o < p)
	{
		if (arr[o] > arr[high] && arr[p] < arr[high])
		{
			swap(arr[o], arr[p]);
		}
		if (arr[o] <= arr[high])
		{
			o++;
		}
		if (arr[p] >= arr[high])
		{
			p--;
		}
	}
	if(arr[o]<=arr[high])
	{
		swap(arr[high], arr[o+1]);
		return o+1;
	}
	else
	{
		swap(arr[high], arr[o]);
		return o;
	}
	
}
int qs(int arr[], int high, int low)
{
	if (low < high)
	{
		int pivo = partition(arr, high, low);
		qs(arr, pivo - 1, low);
		qs(arr, high, pivo + 1);
	}
}
int main()
{
	int m;
	cout << "how many numbers you want to sort?";
	cin >> n;
	int sor[n];
	cout << "input the numbers u want to sort ";
	for (int i = 0; i < n; i++)
	{
		cin >> sor[i];
	}
	qs(sor, n - 1, 0);
	output(sor, n);
}
