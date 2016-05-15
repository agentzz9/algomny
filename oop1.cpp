#include<iostream.h>
#include<math.h>
class triangle //right angled
{
	float b,h;
	public:
		void input()
		{
			cout<<"Enter Base & Height: ";
			cin>>b>>h;
		}
		void area();
		void perimeter();
};
void triangle::area()
{
	cout<<"The Area: "<<(b*h)/2<<"sq. units"<<endl;
}
void triangle::perimeter()
{
	float hyp;
	hyp=pow(((b*b)+(h*h)),.5);
	cout<<"The Perimeter: "<<hyp+h+b<<" units"<<endl;
}

int main()
{
	triangle obj;
	
	obj.input();
	obj.area();
	obj.perimeter();
	system("pause");
	return 0;
}
