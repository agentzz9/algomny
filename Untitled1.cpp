#include<iostream>
using namespace std;
void callMe(int depth, int arr[500000])
{
	cout<<depth<<endl;
	callMe(depth+1,arr);
	
}
int main()
{
	int arr[500000];
	callMe(1,arr);
	return 0;
	
}
