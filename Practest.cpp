#include<iostream>
using namespace std;
class complex{
    double real;
    double img;
    public:

    complex(){
        real =0;
        img =0;
    }

    complex operator+(complex &c){
        complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    complex operator*(complex &c){
        complex temp;
        temp.real = real*c.real - img*c.img;
        temp.img = real*c.img + c.real*img;
        return temp;
    }

    friend istream& operator>>(istream& in, complex &c);
    friend ostream& operator<<( ostream& out , complex &c);
};

istream& operator>>(istream& in, complex &c){
    in >> c.real >> c.img;
    return in;
}
ostream& operator<<(ostream& out , complex &c){
    out<<c.real<<"+"<<c.img<<"i"<<endl;
    return out;
}
int main(){
    complex c1,c2,c3,c4;
    int flag = 1;
    cout<<"enter real and imgnary part of first complex number: ";
    cin>>c1;
    cout<<"enter real and imgnary part of second complex number: ";
    cin>>c2;
    while(flag){
        cout<<endl;
        cout << "1. Addition of Complex Numbers" << endl;
        cout << "2. Multiplication of Complex Numbers" << endl;
        cout << "3. Exit\n";
        int a;
        cout << "Enter your choice from above MENU (1 to 3) : ";
        cin >> a;
        if(a==1){
            c3 = c1 + c2;
            cout<<"addition of two complex number is : "<<c3<<endl;
        }else if(a==2){
            c4 = c1*c2;
            cout<<"multiplication of two complex number is : "<<c4<<endl;
        }else{
            flag = 0;
        }
    }
    return 0;
}
