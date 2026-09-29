#include<bits/stdc++.h>
using namespace std;
bool leap(int year){
    if(year%100!=0){
        if(year%4==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(year%400==0)
        return 1;
        else
        return 0;
    }
}
int main(){
    int d,m,y;
    cin>>d>>m>>y;
    int mdim=0;
    if(m==1||m==3||m==5||m==7||m==8||m==10||12){
        mdim=31;
    }
    else if(m==4||m==6||m==9||m==1){
        mdim=30;
    }
    else{
        if(leap(y)){
            mdim=29;
        }
        else{
            mdim=28;
        }
    }
    if(d==mdim){
        if(m==12){
            d=1;
            m=1;
            y++;
        }
        else{
            d=1;
            m++;
        }
    }
    else{
        d++;
    }
    cout<<d<<" "<<m<<" "<<y;
    
}