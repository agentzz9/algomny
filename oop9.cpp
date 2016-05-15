#include<iostream.h>
#include<conio.h>
#include<math.h>
class shape
{
    public:
        float area(float rad,float pi)//circle
        {
            return pi*rad*rad;
        }
        float area(int side)//square
        {
            return side*side;
        }
        float area(int l,int b)//rectangle
        {
            return l*b;
        }
        float area(int p,int q,int r)//triangle
        {
            int s;
            s=(p+q+r)/2;
            return sqrt(s*(s-p)*(s-q)*(s-r));
        }
};
int main()
{
    shape obj;
    float rad;
    int side,l,b,p,q,r;
    cout<<"\nEnter radius: ";cin>>rad;
    cout<<"\nEnter side: ";cin>>side;
    cout<<"\nEnter length and breadth:: ";cin>>l>>b;
    cout<<"\nEnter 3 sides of a triangle::: ";cin>>p>>q>>r;
    cout<<"\n\nAREA:";
    cout<<"\nCircle:"<<obj.area(rad,3.14);
    cout<<"\nSquare:"<<obj.area(side);
    cout<<"\nRectangle:"<<obj.area(l,b);
    cout<<"\nTriangle:"<<obj.area(p,q,r)<<endl;
    system("pause");
    return 0;
        
}

            
        
            
            
            
