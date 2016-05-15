#include<iostream.h>
#include<conio.h>
class company
{
    protected:
         char name[20];
    public:
        virtual void input()
        {
            cout<<"\nName(company): ";
            gets(name);
        }
        virtual void display()
        {
            cout<<"\nCompany:"<<name<<endl;
        }
};
class laptop : public company
{
    protected:
        char modelname[20];
        float price;
    public:
        void input()
        {
            cout<<"\nLaptop Model: ";
            cin>>modelname;
            cout<<"\n Price: ";
            cin>>price;
        }
        void display()
        {
            cout<<"\nLaptop Model: "<<modelname<<endl;
            cout<<"\n price: "<<price<<endl;
        }
};
class desktop : public company
{
    protected:
        char modelname[20];
        float price;
    public:
        void input()
        {
            cout<<"\nDesktop Model: ";
            cin>>modelname;
            cout<<"\n price: ";
            cin>>price;
        }
        void display()
        {
            cout<<"\nDesktop Model: "<<modelname<<endl;
            cout<<"\n price: "<<price<<endl;
        }
};
int main()
{
    company *bptr;
    
    company B;
    desktop D1;
    laptop D2;
    
    bptr=&B;
    bptr->input();
    cout<<"\nSo, data stored is:";
    bptr->display();
    
    bptr=&D1;
    bptr->input();
    cout<<"\nSo, data stored is:";
    bptr->display();
    
    bptr=&D2;
    bptr->input();
    cout<<"\nSo, data stored is:";
    bptr->display();
    
    cout<<endl<<endl;
    system("pause");
    return 0;
    
}

