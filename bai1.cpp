#include <iostream>     // std::cin, std::cout
#include <stdio.h>
#include<conio.h>
#include <fstream>
#include <string>
#include<vector>
#include<time.h>
#include<windows.h>
#include <cstdlib>
using namespace std;

void resizeConsole(int width,int height)	//thay doi kich co man hinh
{
	HWND console=GetConsoleWindow();
	RECT r;
	GetWindowRect(console,&r);
	MoveWindow(console,r.left,r.top,width,height,TRUE);
}
void textcolor(int x)	//doi mau chu
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void XoaManHinh()	//xoa man hinh
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
void menu(int mod)
{gotoxy(30,5);
if(mod==1)
textcolor(14);
else textcolor(7);
cout<<"1.Them ban ghi";
textcolor(7);
gotoxy(30,6);
if(mod==2)
textcolor(14);
else textcolor(7);
cout<<"2.Liet ke Danh ba";
textcolor(7);
gotoxy(30,7);
if(mod==3)
textcolor(14);
else textcolor(7);
cout<<"3.Sua ban ghi";
textcolor(7);
gotoxy(30,8);
if(mod==4)
textcolor(14);
else textcolor(7);
cout<<"4.Xoa ban ghi";
textcolor(7);
gotoxy(30,9);
if(mod==5)
textcolor(14);
else textcolor(7);
cout<<"5.Tim kiem thong tin";
textcolor(7);
gotoxy(30,10);
if(mod==6)
textcolor(14);
else textcolor(7);
cout<<"6.exit";
textcolor(7);
gotoxy(25,13);
cout<<"Nhan w,s de di chuyen option";
gotoxy(25,14);
cout<<"Nhan space de chon";
}
struct danhba
{char mod[10];
char ten[40];
char gt[10];
char sdt[12];
char email[40];
char dc[40];
};
typedef struct danhba danhba;
void Nhapdanhba(ifstream &filein,danhba &danhba)
{	char temp[255];
	filein.getline(temp, 255);
	strcpy(danhba.ten,temp);
	fflush(stdin);
	filein.getline(temp, 255);
	strcpy(danhba.gt,temp);
	fflush(stdin);
	filein.getline(temp, 255);
	strcpy(danhba.sdt,temp);
	fflush(stdin);
	filein.getline(temp, 255);
	strcpy(danhba.email,temp);
	fflush(stdin);
	filein.getline(temp, 255);
	strcpy(danhba.dc,temp);
}
void Nhapdanhba2(ifstream &filein, vector<danhba> &ds)
{while (filein.eof()==false)
{danhba danhba;
Nhapdanhba(filein,danhba);
ds.push_back(danhba);
}
}
void Nhapdanhba3(danhba &danhba)
{fflush(stdin);
cout<<"Nhap ten:";
gets(danhba.ten);
cout<<endl;
	fflush(stdin);
cout<<"Nhap gt:";
gets(danhba.gt);
cout<<endl;
	fflush(stdin);
cout<<"Nhap sdt:";
gets(danhba.sdt);
cout<<endl;
	fflush(stdin);
cout<<"Nhap email:";
gets(danhba.email);
cout<<endl;
	fflush(stdin);
cout<<"Nhap dc:";
gets(danhba.dc);
cout<<endl;
	fflush(stdin);
}
void Xuatdanhba(danhba danhba)
{cout<<"Ten: "<<danhba.ten<<endl;
cout<<"GT: "<<danhba.gt<<endl;
cout<<"Sdt: "<<danhba.sdt<<endl;
cout<<"Email: "<<danhba.email<<endl;
cout<<"Dc: "<<danhba.dc<<endl;
}
void copy(danhba danhba1,danhba danhba2)
{strcpy(danhba1.ten,danhba2.ten);
strcpy(danhba1.gt,danhba2.gt);
strcpy(danhba1.sdt,danhba2.sdt);
strcpy(danhba1.email,danhba2.email);
strcpy(danhba1.dc,danhba2.dc);
}
int main()
{
ifstream filein;
filein.open("danhba.txt",ios_base::in);
vector<danhba> dsdanhba;
Nhapdanhba2(filein,dsdanhba);
filein.close();
tt:
system("cls");
int modemenu=1;
while(true)
{
menu(modemenu);
Sleep(100);
if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c=='s'&& modemenu<6) modemenu++;
	if(c=='w'&& modemenu>1) modemenu--;
	if(c==' ') break;
}
}

tk:
if(modemenu==2)
{system("cls");
for(int i=0;i<dsdanhba.size();i++)
{cout<<"===========================STT: "<<i+1<<"==========================="<<endl;
Xuatdanhba(dsdanhba[i]);
}
cout<<"\n\n\nNhan R de quay ve menu chinh";
cout<<endl<<"Nhan E de thoat";
cout<<endl<<"Nhan T de them ban ghi";
cout<<endl<<"Nhan S de sua ban ghi";
cout<<endl<<"Nhan X de xoa ban ghi";
while(true)
{if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c=='r') goto tt;
	if(c=='t') {modemenu=1;goto tk;}
	if(c=='s') {modemenu=3;goto tk;}
	if(c=='x') {modemenu=4;goto tk;}
	if(c=='e') break;
}
}
}

