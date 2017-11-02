#include"iostream"
#include "omp.h"
using namespace std;

class Quicksort
{
	public:
	void sort(int *arr, int size)
	{
		if(size == 1 || size == 0)
		return;
		int pivot = arr[0];
		int *arrl = new int[size];
		int *arrh = new int[size];
		int j=0, k=0;
		#pragma omp parallel num_threads(size-1)
		{
			int id = omp_get_thread_num();
			int element = arr[id+1];
			cout	<<"\n" << "thread id is \t"<<id<<"\n";
			#pragma omp critical
			{
				if( element <= pivot )
				arrl[j++] = element;
				else
				arrh[k++] = element;
			}
		}
		sort(arrl, j);
		int p=0;
		for(int i=0; i<j; i++)
		{
			arr[p++] = arrl[i];
			arr[p++] = pivot;
			sort(arrh, k);
		}
		for(int i=0; i<k; i++)
		{
			arr[p++] = arrh[i];
			delete(arrl);
			delete(arrh);
		}
	}
};

int main()
{
	cout<<"\n\n***Implementation of parallel quick sort*****"<<"\n";
	int size;
	cout<<"\n\nEnter size of an array: \n";
	cin>>size;
	int arr[size];cout<<"\n\nEnter no.s to be sorted: \n";
	for (int i = 0 ; i < size ; i++)
	{
		cin>>arr[i];
	}
	Quicksort q;
	q.sort(arr, size);
	cout<<"\n\nSorted array is:\n\n";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<"\t";
	}
		cout<<"\n";
		cout<<"\n\n"<<"\n";
		
return 0;
}
