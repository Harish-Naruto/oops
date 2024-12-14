#include<iostream>
#include<string>
using namespace std;

class student{
    string name;
    int roll_no;
    string cls;
    string division;
    string dob;
    string bloodgroup;
    static int count;

    public:
    
    student(){
        name ="";
        roll_no=0;
        division="";
        dob="dd/mm/yyyy";
        bloodgroup = "";

    }
    static int getcount(){
        return count;
    }

    void getdata()
};