if(modemenu==1)
{system("cls");
danhba tam;
Nhapdanhba3(tam);
dsdanhba.push_back(tam);
 ofstream outfile;
   outfile.open("danhba.txt");
for(int i=0;i<dsdanhba.size();i++)
{if(i==0) outfile<<dsdanhba[i].ten<<endl;
else
outfile<<endl<<dsdanhba[i].ten<<endl;
outfile<<dsdanhba[i].gt<<endl;
outfile<<dsdanhba[i].sdt<<endl;
outfile<<dsdanhba[i].email<<endl;
outfile<<dsdanhba[i].dc;
}
cout<<endl<<"\t\t\t\tThem thanh cong";
cout<<"\nNhan R de quay ve menu chinh";
cout<<endl<<"Nhan E de thoat";
cout<<endl<<"Nhan L de liet ke danh ba";
while(true)
{if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c=='r') goto tt;
	if(c=='l') {modemenu=2;goto tk;}
	if(c=='e') break;
}
}
outfile.close();
}
if(modemenu==3)
{t3:
system("cls");
int vt;
cout<<"Nhap vao vi tri ban ghi"<<endl;
cin>>vt;

if(vt>dsdanhba.size()||vt<=0) cout<<"Khong co ban ghi";
else
{
vt=vt-1;
cout<<"Ban ghi muon sua doi:"<<endl;
cout<<dsdanhba[vt].ten<<endl;
cout<<dsdanhba[vt].gt<<endl;
cout<<dsdanhba[vt].sdt<<endl;
cout<<dsdanhba[vt].email<<endl;
cout<<dsdanhba[vt].dc<<endl;
cout<<"Co phai muon sua ban ghi nay(y/n/m to menu)?";
char c;
c=getch();
if(c=='n') goto t3;
else if (c=='m') goto tt;
danhba tam2;
cout<<endl;
Nhapdanhba3(tam2);
strcpy(dsdanhba[vt].ten,tam2.ten);
strcpy(dsdanhba[vt].gt,tam2.gt);
strcpy(dsdanhba[vt].sdt,tam2.sdt);
strcpy(dsdanhba[vt].email,tam2.email);
strcpy(dsdanhba[vt].dc,tam2.dc);
ofstream outfile;
   outfile.open("danhba.txt");
for(int i=0;i<dsdanhba.size();i++)
{if(i==0) outfile<<dsdanhba[i].ten<<endl;
else
outfile<<endl<<dsdanhba[i].ten<<endl;
outfile<<dsdanhba[i].gt<<endl;
outfile<<dsdanhba[i].sdt<<endl;
outfile<<dsdanhba[i].email<<endl;
outfile<<dsdanhba[i].dc;
}
cout<<"Sua thanh cong"<<endl;
cout<<"Nhan R de quay ve menu chinh";
cout<<endl<<"Nhan E de thoat";
cout<<endl<<"Nhan L de liet ke danh ba";
while(true)
{if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c=='r') goto tt;
	if(c=='l') {modemenu=2;goto tk;}
	if(c=='e') break;
}
}
}
}
if(modemenu==4)
{t4:
system("cls");
int vt;
cout<<"Nhap vao vi tri ban ghi muon xoa"<<endl;
cin>>vt;

if(vt>dsdanhba.size()||vt<=0) cout<<"Khong co ban ghi";
else
{
vt=vt-1;
cout<<"Ban ghi muon xoa:"<<endl;
cout<<dsdanhba[vt].ten<<endl;
cout<<dsdanhba[vt].gt<<endl;
cout<<dsdanhba[vt].sdt<<endl;
cout<<dsdanhba[vt].email<<endl;
cout<<dsdanhba[vt].dc<<endl;
cout<<"Co phai muon xoa nay(y/n/m to menu)?";
char c;
c=getch();
if(c=='n') goto t4;
else if(c=='m') goto tt;
dsdanhba.erase(dsdanhba.begin()+vt);
 ofstream outfile;
   outfile.open("danhba.txt");
for(int i=0;i<dsdanhba.size();i++)
{if(i==0) outfile<<dsdanhba[i].ten<<endl;
else
outfile<<endl<<dsdanhba[i].ten<<endl;
outfile<<dsdanhba[i].gt<<endl;
outfile<<dsdanhba[i].sdt<<endl;
outfile<<dsdanhba[i].email<<endl;
outfile<<dsdanhba[i].dc;
cout<<"Xoa thanh cong"<<endl;
cout<<"Nhan R de quay ve menu chinh";
cout<<endl<<"Nhan E de thoat";
cout<<endl<<"Nhan L de liet ke danh ba";
while(true)
{if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c=='r') goto tt;
	if(c=='l') {modemenu=2;goto tk;}
	if(c=='e') break;
}
}
}
}
}
if(modemenu==5)
{system("cls");
char temp2[255],*s;
printf("Nhap ten can tim kiem: ");
gets(temp2);
for(int i=0;i<dsdanhba.size();i++)
{s=strstr(dsdanhba[i].ten,temp2);
if(s!=NULL) 
{cout<<"===========================STT: "<<i+1<<"==========================="<<endl;
Xuatdanhba(dsdanhba[i]);
}
}

}




}


