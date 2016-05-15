#include<iostream.h>
#include<conio.h>

class income
{
	double long basic,da,hra,ded,tax,income;
	public:
		void paysalary();
		void computededuction();
		void calculatetax();
		void output();
};
int main()
{
	income obj;

	obj.paysalary();
	obj.computededuction();
	obj.calculatetax();
	obj.output();
	
	return 0;
}
void income::paysalary()
{
	cout<<"Input Basic Salary Rs. ";cin>>basic;
	cout<<"Input DA           Rs. ";cin>>da;
	hra=(.15)*basic;
}
void income::computededuction()
{
	ded=(0.8)*basic;
}
void income::calculatetax()
{
	if(basic<100000)
	{
		tax=(.2)*basic;
	}
	else
	{
		tax=(.1)*((.3)*basic);
	}
}
void income::output()
{
	cout<<"____________________________"<<endl;
	cout<<"Basic                : Rs. "<<basic<<endl;
	cout<<"DA                   : Rs. "<<da<<endl;
	cout<<"Deductions           : Rs. "<<ded<<endl;
	cout<<"Tax                  : Rs. "<<tax<<endl;
	cout<<"_____________________________"<<endl;
	cout<<"Total Income         : Rs. "<<(basic+da+hra-ded-tax)<<endl;
	system("pause");
}

	