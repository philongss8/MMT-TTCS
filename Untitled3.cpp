#include <iostream>     // std::cin, std::cout
#include <stdio.h>
#include<conio.h>
#include <fstream>
#include <string>
#include<vector>
#include "console.h"
#include<time.h>
#include<windows.h>
#include <cstdlib>
using namespace std;
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
struct diem
{string ten;
int diem;
};
typedef struct diem diem;
void nhapdiem(ifstream &filein,diem &diem)
{string s;
   getline(filein,s,',');
   diem.ten=s;
   getline(filein,s);
   diem.diem=atoi(s.c_str());  
}
void nhapdiem2(ifstream &filein, vector<diem> &ds)
{while (filein.eof()==false)
{diem diem;
nhapdiem(filein,diem);
ds.push_back(diem);
}
}
void xuatdiem(diem diem)
{
cout<<"Ten nguoi choi: "<<diem.ten;
cout<<"\tDiem so: "<<diem.diem;
}
void xuatdiem2(vector<diem> ds)
{for(int i=0;i<ds.size()-1;i++)
{gotoxy(5,i);
cout<<"Ten nguoi choi: "<<ds[i].ten;
gotoxy(40,i);
cout<<"Diem so"<<ds[i].diem;
}
}
void Pause(int mod)
{gotoxy(35,5);
cout<<"Pause game";
if(mod==1) textcolor(14);
else textcolor(7);
gotoxy(20,6);
cout<<"Tiep tuc"<<endl;
textcolor(7);
if(mod==2) textcolor(14);
else textcolor(7);
gotoxy(50,6);
cout<<"Ket thuc"<<endl;
textcolor(7);
}
void Playagain(int mod)
{gotoxy(35,5);
cout<<"Play again?";
if(mod==1) textcolor(14);
else textcolor(7);
gotoxy(20,6);
cout<<"Yes"<<endl;
textcolor(7);
if(mod==2) textcolor(14);
else textcolor(7);
gotoxy(40,6);
cout<<"No"<<endl;
textcolor(7);
if(mod==3) textcolor(14);
else textcolor(7);
gotoxy(60,6);
cout<<"Save point"<<endl;
textcolor(7);
}
struct detn
{string cauhoi;
string dapan1;
string dapan2;
string dapan3;
string dapan4;
string dapand;
};
typedef struct detn detn;


void doc1(ifstream &filein,detn &detn)
{
	getline(filein,detn.cauhoi);
	getline(filein,detn.dapan1);
	getline(filein,detn.dapan2);
	getline(filein,detn.dapan3);
	getline(filein,detn.dapan4);
	getline(filein,detn.dapand);
}
void doc2(ifstream &filein, vector<detn> &ds)
{while (filein.eof()==false)
{detn detn;
doc1(filein,detn);
ds.push_back(detn);
}
}
void xuat1(detn detn,int mod,int mod2)
{
gotoxy(10,0);
cout<<"Cau hoi: "<<detn.cauhoi<<endl;
if(mod==1) textcolor(14);
else textcolor(7);
cout<<"A. "<<detn.dapan1<<endl;
textcolor(7);
if(mod==2) textcolor(14);
else textcolor(7);
cout<<"B. "<<detn.dapan2<<endl;
textcolor(7);
if(mod==3) textcolor(14);
else textcolor(7);
cout<<"C. "<<detn.dapan3<<endl;
textcolor(7);
if(mod==4) textcolor(14);
else textcolor(7);
cout<<"D. "<<detn.dapan4<<endl;
textcolor(7);
cout<<"DA "<<detn.dapand<<endl;
cout<<mod;
cout<<endl;
if(mod2==1) cout<<"Dap an sai";
else if(mod2==2) cout<<"Dap an dung";
}
void menu(int mod)
{{gotoxy(35,5);
cout<<"Menu";
if(mod==1) textcolor(14);
else textcolor(7);
gotoxy(35,7);
cout<<"De 1"<<endl;
textcolor(7);
if(mod==2) textcolor(14);
else textcolor(7);
gotoxy(35,8);
cout<<"De 2"<<endl;
textcolor(7);
if(mod==3) textcolor(14);
else textcolor(7);
gotoxy(35,9);
cout<<"XH diem cao"<<endl;
textcolor(7);
}
}




