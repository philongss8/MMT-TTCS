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
gotoxy(30,8);
cout<<"Nhan a,d de di chuyen option";
gotoxy(30,9);
cout<<"Nhan space de chon";
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
gotoxy(30,8);
cout<<"Nhan a,d de di chuyen option";
gotoxy(30,9);
cout<<"Nhan space de chon";
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
cout<<"Cau hoi : "<<detn.cauhoi<<endl;
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
gotoxy (20,20);
cout<<"Nhan E de pause hoac nop bai";
gotoxy (20,21);
cout<<"Nhan G de chon";
gotoxy (20,22);
cout<<"Nhan a,d de di chuyen cau hoi";
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
gotoxy(35,12);
cout<<"Nhan space de chon";
}
}




int main()
{tk:
	diem tam;
int modmenu=1;
int modde=1;
while(modmenu!=0)
{Sleep(100);
menu(modmenu);
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


ifstream fileinn;
fileinn.open("diem.txt",ios_base::in);
vector<diem> dsdiem;
nhapdiem2(fileinn,dsdiem);
fileinn.close();
while(modde==3)
{

xuatdiem2(dsdiem);
Sleep(100);
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
{Sleep(100);

xuat1(ds[i],mod[i],dtl[i]);

string da=ds[i].dapand;
while (pause==1)
{Sleep(100);
system("cls");
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
cout<<"\t Vi tri hien tai: Cau "<<i+1;
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
int spmod=0;
while(pla==1)
{Sleep(100);
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
	else {system("cls");spmod=1;goto sp;
	}
	}
}
Sleep(50);
sp:
	string ten;
	int vt;
	int save=0;
	int min=dsdiem[0].diem;
for(int i=0;i<dsdiem.size()-1;i++)
{if(dsdiem[i].diem<min) min=dsdiem[i].diem;
}
	while(spmod==1)
	{	Sleep(400);
	system("cls");
	xuatdiem2(dsdiem);

		if(diem<min) {
	gotoxy(20,12);cout<<"Ban chua du diem de vao xh=))";}
	else if(diem>min&&save==0) {
		gotoxy(20,12);cout<<"Nhap vao ten:";
		cin>>ten;
		for(int i=9;i>0;i--)
{if(diem>dsdiem[i].diem) vt=i;
}
for(int i=vt;i<dsdiem.size()-1;i++)
{tam=dsdiem[i];
dsdiem[i+1]=tam;
}

dsdiem[vt].ten=ten;
dsdiem[vt].diem=diem;
save=1;

 ofstream outfile;
   outfile.open("diem.txt");
   for(int i=0;i<dsdiem.size()-1;i++)
   {outfile<<dsdiem[i].ten<<","<<dsdiem[i].diem<<endl;
   
   }
   outfile.close();





	}
	else Sleep(100);
	
	gotoxy(20,14);
cout<<"Nhan b de quay ve menu";
gotoxy(20,15);
cout<<"Nhan e de thoat";
if(kbhit())		//nhan tu ban phim
	{char c;
	c=getch();
	if(c=='b') {system("cls");
	goto tk;}
	if(c=='e') {system("cls");
	spmod=0;pla=0;
	}
	}


}
}}
