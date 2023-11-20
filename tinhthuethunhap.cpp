#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void case_1(float &HMTT1,float &HMTT2){
    goback:

    float hmtt_nld,hmtt_npt;

   cout<<"Nhap han muc mien tru thue doi voi nguoi lao dong: ";cin>>hmtt_nld;
   if(hmtt_nld<=0){ 
    
    cout<<"So tien khong duoc nho hon 0...";
    system("pause");
    system("cls");
    goto goback;
   }

   cout<<"Nhap han muc mien tru thue doi voi nguoi phu thuoc: ";cin>>hmtt_npt;
   if(hmtt_npt<=0){ 
    
    cout<<"So tien khong duoc nho hon 0...";
    system("pause");
    system("cls");
    goto goback;
   }

   cout<<"Da thay doi han muc tinh thue : "<<endl;
   cout<<"Voi nguoi lao dong: "<<hmtt_nld<<" trieu dong"<<endl;
   cout<<"Voi nguoi phu thuoc: "<<hmtt_npt<<" trieu dong"<<endl;
   
   HMTT1 = hmtt_nld; HMTT2 = hmtt_npt;

}

void case_2(string *ten , int &so_nguoi_phu_thuoc  , int &nam_tinh_thue){
      
      goback:
      string name ; int snpt; int ntt;

      cout<<"Ten: "; cin>>name;

      for(int i = 33 ; i <=64 ;i++){
        if(name[i] == i ) {
            cout<<"Ten khong duoc chua ky tu dac biet..."<<endl;
            goto goback;
        }
      }

      cout<<"So nguoi phu thuoc: "; cin>>snpt;
      
      cout<<"Nam tinh thue: "; cin>>ntt;
      (*ten) = name;
      
      so_nguoi_phu_thuoc = snpt;
      nam_tinh_thue=ntt;
       
      cout<<"Thong tin duoc cap nhat: "<<endl;
      cout<<"Ten: "<<*ten<<endl;
      cout<<"So nguoi phu thuoc: "<<snpt<<endl;
      cout<<"Nam tinh thue: "<<nam_tinh_thue<<endl;


}



void case_3(string ten , int snpt , int ntt , float hmmtt_nld,float hmtt_npt,float *tnt,float *thue){
     goback:
     system("cls");
     int thang;float sotien;

     cout<<"Ten: "<<ten<<endl;
     cout<<"Nam tinh thue: "<<ntt<<endl;
     cout<<""<<endl; cout<<"Nhap thang: ";cin>>thang; 
     
     if(thang<=0 || thang >12){
        cout<<"Thang khong hop le..."<<endl;
        system("pause");
        goto goback;
     }
    

     cout<<"Nhap thu nhap thang "<<thang<<" :";cin>>sotien;

     *(tnt+thang) = sotien;

     float muc_thue = (sotien - hmmtt_nld - (hmtt_npt*snpt)) ;
     

     if(sotien<=0){
        cout<<"So tien khong hop le..."<<endl;
        system("pause");
        goto goback;
     }

     if(sotien<hmmtt_nld){
        cout<<"So thue phai nop = 0 (vnd)"<<endl;
     }

     else {
           if(muc_thue <= 5){
             *(thue+thang) = muc_thue*0.05;
           }
           else if(muc_thue<=10){
             *(thue+thang) = muc_thue*0.1 -0.25;
           }
           else if(muc_thue>10&&muc_thue<=18){
             *(thue+thang) = muc_thue*0.15 -0.75;
           }
           else if(muc_thue>18&& muc_thue<=32){
            *(thue+thang) = muc_thue*0.2 -1.65;
           }
           else if(muc_thue>32&& muc_thue<=52){
            *(thue+thang) = muc_thue*0.25 -3.25;
           }
           else if(muc_thue>52&& muc_thue<=80){
            *(thue+thang) = muc_thue*0.30 -5.85;
           }
           else if(muc_thue>80){
            *(thue+thang) = muc_thue*0.35 -9.85;
           }
           if(*(thue+thang)<0){
            *(thue+thang) = 0;
           }
           cout<<"So thue phai nop = "<<*(thue+thang)<<" trieu dong."<<endl; 
     }





}

void case_4(string ten , int snpt , int ntt, float tnt[12], float thue[12]){

cout<<"Ten                : "<<ten<<endl;
cout<<"So nguoi phu thuoc : "<<snpt<<endl;
cout<<"Nam tinh thue      : "<<ntt<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;

cout<<"Thang                  Thu nhap            Thue thu nhap     "<<endl;
cout<<""<<endl;
for(int i = 1 ; i <=12 ; i++){
if(i>=10){
   cout<<" "<<i<<"                        "<<tnt[i]<<"                    "<<thue[i]<<endl;
   continue;
}
cout<<" "<<i<<"                         "<<tnt[i]<<"                    "<<thue[i]<<endl;
}
cout<<""<<endl;
cout<<""<<endl;

}



int main(){

   string ten; int so_nguoi_phu_thuoc; int nam_tinh_thue;float thu_nhap_thang[12]; float thue[12];
   
   float HMMTT_nguoi_lao_dong; float HMMTT_nguoi_phu_thuoc;
 
   for(int i = 0 ; i <= 12 ; i ++ ){ 
    thu_nhap_thang[i] = 0;
    thue[i] = 0;
   }
   

goback:

cout<<"1.Thiet lap cac han muc mien tru thue ."<<endl;
cout<<"2.Thiet lap cac tham so anh huong den thue cua nguoi lao dong."<<endl;
cout<<"3.Tinh thue thu nhap ."<<endl;
cout<<"4.Quyet toan thue thu nhap ca nam."<<endl;
cout<<"0.End..."<<endl;

cout<<"Don vi: Trieu dong."<<endl;

int choice;cin>>choice;


switch(choice){
case 1 :

         case_1(HMMTT_nguoi_lao_dong,HMMTT_nguoi_phu_thuoc);
         system("pause");
         system("cls");
         goto goback;

case 2 :
        case_2(&ten,so_nguoi_phu_thuoc,nam_tinh_thue);
        system("pause");
        system("cls");
        goto goback;

case 3 :
        case_3(ten,so_nguoi_phu_thuoc,nam_tinh_thue,HMMTT_nguoi_lao_dong,HMMTT_nguoi_phu_thuoc,thu_nhap_thang,thue);
        system("pause");
        system("cls");
        goto goback;

case 4 :
        case_4(ten,so_nguoi_phu_thuoc,nam_tinh_thue,thu_nhap_thang,thue);
        system("pause");
        system("cls");
        goto goback;

case 0 : 
return 0 ;

default:
cout<<"Chuc nang khong ton tai..."<<endl;
system("pause");
system("cls");
goto goback;

}



}