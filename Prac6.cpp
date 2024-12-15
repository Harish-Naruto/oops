#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class item{
    public:
    string name;
    int cost;
    int quantity;
    int itemcode;
    
    void getdate(){
        cout<<"Enter the name of item : ";
        cin>>name;
        cout<<"Enter quantity: ";
        cin>>quantity;
        cout<<"Enter the cost : ";
        cin>>cost;
        cout<<"Enter the item code: ";
        cin>>itemcode;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Cost: "<<cost<<endl;
        cout<<"Item code: "<<itemcode<<endl;
    }
};

vector<item>oi;

bool compare(item& a , item& b){
    return a.cost > b.cost;
}

void insert(){
    item i;
    i.getdate();
    oi.push_back(i);
}

void search(){
    int code;
    cout<<"enter the code of item you want to search : ";
    cin>>code;
    for(auto i : oi){
        if(i.itemcode == code){
            i.display();
            return;
        }
    }
    cout<<"item not found"<<endl;
}

void sort(){
    sort(oi.begin(),oi.end(),compare);
    cout<<"itmes are sorteed"<<endl;
}

void remove(){
    int code;
    cout<<"enter the code of item to be deleted: ";
    cin>>code;
    for(auto it = oi.begin(); it != oi.end(); ++it) {
        if(it->itemcode == code) {
            oi.erase(it);
            cout << "\nItem deleted successfully!" << endl;
            return;
        }
    }
    cout<<"item cdoe not found"<<endl;
}

void display_all(){
    for(auto i : oi){
        i.display();
        cout<<"-------------------"<<endl;
    }
}
int main(){
    int choice;
    do {
        cout << "\n=== Item Management System ===" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Display All Items" << endl;
        cout << "3. Search Item" << endl;
        cout << "4. Sort Items by Cost" << endl;
        cout << "5. Delete Item" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: insert(); break;
            case 2: display_all(); break;
            case 3: search(); break;
            case 4: sort(); break;
            case 5: remove(); break;
            case 6: cout << "\nExiting program...\n"; break;
            default: cout << "\nInvalid choice! Try again.\n";
        }
    } while(choice != 6);

    return 0;
}
