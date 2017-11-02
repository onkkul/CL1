#include <iostream>
#include <string.h>
using namespace std;

void isAccepted(string a)
{
	if(a.length()<2)
		cout<<"\n \n String length too short. . . Stringrejected . . .! ! !\n\n";
	else
	{
		cout<<"\n\n";
		int i=-1;
		do
		{
			i++;
			cout<<a[i]<<"\t";
		}while(a[i]=='h');
		if(i==0)
			cout<<"\n Unmatched character. . . Stringrejected . . .! ! !\n\n";
		else if(i==1&&a.length()==2)
		{
			if(a[i]=='a'||a[i]=='e')
				cout<<"\n\nString Accepted . . .. . ! ! !\n\n";
			else
				cout<<"\n\n Unmatched character.. . String rejected . . .! ! !\n\n";
		}
		else if(i==a.length()-1)
		{
			if(a[i]=='a'||a[i]=='e')
			{
				//i++;
				//cout<<a[i];
				cout<<"\n\nString Accepted . . . . . ! ! !\n\n";
			}
			else
				cout<<"\n \nUnmatchedcharacter. . . String rejected . . .! ! !\n\n";
		}
		else
			cout<<"\n \nString Rejected. . . .!\n\n";
		}
	}	

int main()
{
	string input;
	int i,j,k,choice;
	cout<<"The Grammar is : \n\n S--->XA\n X---> Xh | h\n A--->a|e\n___________________________________________________\n\n";
	do
	{
		cout<<"\n Enter a String\t";
		cin>>input;
		isAccepted(input);
		cout<<"\n Do you want to continue?? Enter \t1 for yes 0 for no\n";
		cin>>choice;
	} while(choice==1);
	cout<< "\n Program Terminates . . . . ! ! !\n----------------------------------------------------------------------\n";
	return 0;
}
