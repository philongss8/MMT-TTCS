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
using namespace std;
void textcolor(int x)	//doi mau chu
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
int main()
{tt:
int n;
char temp[255];
ifstream filein;
filein.open("input.txt",ios_base::in);
filein.getline(temp, 255);
n=atoi(temp);
int G[n][n];
string tam;
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{	fflush(stdin);
	if(j==n-1) getline(filein,tam);
	else
	getline(filein,tam,' ');
	G[i][j]=atoi(tam.c_str());
}
fflush(stdin);
}
int sum=0;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
sum+=G[i][j];

for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
if(G[i][j]==0) G[i][j]=sum;

for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{printf("%*d",5,G[i][j]);
}
cout<<endl;
}
int dau;
int cuoi;
int vt;
cout<<"Nhap diem dau: ";
cin>>vt;
cout<<"Nhap diem cuoi: ";
cin>>cuoi;
int min=sum;
int tam2;
int tam3;
vt=vt-1;
cuoi=cuoi-1;
for(int i=0;i<n;i++)
{G[i][vt]=sum;
}
if(G[vt][cuoi]!=sum) cout<<G[vt][cuoi];
else
while(vt!=cuoi)
{

min=sum;
for(int i=0;i<n;i++)
{if(G[vt][i]<min) {
min=G[vt][i];
tam2=i;}
}

for(int i=0;i<n;i++)
{G[i][tam2]=sum;
}
for(int i=0;i<n;i++)
{G[tam2][i]=G[tam2][i]+min;
if(G[tam2][i]>G[vt][i]) G[tam2][i]=G[vt][i];
}
cout<<min;
cout<<endl<<tam2+1;
cout<<endl;

vt=tam2;
for(int i=0;i<n;i++)
{if(i==vt) {textcolor(14);G[vt][i]=min;}
printf("%*d",5,G[vt][i]);
if(i==vt) G[vt][i]=sum;
textcolor(7);
if(i==n-1) cout<<endl;
}
if(vt==cuoi) break;
}


cout<<endl<<"Again?";
char c;
c=getch();
if(c=='y') {system("cls");goto tt;}







}
