#include<iostream.h>
#include<conio.h>
class road_vehicle
{
    protected:
        int speed;
    public:
        void inc_speed()
        {
            speed++;
        }
        void input()
        {
            cin>>speed;
        }
        void output()
        {

            cout<<"Speed: "<<speed<<endl;
        }
        void dec_speed()
        {
            speed--;
        }
};
class automobile : public road_vehicle
{
    public:
        automobile() { speed=100; }
};
class truck : public automobile
{
    public:
        truck() { speed=80; }
};
int main()
{
    char ch;
    automobile obj1;
    truck obj2;
    cout<<"Automobile speed initialized with Constructor:";
    obj1.output();
    cout<<"Truck speed initialized with Constructor:";
    obj2.output();
    cout<<endl<<"Want to increase(y)/decrease Truck's speed??";
    cin>>ch;
    if(ch=='y')
    {
        obj2.inc_speed();
        cout<<"New values:\n";
        cout<<"Automobile: ";
        obj1.output();
        cout<<"\nTruck: ";
        obj2.output();
    }
    else
    {
        obj1.dec_speed();
        cout<<"\n\n\nNew values:\n\n";
        cout<<"Automobile: ";
        obj1.output();
        cout<<"Truck: ";
        obj2.output();
    }
    system("pause");
    return 0;
}
    
    
    
    
    
