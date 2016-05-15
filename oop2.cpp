#include<iostream.h>
class complex
{
	int r,i;
	public:
		void input()
		{
			cout<<"Enter Real and Imaginary parts:"<<endl;
			cin>>r>>i;
		}
		void add(complex a,complex b)
		{
			cout<<"On Addition: ("<<a.r+b.r<<") + i("<<a.i+b.i<<")"<<endl;
		}
		void sub(complex a,complex b)
		{
			cout<<"On Subtraction: ("<<a.r-b.r<<") + i("<<a.i-b.i<<")"<<endl;
		}

};
int main()
{
	complex obj1,obj2;
	cout<<"Enter 1st No:"<<endl;
	obj1.input();
	cout<<"Enter 2nd No:"<<endl;
	obj2.input();
	obj1.add(obj1,obj2);
	obj1.sub(obj1,obj2);
	system("pause");
	return 0;
}

	