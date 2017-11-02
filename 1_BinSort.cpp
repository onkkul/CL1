#include<iostream>
using namespace std;

class b_sort
{
	int n,list[20],key;
	public:
		void accept_input();
		void display();
		void sortInit();
		void sort(int list[],int start,int end);
		int partition(int list[],int start,int end);
		int binary(int list[],int key,int start,int end);
		int binaryInit(int key);
		
};

void b_sort :: accept_input()
{
	cout << "enter no of elements: ";
	cin >> n;
	cout << "enter elements: ";
	for(int i=0;i<n;i++)
	{
	cin >> list[i];
	}
}

void b_sort :: display()
{
	cout << "Sorted elements: ";
	for(int i=0;i<n;i++)
	{
		cout << list[i] << " ";
		cout << endl;
	}
}

void b_sort :: sortInit()
{
	sort(list,0,n-1);
}

void b_sort::sort(int list[],int start,int end)
{
	if(start<end)
	{
		int pivot=partition(list,start,end);
		sort(list,start,pivot-1);
		sort(list,pivot+1,end);
	}
}

int b_sort:: partition(int list[],int start,int end)
{
	int pos=start;
	int pivot=list[start];
	for(int i=start;i<=end;i++)
	{
		if(pivot>list[i])
		{
			list[pos]=list[i];
			list[i]=list[pos+1];
			list[pos+1]=pivot;
			pos++;
		}
	}
	return pos;
}

int b_sort :: binaryInit(int key)
{
	return binary(list,key,0,n-1);
}

int b_sort:: binary(int list[],int key,int start,int end)
{
	int static flag=0;
	int mid=(start+end)/2;
	if(list[mid]==key)
	{
		flag=1;
		cout << key << " is present in list at position\t"<<mid<<"\n";
		
		return flag;
	}
	if(start<end)
	{
		if(key>list[mid])
			binary(list,key,mid+1,end);
		else
			binary(list,key,start,mid-1);
	}
	return flag;
}


int main()
{
	b_sort s;
	int key;
	s.accept_input();
	s.sortInit();
	s.display();
	cout << "enter the key to be searched: ";
	cin >> key;
	if(!s.binaryInit(key))
		cout << key << " is not present\n";
}
