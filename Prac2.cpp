#include<iostream>
#include<string>
using namespace std;

class StudData;

class Student {
    string name;
    int roll_no;
    string cls;
    string division;    // Changed from char* to string
    string dob;
    string bloodgroup;  // Changed from char* to string
    static int count;

public:
    Student()          // Default Constructor
    {
        name = "";
        roll_no = 0;
        cls = "";
        division = "";
        dob = "dd/mm/yyyy";
        bloodgroup = "";
    }

    // Removed destructor since we no longer use dynamic memory for division and bloodgroup
    
    static int getCount()
    {
        return count;
    }

    void getData(StudData*);
    void dispData(StudData*);
};

class StudData {
    string caddress;
    long int* telno;
    long int* dlno;
    friend class Student;

public:
    StudData()
    {
        caddress = "";
        telno = new long;
        dlno = new long;
    }

    void getStudData()
    {
        cout << "Enter Contact Address : ";
        cin.get();
        getline(cin, caddress);
        cout << "Enter Telephone Number : ";
        cin >> *telno;
        cout << "Enter Driving License Number : ";
        cin >> *dlno;
    }

    void dispStudData()
    {
        cout << "Contact Address : " << caddress << endl;
        cout << "Telephone Number : " << *telno << endl;
        cout << "Driving License Number : " << *dlno << endl;
    }

    ~StudData()
    {
        delete telno;
        delete dlno;
    }
};

inline void Student::getData(StudData* st)
{
    cout << "Enter Student Name : ";
    getline(cin, name);
    cout << "Enter Roll Number : ";
    cin >> roll_no;
    cout << "Enter Class : ";
    cin.get();
    getline(cin, cls);
    cout << "Enter Division : ";
    cin.get();
    getline(cin, division);  // Changed to use getline for string
    cout << "Enter Date of Birth : ";
    getline(cin, dob);
    cout << "Enter Blood Group : ";
    getline(cin, bloodgroup);  // Changed to use getline for string
    st->getStudData();
    count++;
}

inline void Student::dispData(StudData* st1)
{
    cout << "Student Name : " << name << endl;
    cout << "Roll Number : " << roll_no << endl;
    cout << "Class : " << cls << endl;
    cout << "Division : " << division << endl;
    cout << "Date of Birth : " << dob << endl;
    cout << "Blood Group : " << bloodgroup << endl;
    st1->dispStudData();
}

int Student::count;

int main()
{
    Student* stud1[100];
    StudData* stud2[100];
    int n = 0;
    char ch;

    do
    {
        stud1[n] = new Student;
        stud2[n] = new StudData;
        stud1[n]->getData(stud2[n]);
        n++;
        cout << "Do you want to add another student (y/n) : ";
        cin >> ch;
        cin.get();  // Added to consume newline
        cout << endl;
    } while (ch == 'y' || ch == 'Y');

    for(int i = 0; i < n; i++)
    {
        cout << "---------------------------------------------------------------" << endl;
        stud1[i]->dispData(stud2[i]);
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students : " << Student::getCount();
    cout << endl << "---------------------------------------------------------------" << endl;

    for(int i = 0; i < n; i++)
    {
        delete stud1[i];
        delete stud2[i];
    }

    return 0;
}