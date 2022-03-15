#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
struct qld
{
    string mats;
    string tents;
    int khuvuc;
    float diem1,diem2,diem3,diemuutien,tongdiem;

};
typedef struct qld QLD;
void nhap_thong_tin_1_thi_sinh(QLD &a)
{
    cout<<"nhap ma thi sinh:";
    fflush(stdin);
    getline(cin,a.mats);
    cout<<"nhap ten thi sinh:";
    getline(cin,a.tents);
    do{
         cout<<"nhap khu vuc(1/2/3):";
         cin>>a.khuvuc;
         if(a.khuvuc<1||a.khuvuc>3)
         {
             cout<<"nhap sai,vui long nhap lai!"<<endl;
         }
    }while(a.khuvuc<1||a.khuvuc>3);
    cout<<"nhap diem mon 1:";
    cin>>a.diem1;
    cout<<"nhap diem mon 2:";
    cin>>a.diem2;
    cout<<"nhap diem mon 3:";
    cin>>a.diem3;
}
void nhap_ds_thi_sinh(QLD *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"nhap thong tin thi sinh thu "<<i+1<<endl;
        nhap_thong_tin_1_thi_sinh(a[i]);
    }
}
void xuat_thong_tin_1_ts(QLD a)
{
    cout<<setw(12)<<left<<a.mats<<"  ";
    cout<<setw(20)<<left<<a.tents<<"  ";
    cout<<setw(7)<<left<<a.khuvuc<<"  ";
    cout<<setw(6)<<left<<a.diem1<<"   ";
    cout<<setw(6)<<left<<a.diem2<<"   ";
    cout<<setw(6)<<left<<a.diem3<<"   ";
    cout<<setw(6)<<left<<a.diemuutien<<"   ";
    cout<<setw(6)<<left<<a.tongdiem<<endl;
}
void xuat_ds_ts(QLD *a,int n)
{
    cout<<setw(12)<<left<<"MA THI SINH"<<"  "<<setw(20)<<left<<"TEN THI SINH"<<"  ";
    cout<<setw(7)<<left<<"KHU VUC"<<"  "<<setw(6)<<left<<"DIEM 1"<<"   ";
    cout<<setw(6)<<left<<"DIEM 2"<<"   "<<setw(6)<<left<<"DIEM 3"<<"   ";
    cout<<setw(6)<<left<<"DUTIEN"<<"   "<<setw(6)<<left<<"TD"<<endl;
    for(int i=0;i<n;i++)
    {
        xuat_thong_tin_1_ts(a[i]);
    }
}
void tinh_diem_uu_tien(QLD &a)
{
    if(a.khuvuc==1)
    {
        a.diemuutien=0.5;
    }else if(a.khuvuc==2)
    {
        a.diemuutien=1;
    }else if(a.khuvuc==3)
    {
        a.diemuutien=0;
    }
}
void tinh_tong_diem(QLD &a)
{
    a.tongdiem=a.diem1+a.diem2+a.diem3+a.diemuutien;
}
void xuat_ds_tong_diem(QLD *a,int n)
{
    cout<<setw(12)<<left<<"MA THI SINH"<<"  "<<setw(20)<<left<<"TEN THI SINH"<<"  ";
    cout<<setw(7)<<left<<"KHU VUC"<<"  ";
    cout<<setw(6)<<left<<"DUTIEN"<<"   "<<setw(6)<<left<<"TD"<<endl;
    for(int i=0;i<n;i++)
    {
        tinh_diem_uu_tien(a[i]);
        tinh_tong_diem(a[i]);
        cout<<setw(12)<<left<<a[i].mats<<"  ";
        cout<<setw(20)<<left<<a[i].tents<<"  ";
        cout<<setw(7)<<left<<a[i].khuvuc<<"  ";
        cout<<setw(6)<<left<<a[i].diemuutien<<"   ";
        cout<<setw(6)<<left<<a[i].tongdiem<<endl;
    }
}
void ts_co_tong_diem_cao_nhat(QLD *a,int n)
{
    float max=a[0].tongdiem;
    for(int i=1;i<n;i++)
    {
        if(max<a[i].tongdiem)
        {
            max=a[i].tongdiem;
        }
    }
    cout<<setw(12)<<left<<"MA THI SINH"<<"  "<<setw(20)<<left<<"TEN THI SINH"<<"  ";
    cout<<setw(7)<<left<<"KHU VUC"<<"  "<<setw(6)<<left<<"DIEM 1"<<"   ";
    cout<<setw(6)<<left<<"DIEM 2"<<"   "<<setw(6)<<left<<"DIEM 3"<<"   ";
    cout<<setw(6)<<left<<"DUTIEN"<<"   "<<setw(6)<<left<<"TD"<<endl;
    for(int i=0;i<n;i++)
    {
        if(max==a[i].tongdiem)
        {
            xuat_thong_tin_1_ts(a[i]);
        }
    }
}
void hoan_doi(QLD &a,QLD &b)
{
     QLD tg;
    tg=a;
    a=b;
    b=tg;
}
void sap_xep(QLD *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i].tongdiem<a[j].tongdiem)
            {
                hoan_doi(a[i],a[j]);
            }
        }
    }
    xuat_ds_ts(a,n);
}
void them_ts(QLD *a,int &n)
{
    
    for(int i=0;i<n-1;i++)
    {
         for(int j=i+1;j<n;j++)
         {
              if(a[i].tongdiem<a[j].tongdiem)
              {
                  hoan_doi(a[i],a[j]);
              }
        }
    }
    QLD b;
    cout<<"NHAP THONG TIN THI SINH CAN THEM:"<<endl;
    nhap_thong_tin_1_thi_sinh(b);
    int x=0;
    tinh_diem_uu_tien(b);
    tinh_tong_diem(b);
    for(int i=0;i<n;i++)
    {
        if(b.tongdiem<a[i].tongdiem)
        {
            x++;
        }
    }
    for(int j=n;j>x;j--)
    {
        a[j]=a[j-1];
    }     
    a[x]=b;
    n++;
    xuat_ds_ts(a,n);
}
void xoa(QLD *a,int &n)
{
    float diemchuan;
    cout<<"NHAP DIEM CHUAN:";
    cin>>diemchuan;
    for(int i=0;i<n;i++)
    {
        if(a[i].tongdiem<diemchuan)
        {
            for(int j=i;j<n;j++)
            {
                a[j]=a[j+1];
            }
            n--;
            i=i-2;
        }
    }
     xuat_ds_ts(a,n);
}
void doc_file_1_ts(ifstream &filein,QLD &b)
{
    string x;
    getline(filein,x,'\n');
    getline(filein,x,':');
    getline(filein,b.mats,'\n');
    getline(filein,x,':');
    getline(filein,b.tents,'\n');
    getline(filein,x,':');
    filein>>b.khuvuc;
    getline(filein,x,'\n');
    getline(filein,x,':');
    filein>>b.diem1;
    getline(filein,x,'\n');
    getline(filein,x,':');
    filein>>b.diem2;
    getline(filein,x,'\n');
    getline(filein,x,':');
    filein>>b.diem3;
    getline(filein,x,'\n');
    getline(filein,x,':');
    filein>>b.diemuutien;
    getline(filein,x,'\n');
    getline(filein,x,':');
    filein>>b.tongdiem;
    getline(filein,x,'\n');

}
void doc_file_danh_sach_ts(ifstream &filein,QLD *b,int n)
{
    for(int i=0;i<n;i++)
    {
        doc_file_1_ts(filein,b[i]);
    }
}
void ghi_file_ds_ts(ofstream &fileout,QLD *a,int n)
{
     for(int i=0;i<n;i++)
     {
        fileout<<"thi sinh thu "<<i+1;
        fileout<<"\nma thi sinh:"<<a[i].mats;
        fileout<<"\nten thi sinh:"<<a[i].tents;
        fileout<<"\nkhu vuc:"<<a[i].khuvuc;
        fileout<<"\ndiem 1:"<<a[i].diem1;
        fileout<<"\ndiem 2:"<<a[i].diem2;
        fileout<<"\ndiem 3:"<<a[i].diem3;
        fileout<<"\ndiem uu tien:"<<a[i].diemuutien;
        fileout<<"\ntong diem:"<<a[i].tongdiem<<endl;
     }
          
}
void menu(QLD *a,QLD *b,int &n)
{
    int luachon;
    while(true)
    {
        system("cls");
        cout<<"=================================MENU==============================";
        cout<<"\n_____________________________________________________________________";
        cout<<"\n|\t\t1.NHAP DANH SACH THI SINH                           |";
        cout<<"\n|\t\t2.TINH DIEM UU TIEN-TONG DIEM                       |";
        cout<<"\n|\t\t3.XUAT DANH SACH THI SINH                           |";
        cout<<"\n|\t\t4.XUAT THONG TIN THI SINH CO DIEM CAO NHAT          |";
        cout<<"\n|\t\t5.SAP XEP DS THEO THU TU GIAM DAN CUA TONG DIEM     |";
        cout<<"\n|\t\t6.THEM THI SINH                                     |";
        cout<<"\n|\t\t7.XOA THI SINH                                      |";
        cout<<"\n|\t\t8.LUU DANH SACH THI SINH RA TEP thisinh.dat         |";
        cout<<"\n|\t\t9.DOC DANH SACH THI SINH TU TEP thisinh.dat         |";
        cout<<"\n|\t\t0.THOAT                                             |";
        cout<<"\n_____________________________________________________________________";
        cout<<"\n=================================ENDL================================="<<endl;
        do{
              cout<<"nhap lua chon:";
              cin>>luachon;
              if(luachon<0||luachon>9)
              {
                  cout<<"lua chon sai,vui long nhap lai lua chon!"<<endl;
              }
        }while(luachon<0||luachon>9);
        if(luachon==1)
        {
            nhap_ds_thi_sinh(a,n);
        }else if(luachon==2)
        {
            xuat_ds_tong_diem(a,n);
            system("pause");
        }else if(luachon==3)
        {
            xuat_ds_ts(a,n);
           system("pause");
        }else if(luachon==4)
        {
            ts_co_tong_diem_cao_nhat(a,n);
            system("pause");
            
        }else if(luachon==5)
        {
            sap_xep(a,n);
            system("pause");
            
        }else if(luachon==6)
        {
            them_ts(a,n);
            system("pause");
            
        }else if(luachon==7)
        {
            xoa(a,n);
            system("pause");
            
        }else if(luachon==8)
        {
        	
            ofstream fileout;
            fileout.open("thisinh.dat.txt",ios_base::out);
            ghi_file_ds_ts(fileout,a,n);
            fileout.close();
            cout<<"Ghi file thanh cong"<<"\n";
            system("pause");
        }
        else if(luachon==9)
       	{
            ifstream filein;
            filein.open("thisinh.dat.txt",ios_base::in);
            doc_file_danh_sach_ts(filein,b,n);
            filein.close();
            xuat_ds_ts(b,n);
            system("pause");
		}
            
		else if(luachon==0)
 		{
            break;
  		}

    }
}
int main()
{
    int n;
    cout<<"nhap so luong thi sinh:";
    cin>>n;
    QLD a[100];
    QLD b[100];
    menu(a,b,n);
return 0;
}