int main()
{tk:
int modmenu=1;
int modde=1;
while(modmenu!=0)
{menu(modmenu);
if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c=='s'&& modmenu==2) modmenu=3;
	if(c=='s'&& modmenu==1) modmenu=2;
	if(c=='w'&& modmenu==2) modmenu=1;
	if(c=='w'&& modmenu==3) modmenu=2;
	if(c==' '&& modmenu==1) {modmenu=0;modde=1;
	}
	if(c==' '&& modmenu==2) {modmenu=0;modde=2;
	}
	if(c==' '&& modmenu==3) {modmenu=0;modde=3;
	}
}}


ifstream filein;
if(modde==1)
filein.open("cauhoi.txt",ios_base::in);
else if(modde==2)
filein.open("cauhoi2.txt",ios_base::in);
system("cls");
while(modde==3)
{ifstream filein;
filein.open("diem.txt",ios_base::in);
vector<diem> dsdiem;
nhapdiem2(filein,dsdiem);
xuatdiem2(dsdiem);
filein.close();
if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c==' ') {modde=1;system("cls");goto tk;
	}
}
}








vector<detn> ds;
doc2(filein,ds);
int diem=0;
int mp=1;
int i=0;
int kt=0;
int max=ds.size()-1;
int *mod;
int *dtl;
dtl=new int[max];
mod=new int[max];
int pause=0;
for(int i=0;i<=max;i++)
{dtl[i]=0;
mod[i]=1;
}

while(kt!=1)
{
xuat1(ds[i],mod[i],dtl[i]);

string da=ds[i].dapand;
while (pause==1)
{system("cls");
Pause(mp);
if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c=='d'&& mp==1) mp=2;
	if(c=='a'&& mp==2) mp=1;
	if(c==' ')
	{if (mp==2) goto tt;
	else {system("cls");
	pause=0;}
	}
}
Sleep(50);
}
if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c=='d'&&i<max) {
	i++;system("cls");}
	if(c=='a'&&i>0) {
	i--;system("cls");}
	if(c=='e')
	{
	pause=1;
	
	}
	
	
	if(dtl[i]==0)
	{
	if(c=='s'&&mod[i]<4)
	{
	system("cls");mod[i]=mod[i]+1;}
	if(c=='w'&&mod[i]>1)
	{
	system("cls");mod[i]=mod[i]-1;}
	
	if(c=='g')
	{if(mod[i]==atoi(da.c_str())) {
	cout<<endl<<"Dap an dung";diem++;dtl[i]=2;}
	else {
	cout<<endl<<"Dap an sai";dtl[i]=1;}
	}
}
}
gotoxy(37,7);
cout<<"Diem so:"<<diem;
gotoxy(0,8);
int td=0;
for(int i=0;i<=max;i++)
{if(dtl[i]!=0) td=td+1;
}
cout<<"Tien do: "<<td<<" // "<<max+1;
cout<<endl;
for(int i=0;i<=max;i++)
{if(dtl[i]==2) cout<<"O";
else if(dtl[i]==1) cout<<"X";
else cout<<"-";
cout<<" ";
}
}

filein.close();
tt:
system("cls");
cout<<"Cam on ban da choi game"<<endl;
cout<<"Diem dat duoc:"<<diem;

int pla=1;
int mpl=1;
while(pla==1)
{
Playagain(mpl);
if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c=='d'&& mpl==2) mpl=3;
	if(c=='d'&& mpl==1) mpl=2;
	if(c=='a'&& mpl==2) mpl=1;
	if(c=='a'&& mpl==3) mpl=2;
	if(c==' ')
	{if (mpl==1) {
	system("cls");goto tk;}
	else if(mpl==2){system("cls");
	pla=0;}
	else {system("cls");goto sd;
	}
	}
}
Sleep(50);
}
sd:
int moddiem=1;
while(moddiem==1)
{
ifstream filein;
filein.open("diem.txt",ios_base::in);
vector<diem> dsdiem;
filein.close();
}
}
