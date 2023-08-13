#include<iostream>
#include<windows.h>
#include<ctime>
#include<cstdlib>
#include<conio.h>
#include<fstream>
#include<vector>

using namespace std;

class timeline{
private:

int hour;
int munite;
int second;

public:
timeline() : hour(0) , munite(0) , second(0){}

timeline(int h , int m , int s) : hour(h) , munite(m) ,second(s) {}


timeline operator ++ (){
    second++;
    if(second >=60){
        munite++;
        second -=60;
        if(munite >= 60) {
            hour++;
            munite-=60;
        }
    }
        return timeline(hour,munite,second);
    }



friend ostream& operator << (ostream& os , timeline t ){
    cout<<"Hour: "<<t.hour<<endl;
    cout<<"Munite: "<<t.munite<<endl;
    cout<<"Second: "<<t.second<<endl;
    return os;
}

friend istream& operator >> (istream& is , timeline& t){
      cout<<"Hour: ";cin>>t.hour;
      cout<<"Munite: ";cin>>t.munite;
      cout<<"Second: ";cin>>t.second;
      return is;
}

timeline operator ++ (int){
   second++;
    if(second >=60){
        munite++;
        second -=60;
        if(munite >= 60) {
            hour++;
            munite-=60;
        }
    }
        return timeline(hour,munite,second);
    }



timeline operator + (timeline& t ){
    timeline T;
    T.hour = this->hour + t.hour;
    T.munite = this->munite + t.munite;
    T.second = this->second + t.second;

   if(second >=60){
        munite++;
        second -=60;
        if(munite >= 60) {
            hour++;
            munite-=60;
        }
    }

    return T;

}

timeline operator - (timeline& t){
    timeline T;
    T.hour = this->hour - t.hour;
    T.munite = this->munite - t.munite;
    T.second = this->second -t.second;
    if(second >=60){
        munite++;
        second -=60;
        if(munite >= 60) {
            hour++;
            munite-=60;
        }
    }

    return T;
}

int outh(){
    return hour;
}

int outm(){
    return munite;
}

int outs(){
    return second;
}



};

void changet(timeline& T){
    timeline t0;
    cin>>t0;
    T = t0;
}

void savefile(timeline& T){
    fstream file;
    file.open("times_save.txt",ios::app);
    file<<"Hour: "<<T.outh()<<endl;
    file<<"Munite: "<<T.outm()<<endl;
    file<<"Second: "<<T.outs()<<endl;
    file.close();
}

void show(){
    fstream file;
    file.open("times_save.txt",ios::in);
    
        string a;
        vector<string> vt;
        while(getline(file,a)){
            vt.push_back(a);
        }

        for(int i = 0 ; i<vt.size() ; i++){
            cout<<vt[i]<<endl;
        }
        file.close();
    }

void dell(){
    fstream file;
    file.open("times_save.txt",ios::out);
    file.close();
}


int main(){
timeline t(0,0,0);

while(true){
t++;
cout<<t;
cout<<"Press any key to pause and open menu..."<<endl;
if(kbhit()){
    system("cls");
    t++;
    cout<<t;
    cout<<"------------------------"<<endl;
    cout<<"1.Change timeline."<<endl;
    cout<<"2.Save timeline."<<endl;
    cout<<"3.Show timeline saved"<<endl;
    cout<<"4.Continue..."<<endl;
    cout<<"5.Delete all timeline saved"<<endl;
    cout<<"0.Close"<<endl;
    cout<<"------------------------"<<endl;
    int chose;
    cin>>chose;

    switch (chose)
    {
    case 1:
    changet(t);
    cout<<"DONE!...";
        system("pause");
        break;

    case 2:
        savefile(t);
        cout<<"DONE!...";
        system("pause");
        break;
        
    case 3:
    show();
    cout<<"DONE!...";
        system("pause");
        break;
    case 5:
    dell();
    cout<<"DONE!...";
        system("pause");
        break;
    case 4:
    break;
    case 0:
    return 0;
    }

}
Sleep(1000);
system("cls");

}
    system("pause");

}
