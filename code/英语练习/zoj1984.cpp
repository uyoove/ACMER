#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<math.h>
#include<string>
#include<map>
using namespace std;
map<string,int>mm;
struct Node{
    string name;
    string nation;
    Node(string a="",string b=""):name(b),nation(a){}
};
void init(){
    mm["Kamen"]=mm["Rock"]=mm["Pierre"]=mm["Stein"]=mm["Ko"]=mm["Koe"]=mm["Sasso"]=mm["Roccia"]=mm["Guu"]=mm["Kamien"]=mm["Piedra"]=1;
    mm["Nuzky"]=mm["Scissors"]=mm["Ciseaux"]=mm["Schere"]=mm["Ollo"]=mm["Olloo"]=mm["Forbice"]=mm["Choki"]=mm["Nozyce"]=mm["Tijera"]=2;
    mm["Papir"]=mm["Paper"]=mm["Feuille"]=mm["Papier"]=mm["Papir"]=mm["Carta"]=mm["Rete"]=mm["Paa"]=mm["Papier"]=mm["Papel"]=3;
}
int main(){
    string a,b;
    init();
    int id=1;
    bool flag=false;
    while(cin>>a>>b){
        Node na(a,b);
        cin>>a>>b;
        Node nb(a,b);
        string op;
        int num[5]={0};
        while(cin>>op){
            if(!flag){
                if(op=="-"||op=="."){
                    cout<<"Game #"<<id++<<":"<<endl;
                    cout<<na.name<<": "<<num[1]<<" point" << (num[1]==1?"":"s")<<endl;
                    cout<<nb.name<<": "<<num[2]<<" point"<<(num[2]==1?"":"s")<<endl;
                    if(num[1]==num[2])
                        cout<<"TIED GAME"<<endl;
                    else if(num[1]>num[2]){
                        cout<<"WINNER: "<<na.name<<endl;
                    }
                    else if(num[1]<num[2]){
                        cout<<"WINNER: "<<nb.name<<endl;
                    }
                    cout<<endl;
                    if(op=="."){
                        flag=true;
                    }
                    break;
                } else{
                    string op2;
                    cin>>op2;
                    if(mm[op]!=mm[op2]){
                        if(mm[op]==1&&mm[op2]==2){
                            num[1]++;
                        }
                        else if(mm[op]==1&&mm[op2]==3){
                            num[2]++;
                        }
                        else if(mm[op]==2&&mm[op2]==1){
                            num[2]++;
                        }
                        else if(mm[op]==2&&mm[op2]==3){
                            num[1]++;
                        }
                        else if(mm[op]==3&&mm[op2]==1){
                            num[1]++;
                        }
                        else if(mm[op]==3&&mm[op2]==2){
                            num[2]++;
                        }
                    }
                }
            }
        }
        if(flag)
            return 0;
    }
}