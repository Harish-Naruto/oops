#include<iostream>
#include<stdio.h>
using namespace std;
class publication
{
    private:
    string title;
    float prices;
    public:
    void getpub(){
        cout<<"Enter the name of Publication: ";
        cin.ignore();
        getline(cin,title);
        cout<<"Enter the prices: ";
        cin>>prices;
    }
    void display(){
        cout<<"\n----------------------------";
        cout<<"\ntitle of Publication : "<<title;
        cout<<"\nPrices: "<<prices;

    }
};

class book : public publication {
    int page_count;
    public:
    void getbook(){
        try{
            getpub();
            cout<<"\nenter the number of pages in book: ";
            cin>>page_count;
            if(page_count<=0){
                throw page_count;
            }
        }
        catch(...){
            cout<<"\npage count is invalid";
            page_count = 0;
        }
    }

    void display_book(){
        display();
        cout<<"\nPage count : "<<page_count;
        cout<<"\n----------------------\n";
    }
};

class tape : public publication{
    int play;
    public:
    void gettape(){
        getpub();
        try{
            cout<<"\nEnter the play duration of the tape: ";
            cin>>play;
            if(play<=0){
                throw play;
            }
        }
        catch(...){
            cout<<"\nplay time is invalid";
            play = 0;
        }
    }
    void displaytape(){
        display();
        cout<<"Play time: "<<play<<endl;
        cout<<"\n-------------------\n";

    }
};
int main(){
    book b[100];
    tape t[100];
    int n;
    int book_count = 0;
    int tape_count = 0;
    int flag = 1;

    while(flag){
        cout<<"\n------menu------\n";
        cout<<"\n1)add books";
        cout<<"\n2)add tape";
        cout<<"\n3)display books";
        cout<<"\n4)display tape";
        cout<<"\nEnter the choice : ";
        cin>>n;
        switch(n)
        {
            case 1:
                b[book_count].getbook();
                book_count++;
                break;
            case 2:
                t[tape_count].gettape();
                tape_count++;
                break;
            case 3:
                for(int i = 0; i < book_count ; i++){
                    b[i].display_book();
                }
                break;
            case 4:
                for(int i = 0 ; i < tape_count; i++){
                    t[i].displaytape();
                }
                break;
            case 5:
                flag = 0;
                exit(0);
        }
    }
    return 0;
}