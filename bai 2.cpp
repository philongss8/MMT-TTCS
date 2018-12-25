#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int  namnhuan(int year)
{if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))
     return 0;
   else
      return 1;
}
int kiemtra(int n,int t,int na)
{int kt=0;
if(na<0) kt+=1;				//nam nhap sai
else if(t<0||t>12) kt+=1;	//nam nhap dung thang nhap sai
else						
if(t==2)					// thang 2
if(namnhuan(na)==0)				//kt nam nhuan	
if(n>29||n<1) kt+=1;		//ngay nhap sai
else kt+=0;					//ngay nhap dung
else if(n>28||n<1) kt+=1;	//nam k nhuan ngay nhap sai
else kt+=0;					//ngay nhap dung
else if(t==4||t==6||t==9||t==11)	//thang co 30 ngay
if(n>30||n<1) kt+=1;		//ngay nhap sai
else kt+=0;					//ngay nhap dung
else if(n>31||n<1) kt+=1;	//thang co 31 ngay, ngay nhap sai
else kt+=0;					//ngay nhap dung
return kt;		//neu dung het kt=0
}
int main()
{
int day,month,year;

tt:
cout<<"Nhap vao ngay ";
cin>>day;
cout<<"Nhap vao thang ";
cin>>month;
cout<<"Nhap vao nam ";
cin>>year;
if( kiemtra(day,month,year)==0)	//kiem tra ngay, thang nam nhap dung hay sai
{
cout<<"Ngay da nhap vao:  "<<day<<"// "<<month<<"// "<<year<<endl;
if(namnhuan(year)==0)
  printf("%d la mot nam nhuan", year);
  else
  printf("%d khong phai la nam nhuan", year);
  //sng= so ngay
int sng=day;
if(month>1)
{
	
	//thuc hien dong lenh for se + them so ngay tuong ung voi thang
for(int i=1;i<month;i++)
{ switch (i)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            {
                sng=sng+31;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11:
            {
               sng=sng+30;
                break;
            }
            default:
            {
              if(namnhuan(year)==0) {sng=sng+29;break;} 
              else {sng=sng+28;break;} 
            }
        }
 
}
}
cout<<endl;
cout<<"ngay vua nhap la ngay "<<sng<<" trong nam";
cout<<endl;
cout<<"cong them ngay ";
int cong;
cin>>cong;
int sng2=sng+cong;     //sau khi + ngay van giu gia tri kieu int
int max;				//gioi han max
if(namnhuan(year)==0) max=366;
else max=365;
cout<<endl;
//neu stt ngay > ngay co trong nam (max) thi se sang nam moi 
//vong lap lap lai den khi so ngay be hon max (truong hop + hon 800 ngay)
//tinh duoc nam
while(sng2>max)
{
	sng2=sng2-max;
	year=year+1;
	cout<<" - "<<max;
	if(namnhuan(year)==0) max=366;
else max=365;
}
cout<<endl<<sng2;

//chuyen doi tu kieu stt sang thang
//tinh duoc thang
int sng3=0,tam;
int thang=1;
while(sng3<sng2)
{switch (thang)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            {	tam=31;
                sng3=sng3+31;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11:
            {	tam=30;
               sng3=sng3+30;
                break;
            }
            default:
            {	  if(namnhuan(year)==0) {tam=29;sng3=sng3+29;break;} 
              else {tam=28;sng3=sng3+28;break;}    }
        }
 thang++;
}
cout<<endl;
//lay stt -sothang*songaytrongthang duoc so ngay
int nd=sng2-(sng3-tam);
//in lan luot ngay,thang,nam
cout<<nd<<"//"<<thang-1<<"//"<<year;
cout<<endl;


//Thuc hien nhu phep cong
//chuyen doi tu kieu int sang kieu ngay
cout<<"tru ngay ";
int tru;
cin>>tru;
int sng4=sng2-tru;
//kiem tra so ngay cua nam truoc do
if(namnhuan(year-1)==0) max=366;
else max=365;
cout<<endl;
//khi so ngay sau khi - be hon 0, - nam di 1 va cong so ngay voi so ngay cua nam truoc do
//tiep tuc thuc hien den khi so ngay >0 (truong hop - hon 800 ngay)
//lay duoc nam
while(sng4<=0)
{
	sng4=sng4+max;
	year=year-1;
	cout<<" + "<<max;
	if(namnhuan(year-1)==0) max=366;
else max=365;
}

cout<<endl<<sng4;
int sng5=0;
//lay thang tuong tu nhu cong ngay
thang=1;
while(sng5<sng4)
{switch (thang)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            {	tam=31;
                sng5=sng5+31;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11:
            {	tam=30;
               sng5=sng5+30;
                break;
            }
            default:
            {	  if(namnhuan(year)==0) {tam=29;sng5=sng5+29;break;} 
              else {tam=28;sng5=sng5+28;break;}    }
        }
 thang++;
}
cout<<endl;
//lay ngay
nd=sng4-(sng5-tam);
cout<<nd<<"//"<<thang-1<<"//"<<year;



}
else cout<<"Ngay nhap sai";
}
