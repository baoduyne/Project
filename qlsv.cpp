#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class student{
private:

int id;
string name;
string date;

public:

student(){};
student(int msv,string ten,string tuoi): id(msv) , name(ten) , date(tuoi){};

void themsv();

void timsv(string ten);

void xoasv(int msv);

void nhapsv();

void xuatsv();

void show();

void xoatoanbo();

void xoasvtrongfile();


    vector<student> listsv;
};

void draw(){
    cout<<"-------------------------------"<<endl;
}

static int ID;


int main(){
    student sv;
ID=0;

sv.xuatsv();

goback:
string N;
int xoa;
int choice;



cout<<"1.Them sinh vien"<<endl;
cout<<"2.Xoa sinh vien"<<endl;
cout<<"3.Xem danh sach sinh vien"<<endl;
cout<<"4.Xoa toan bo danh sach sinh vien"<<endl;
cout<<"5.Tim sinh vien"<<endl;
cout<<"0.Thoat"<<endl;
draw();
cout<<"CHOSE : ";cin>>choice;
       switch(choice)

       {
            case 1:
                    draw();
                    sv.themsv();
                    cout<<"DONE...!"<<endl;
                    system("pause");
                    system("cls");
                    goto goback;
            case 2:
                   draw();
                   sv.show();
                   cout<<"Nhap msv can xoa : " ; cin >> xoa;
                   sv.xoasv(xoa);
                   cout<<"DONE...!"<<endl;
                    system("pause");
                    system("cls");
                    goto goback;

            case 3:
                draw();
                sv.show();
                cout<<"DONE...!"<<endl;
                    system("pause");
                    system("cls");
                    goto goback;
                
            case 4:
                 draw();
                 sv.xoatoanbo();
                 cout<<"DONE...!"<<endl;
                    system("pause");
                    system("cls");
                    goto goback;

            case 5:
            draw();
            cout<<"Nhap ten sinh vien can tim :"; cin >> N;
                   sv.timsv(N);
            system("pause");
            system("cls");
            goto goback;
            case 0:
            return 0;
                           default : 
                           cout<<"vui long nhap lai..."<<endl;
                           goto goback;

       }



}

void student::themsv(){
    
    string ten;
    string tuoi;

    cout<<"Name : ";cin>> ten;
    cout<<"Date : ";cin>> tuoi;


    listsv.push_back(student(ID,ten,tuoi));
    nhapsv();
    ID++;
}

void student::nhapsv(){
    fstream file;
    file.open("text2.txt",ios::app);
file<<listsv[ID].name<<endl;
file<<listsv[ID].date<<endl;
    file.close();
}

void student::timsv(string ten){
     
     for(int i = 0 ; i<ID ; i++){
        if(ten == listsv[i].name) cout<<"ID: "<<listsv[i].id<<endl;cout<<"Name : "<<listsv[i].name<<endl; cout<<"Date : "<<listsv[i].date<<endl;
     }
}

void student::show(){
    for(int i = 0 ; i<ID ; i++){
        cout<<"ID : "<<listsv[i].id<<endl;
        cout<<"Name : "<<listsv[i].name<<endl;
        cout<<"Date : "<<listsv[i].date<<endl;
    }
}

void student::xoasv(int msv){
    for(int i = 0 ; i<ID ;i++){  
        if(msv == listsv[i].id) listsv.erase(listsv.begin() + i);
    }
ID--;
xoasvtrongfile();
}

void student::xuatsv(){
    fstream file1;
    file1.open("text2.txt",ios::in);
                                   string dong;
                            
                                   int i = 0;
                                   string tuoi;
                                   string ten;
                                   
                                   while (getline(file1,dong))
                                   {
                                    
                                    if(i==1){
                                         tuoi = dong; 
                                         i=0;
                                    
                                         listsv.push_back(student(ID,ten,tuoi));
                                         ID++;
                                         goto bach;
                                    }
                                    ten = dong ;
                                    i++;
                                    bach:
                                    int p;
                                   }
                                   
                                   
    file1.close();
}

void student::xoatoanbo(){
    for(int i = 0 ; i<ID ; i++){
        listsv.erase(listsv.begin()+i);
    }
    ID = 0;
    xoasvtrongfile();
}

void student::xoasvtrongfile(){
    fstream file;
    file.open("text2.txt",ios::out);
    for(int i = 0 ; i<ID ; i++){
        file<<listsv[i].name<<endl;
        file<<listsv[i].date<<endl;
    }
    file.close();
}

