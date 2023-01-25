#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include "dice.h"
#include "map.h"
#include "main.h"
using namespace std;

vector<map_land> map;

struct player{
    string player;
    int cash;
    int pos;
    int pulse;
    vector <int> land;
};
player allplayer[4];
struct chengshi{
    int pos;
    string name;
    int mai1;
    int sheng2;
    int sheng3;
    int jiao1;
    int jiao2;
    int jiao3;
    int bianmai;
    int shougou1;
    int grade;
};
chengshi city[31];
struct dujia{
    int pos;
    string name;
    int mai;
    int jiao;

};
dujia travel[31];
int *chances=new int [2];
int *chanceses=new int[2];
int *paytax=new int [4];
int qidian;
int jianyu;
int nump;
int lose[4];
void initiate(){
    city[2].name="DEN";city[2].mai1=4000;city[2].sheng2=3000;city[2].sheng3=6000;city[2].jiao1=1000;city[2].jiao2=2000;city[2].jiao3=8000;city[2].bianmai=7000;city[2].shougou1=5500;
    city[3].name="LAX";city[3].mai1=6000;city[3].sheng2=4000;city[3].sheng3=7000;city[3].jiao1=1500;city[3].jiao2=3000;city[3].jiao3=10000;city[3].bianmai=2000;city[3].shougou1=6500;
    city[5].name="CHI";city[5].mai1=6000;city[5].sheng2=3000;city[5].sheng3=6000;city[5].jiao1=3000;city[5].jiao2=3500;city[5].jiao3=7000;city[5].bianmai=3000;city[5].shougou1=4500;
    city[9].name="HKG";city[9].mai1=3000;city[9].sheng2=4000;city[9].sheng3=5000;city[9].jiao1=1500;city[9].jiao2=2000;city[9].jiao3=9000;city[9].bianmai=5000;city[9].shougou1=4500;
    city[11].name="RIO";city[11].mai1=4000;city[11].sheng2=3000;city[11].sheng3=6000;city[11].jiao1=1000;city[11].jiao2=2000;city[11].jiao3=8000;city[11].bianmai=7000;city[11].shougou1=5500;
    city[13].name="LON";city[13].mai1=5000;city[13].sheng2=6000;city[13].sheng3=9000;city[13].jiao1=2000;city[13].jiao2=5000;city[13].jiao3=6000;city[13].bianmai=5000;city[13].shougou1=6500;;
    city[15].name="PAR";city[15].mai1=5000;city[15].sheng2=6000;city[15].sheng3=9000;city[15].jiao1=3000;city[15].jiao2=3500;city[15].jiao3=8000;city[15].bianmai=10000;city[15].shougou1=6500;
    city[17].name="BER";city[17].mai1=4000;city[17].sheng2=3000;city[17].sheng3=6000;city[17].jiao1=1000;city[17].jiao2=2000;city[17].jiao3=8000;city[17].bianmai=7000;city[17].shougou1=5500;
    city[18].name="ATH";city[18].mai1=2000;city[18].sheng2=3000;city[18].sheng3=4000;city[18].jiao1=900;city[18].jiao2=1000;city[18].jiao3=4000;city[18].bianmai=3000;city[18].shougou1=2500;
    city[20].name="THR";city[20].mai1=2000;city[20].sheng2=3000;city[20].sheng3=5000;city[20].jiao1=1000;city[20].jiao2=1500;city[20].jiao3=7000;city[20].bianmai=1000;city[20].shougou1=3500;
    city[24].name="DEL";city[24].mai1=5000;city[24].sheng2=4000;city[24].sheng3=4000;city[24].jiao1=2000;city[24].jiao2=3000;city[24].jiao3=8000;city[24].bianmai=3000;city[24].shougou1=4500;
    city[25].name="TYO";city[25].mai1=5000;city[25].sheng2=3000;city[25].sheng3=6000;city[25].jiao1=1000;city[25].jiao2=2000;city[25].jiao3=8000;city[25].bianmai=5000;city[25].shougou1=3500;
    city[26].name="SYD";city[26].mai1=3000;city[26].sheng2=3000;city[26].sheng3=6000;city[26].jiao1=1000;city[26].jiao2=2000;city[26].jiao3=8000;city[26].bianmai=6000;city[26].shougou1=7500;
    city[28].name="BEJ";city[28].mai1=4000;city[28].sheng2=3000;city[28].sheng3=5000;city[28].jiao1=3000;city[28].jiao2=4000;city[28].jiao3=9000;city[28].bianmai=10000;city[28].shougou1=4500;
    city[29].name="RGN";city[29].mai1=4000;city[29].sheng2=3000;city[29].sheng3=6000;city[29].jiao1=1000;city[29].jiao2=2000;city[29].jiao3=8000;city[29].bianmai=4000;city[29].shougou1=4500;
    city[30].name="SEL";city[30].mai1=6000;city[30].sheng2=3000;city[30].sheng3=6000;city[30].jiao1=1000;city[30].jiao2=2000;city[30].jiao3=8000;city[30].bianmai=3000;city[30].shougou1=5500;
    travel[7].name="DPS";travel[7].mai=8000;travel[7].jiao=6000;
    travel[12].name="DXB";travel[12].mai=7500;travel[12].jiao=5000;
    travel[21].name="PHX";travel[21].mai=9000;travel[21].jiao=7000;
    travel[27].name="HAV";travel[27].mai=7200;travel[27].jiao=6000;
    allplayer[0].player="@";allplayer[0].cash=10000;allplayer[0].pos=1;allplayer[0].pulse=0;
    allplayer[1].player="#";allplayer[1].cash=10000;allplayer[1].pos=1;allplayer[1].pulse=0;
    allplayer[2].player="$";allplayer[2].cash=10000;allplayer[2].pos=1;allplayer[2].pulse=0;
    allplayer[3].player="&";allplayer[3].cash=10000;allplayer[3].pos=1;allplayer[3].pulse=0;
}
//What it does: initiate the content of the struct "city" "travel" and "allplayer"
//What the input are: none
//What the output are: none

int SetRound(){
    int x;
    cout<<"The number of round will be(at least 10): ";
    cin>>x;
    while(x<10){
        cout<<"The number is less than 10! Please enter again: ";
        cin>>x;
        cout<<endl;
    }
    return x;
}
//What it does: set the round of the game
//What the input are: an integer which shows the round of the game
//What the output are: none
bool check_cash(int num){
    if(allplayer[num].cash<=0){return false;}
    else{return true;}
}
//What it does: check the cash of the player
//What the input are: none
//What the output are: return false if the cash of a player is less than 0
void losegame(int num){
    nump-=1;
    lose[num]=-1;
    allplayer[num].pos=-1;
    cout<<"Oooops! player "<<allplayer[num].player<<" has run out of cash and lose the game!"<<endl;
    cout<<"His ownership of all the city will be dismissed!"<<endl;
    for(int i=1;i<31;i++){
        if(map[i].name_owner.substr(0,1)==allplayer[num].player){map[i].name_owner="nob";}
    }
    for(int i=1;i<31;i++){
        for(int j=0;j<4;j++){
            if(map[i].name_passenger.substr(j,1)==allplayer[num].player){map[i].name_passenger.replace(j,1,"*");}            
        }
    }
}
//What it does: kick out the player if he is run out of cash, return all his belongings
//What the input are: none
//What the output are: change the content of passenger/owner in the struct map
void check_passenger_old(int num,int pos){
    for(int i=0;i<4;i++){
        if(map[pos].name_passenger.substr(i,1)==allplayer[num].player){map[pos].name_passenger.replace(i,1,"*");}
    }
}

void check_passenger_new(int num,int pos){
    for(int i=0;i<4;i++){
        if(map[pos].name_passenger.substr(i,1)=="*"){map[pos].name_passenger.replace(i,1,allplayer[num].player);return;}
    }
}
//What it does: change the position of the player after each move (both the check_passenger_old and the checkpassenger_new)
//What the input are: none
//What the output are: change the content of passenger in the struct map
void check_city(int n,int num){
    string owner1="",owner2="",owner3="";
    int a=1,b=2,c=3;
    char k=a+'0',p=b+'0',q=c+'0';
    owner1+=allplayer[num].player;
    owner1+=" ";
    owner2=owner1+p;owner3=owner1+q;owner1+=k;
    if(map[n].name_owner=="nob"){
        string intention;
        if(allplayer[num].cash<=city[n].mai1){cout<<"Your cash isn't enough to buy the land. Round over. "<<endl;
        cout << "Please enter anything to continue..." << endl;
        string s;
        cin >> s;
        return;}
        else{
            cout<<"This city named "<<city[n].name<<" hasn't been bought."<<endl;
            cout<<"Would you like to spend "<<city[n].mai1<<" to buy this land?(enter yes or no)"<<endl;
            cout<<"Note: you have "<<allplayer[num].cash<<" in total."<<endl;
            while(cin>>intention){
            if(intention=="yes"){
                cout<<"Congratulations! You have successfully bought this land."<<endl;
                map[n].name_owner=owner1;
                allplayer[num].cash-=city[n].mai1;
                city[n].grade=1;
                allplayer[num].land.push_back(n);
                break;
                };
            if(intention=="no")
            {cout<<"You choose no. Round over. "<<endl;
            break;}
            cout << "Please input again! (yes or no)" << endl;}
        return;
        }
    }
    if(owner1==map[n].name_owner){
        string intention;
        if(allplayer[num].cash<=city[n].sheng2){cout<<"Your cash isn't enough to upgrade your land. Round over. "<<endl;return;}
        else{
            cout<<"This city belongs to you. "<<endl;
            cout<<"Would you like to spend "<<city[n].sheng2<<" to upgrade your city to the second level?(enter yes or no)"<<endl;
            cout<<"Note: you have "<<allplayer[num].cash<<" in total."<<endl;
            cin>>intention;
            if(intention=="yes"){cout<<"Congratulations! You have upgrade your city to the second level."<<endl;map[n].name_owner==owner2;allplayer[num].cash-=city[n].sheng2;city[n].grade=2;}
            if(intention=="no"){cout<<"You choose no. Round over. "<<endl;}
        return;
        }
    }    
    if(owner2==map[n].name_owner){
        string intention;
        if(allplayer[num].cash<=city[n].sheng3){cout<<"Your cash isn't enough to upgrade your land. Round over. "<<endl;return;}
        else{
            cout<<"This city belongs to you. "<<endl;
            cout<<"Would you like to spend "<<city[n].sheng3<<" to upgrade your city to the highest level?(enter yes or no)"<<endl;
            cout<<"Note: you have "<<allplayer[num].cash<<" in total."<<endl;
            cin>>intention;
            if(intention=="yes"){cout<<"Congratulations! You have upgrade your city to the highest level."<<endl;map[n].name_owner==owner3;allplayer[num].cash-=city[n].sheng3;city[n].grade=3;}
            if(intention=="no"){cout<<"You choose no. Round over. "<<endl;}
        return;
        }
    }
    if(owner3==map[n].name_owner){
        cout<<"The city is in the highest level! Round over. "<<endl;
        cout << "Please enter anything to continue..." << endl;
        string s;
        cin >> s;
        return;
    }
    if(owner1!=map[n].name_owner&&owner2!=map[n].name_owner&&owner3!=map[n].name_owner&&map[n].name_owner!="nob"){
        string realowner=map[n].name_owner.substr(0,1);
        if(city[n].grade==3){
            bool check;
            cout<<"Ooops! This city belongs to "<<realowner<<" . You have to pay him "<<city[n].jiao3<<" ."<<endl;
            allplayer[num].cash-=city[n].jiao3;
            check=check_cash(num);
            if(check==false){
                losegame(num);
                for(int i=0;i<4;i++){
                    if(allplayer[i].player==realowner){allplayer[i].cash+=city[n].jiao3;allplayer[i].cash+=allplayer[num].cash;}
                }
                return;
            }
            else{
                for(int i=0;i<4;i++){
                    if(allplayer[i].player==realowner){allplayer[i].cash+=city[n].jiao3;}
                }
                return;
            }
        }
        if(city[n].grade==2){
            bool check;
            cout<<"Ooops! This city belongs to "<<realowner<<" . You have to pay him "<<city[n].jiao2<<" ."<<endl;
            allplayer[num].cash-=city[n].jiao2;
            check=check_cash(num);
            if(check==false){
                losegame(num);
                for(int i=0;i<4;i++){
                    if(allplayer[i].player==realowner){allplayer[i].cash+=city[n].jiao2;allplayer[i].cash+=allplayer[num].cash;}
                }
                return;
            }
            else{
                for(int i=0;i<4;i++){
                    if(allplayer[i].player==realowner){allplayer[i].cash+=city[n].jiao2;}
                }
                return;
            }
        }
        if(city[n].grade==1){
            bool check;
            cout<<"You have arrived at "<<city[n].name<<" ."<<endl;
            if(allplayer[num].cash<=city[n].jiao1){
                cout<<"You have to pay "<<city[n].jiao1<<" ."<<endl;
                cout<<"Your cash isn't enough!"<<endl;
                losegame(num);
                for(int i=0;i<4;i++){
                    if(allplayer[i].player==realowner){allplayer[i].cash+=allplayer[num].cash;}
                }
                return;
            }
            if(allplayer[num].cash<=city[n].shougou1&&allplayer[num].cash>city[n].jiao1){
                cout<<"Your cash isn't enough to buy this grade 1 city from "<<realowner<<" . Automatically pay "<<city[n].jiao1<<" !"<<endl;
                allplayer[num].cash-=city[n].jiao1;
                for(int i=0;i<4;i++){
                   if(allplayer[i].player==realowner){allplayer[i].cash+=city[n].jiao1;} 
                }
                return;    
            }
            if(allplayer[num].cash>city[n].shougou1){
                string intention;
                cout<<"You could choose to buy this city or pay the passing-by fee "<<city[n].jiao1<<" to "<<realowner<<" ."<<endl;
                cout<<"Enter your choice(buy or pay): "<<endl;
                cout<<"Note: you have "<<allplayer[num].cash<<" in total."<<endl;
                cin>>intention;
                if(intention=="buy"){
                    cout<<"Congratulations! This city belongs to you now. "<<endl;
                    map[n].name_owner=owner1;
                    allplayer[num].cash-=city[n].shougou1;
                    for(int i=0;i<4;i++){
                        if(allplayer[i].player==realowner){allplayer[i].cash+=city[n].shougou1;}
                    }
                    return;
                }
                if(intention=="pay"){
                    cout<<"OK! You pay "<<realowner<<" "<<city[n].jiao1<<" ."<<endl;
                    allplayer[num].cash-=city[n].jiao1;
                     for(int i=0;i<4;i++){
                        if(allplayer[i].player==realowner){allplayer[i].cash+=city[n].jiao1;}
                    }
                    return;
                }      
            }
        }
    }
}
//What it does: as in the basic rules, trigger incidents if the position of player is "city",whether buy the city, upgrade the city or pay to another player
//What the input are: the intention of player whether to buy/upgrade the travel city(yes/no) 
//What the output are: change the owner of the city/change the grade of the city/change the map if the intention is yes. trigger check_cash function and lose_game function after the player pay the money to another player
void check_travel(int n, int num){
    bool check;
    string owner="";
    owner+=allplayer[num].player;
    owner+=" ";
    owner+="T";
    if(map[n].name_owner=="nob"){
        string intention;
        if(allplayer[num].cash<=travel[n].mai){
            cout<<"Your cash isn't enough to buy the travel land. Round over."<<endl;
            cout << "Please enter anything to continue..." << endl;
            string s;
            cin >> s;
            return;}
        else{
            cout<<"This travel city named "<<travel[n].name<<" hasn't been bought."<<endl;
            cout<<"Would you like to spend "<<travel[n].mai<<" to buy this travel city?(enter yes or no) "<<endl;
            cout<<"Note: it will belong to you forever!"<<endl;
            cout<<"Note: you have "<<allplayer[num].cash<<" in total."<<endl;
            cin>>intention;
            if(intention=="no"){cout<<"You choose no. Round over. "<<endl;}
            if(intention=="yes"){cout<<"Congratulations! You have successfully bought this travel city."<<endl;map[n].name_owner=owner;allplayer[num].cash-=travel[n].mai;}   
        return;
        }
    }
    if(map[n].name_owner==owner){
        cout<<"This is your travel city. Round over."<<endl;
        cout << "Please enter anything to continue..." << endl;
        string s;
        cin >> s;
        return;}
    if(map[n].name_owner!="nob"&&map[n].name_owner!=owner){
        string realowner;
        bool check;
        realowner=map[n].name_owner.substr(0,1);
        cout<<"Ooops! This is a travel city which belongs to "<<realowner<<" ."<<endl;
        cout<<"You have to pay him "<<travel[n].jiao<<" ."<<endl;
        allplayer[num].cash-=travel[n].jiao;
        check=check_cash(num);
        if(check==false){
            losegame(num);
            for(int i=0;i<4;i++){
                if(allplayer[i].player==realowner){allplayer[i].cash+=travel[n].jiao;allplayer[i].cash+=allplayer[num].cash;}
            }
            return;
        }
        else{
            for(int i=0;i<4;i++){
                if(allplayer[i].player==realowner){allplayer[i].cash+=travel[n].jiao;}
            }
            cout << "Please enter anything to continue..." << endl;
            string s;
            cin >> s;
            return;
        }
    }
}
//What it does: as in the basic rules, trigger incidents if the position of player is "travel city",whether buy the city or pay to another player
//What the input are: the intention of player whether to buy the travel city(yes/no) 
//What the output are: change the owner of the city and change the map if the intention is yes. trigger check_cash function and lose_game function after the player pay the money to another player
void check_pay(int num){
    bool check;
    cout<<"Ooops! You have arrived at tax area. You should pay 5000! "<<endl;
    allplayer[num].cash-=5000;
    check=check_cash(num);
    if(check==false){losegame(num);}
    else{
    cout<<"You have "<<allplayer[num].cash<<" now."<<endl;
    }
    cout << "Please enter anything to continue..." << endl;
    string s;
    cin >> s;
    return;
}
//What it does: as in the basic rules, pay money if the position of player is "tax"
//What the input are: none
//What the output are: change the cash of the player in the "appplayer" struct
void check_beginning(int num){
    cout<<"Wow! You have passed by the beginning area. Give you 4000 as reward!"<<endl;
    allplayer[num].cash+=4000;
    cout<<"You have "<<allplayer[num].cash<<" now."<<endl;
    return;
}
//What it does: as in the basic rules, give money to the player if he passes by the "-->".
//What the input are: none
//What the output are: change the cash of the player in the "allplayer" struct

void check_chance(int num){
    cout << "You meet some chances! Something will happen. Please Enter anything to continue...";
    string i;
    if(cin>>i){
    srand(time(NULL));
    int event=rand()%8+1;
    if (event==1){
        cout << "You visit some famous local scenic spots, which costs 2000 dollars in cash!" << endl;
        allplayer[num].cash-=2000;
        cout << "You have " << allplayer[num].cash << " now." << endl;
    }
    else if (event==2){
        cout << "You buy a lottery ticket and win 5000 dollars!" << endl;
        allplayer[num].cash+=5000;
        cout << "You have " << allplayer[num].cash << " now." << endl; 
    }
    else if (event==3){
        cout << "You invested in real estate and lose 3000 dollars because of the financial crisis!" << endl;
        allplayer[num].cash-=3000;
        cout << "You have " << allplayer[num].cash << " now."<<endl;
    }
    else if (event==4){
        cout << "You get a disease and need to pay 1000 dollars to your doctors!" << endl;
        allplayer[num].cash-=1000;
        cout << "You have " << allplayer[num].cash << " now."<<endl;
    }
    else if (event==5){
        cout << "You work in a factory in spare time, get 1000 dollars!" << endl;
        allplayer[num].cash+=1000;
        cout << "You have " << allplayer[num].cash << " now."<<endl;
    }
    else if (event==6){
        cout << "You enjoy your dinner in a fancy restaurant and spend 2000 dollars!" << endl;
        allplayer[num].cash-=2000;
        cout << "You have " << allplayer[num].cash << " now."<<endl;
    }
    else if (event==7){
        cout << "You break the speed limit while driving your car. You have to pay 2000 dollars fine!" << endl;
        allplayer[num].cash-=2000;
        cout << "You have " << allplayer[num].cash << " now."<<endl;
    }
    else if (event==8){
        cout << "You enter on an inheritance! You get 2000 dollars!" << endl;
        allplayer[num].cash+=2000;
        cout << "You have " << allplayer[num].cash << " now."<<endl;
    }
    }
}
//What it does: check the position of the player if he arrives at"???". 
//What the input are: any string to continue the game
//What the output are: trigger the random incidents and change the content of struct allplayer and map
void check_destiny(int num,int pos){
    cout << "You will face your destiny! Something will happen. Please Enter anything to continue...";
    string s;
    cin >> s;
    srand(time(NULL));
    int event=rand()%8+1;
    if (event==1){
        cout << "You will stay here for the next round!" << endl;
        allplayer[num].pulse=1;
    }
    else if (event=2){
        cout << "Lose one of your lands!" << endl;
        if (allplayer[num].land.size()!=0){
        int loss=allplayer[num].land.back();
        cout << "You lose " << map[loss].name_land << " now." << endl;
        map[loss].name_owner="nob";
        city[loss].grade=0;
        allplayer[num].land.pop_back();
        }
        else{
            cout << "You don't have any land now! Please continue..." << endl;
        }
    } 
    else if (event==3){
        cout << "Go to the start point immediately!" << endl;
        check_passenger_old(num,pos);
        check_passenger_new(num,1);
    }
    else if (event==4){
        cout << "Cast the dice one more time!" << endl;
        cout<<"Player1 please enter a number to cast the dice: ";
        int n=castdice();
        check_passenger_old(num,allplayer[num].pos);
        allplayer[num].pos+=n;
        if(allplayer[num].pos>30){allplayer[num].pos-=30;check_beginning(num);}
        check_passenger_new(num,allplayer[num].pos);
    }
    else if (event==5){
        cout << "Tornado occurs! The house on one of your lands are all destroyed!" << endl;
        if (allplayer[num].land.size()!=0){
            city[allplayer[num].land[0]].grade=1;
            map[allplayer[num].land[0]].name_owner[2]='1';
            cout << "The grade of " << city[allplayer[num].land[0]].name << " is 1 now!" << endl;
        }
        else{
            cout << "You don't have any land!" << endl;
        }
    }
    else if (event==6){
        cout << "Be sent to the rest area for vacation! You will stay here for a round." << endl;
        check_passenger_old(num,pos);
        check_passenger_new(num,10);
        allplayer[num].pulse=1;
    }
}
//What it does: check the position of the player if he arrives at"!!!". 
//What the input are: any string to continue the game
//What the output are: trigger the random incidents and change the content of struct allplayer and map

void check_rest(int num){
    cout << "You pass by the rest area, but nothing will happen. Please enter anything to continue..." << endl;
    string s;
    cin >> s;
}
//What it does: check the position of the player if he arrives at"rest". 
//What the input are: any string
//What the output are: none


void check_status(int n,int num){
    if(map[n].status=="city"){check_city(n,num);}
    if(map[n].status=="travel"){check_travel(n,num);}
    if(map[n].status=="pay"){check_pay(num);}
    if(map[n].status=="chance"){check_chance(num);}
    if(map[n].status=="destiny"){check_destiny(num,n);}
    if(map[n].status=="rest"){check_rest(num);}
}
//What it does: check the position of the player and where he arrives. Trigger the other functions.
//What the input are: none
//What the output are: referring to other functions



int main(){
    int numr,nump=4;
    vector<map_land> map;
    initiate();
    for(int i=0;i<4;i++){lose[i]=0;}
    numr=SetRound();
    cout<<"player 1: @"<<endl;
    cout<<"player 2: #"<<endl;
    cout<<"player 3: $"<<endl;
    cout<<"player 4: &"<<endl;
    int n;
    map=load_map();
    print_map();
    while(nump!=1||numr!=0){
        if (allplayer[0].pulse==0){
        if(lose[0]!=-1){
            cout<<"Player1 please enter a number to cast the dice: ";
            n=castdice();
            check_passenger_old(0,allplayer[0].pos);
            allplayer[0].pos+=n;
            if(allplayer[0].pos>30){allplayer[0].pos-=30;check_beginning(0);}
            check_passenger_new(0,allplayer[0].pos);
            check_status(allplayer[0].pos,0);
            system("clear");
            print_map();
            numr-=1;
            if(numr==0){break;}
            if(nump==1){break;}
            
        }}
        else {
            cout << "You should stay here! Sorry" << endl;
            allplayer[0].pulse=0;
            numr-=1;
            if(numr==0){break;}
        }
        if (allplayer[1].pulse==0){
        if(lose[1]!=-1){
            cout<<"Player2 please enter a number to cast the dice: ";
            n=castdice();
            check_passenger_old(1,allplayer[1].pos);
            allplayer[1].pos+=n;
            if(allplayer[1].pos>30){allplayer[1].pos-=30;check_beginning(1);}
            check_passenger_new(1,allplayer[1].pos);
            check_status(allplayer[1].pos,1);
            system("clear");
            print_map();
            numr-=1;
            if(numr==0){break;}
            if(nump==1){break;}
        }}
        else{
            cout << "You should stay here! Sorry" << endl;
            allplayer[0].pulse=0;
            numr-=1;
            if(numr==0){break;}
        }
        if (allplayer[2].pulse==0){
        if(lose[2]!=-1){
            cout<<"Player3 please enter a number to cast the dice: ";
            n=castdice();
            check_passenger_old(2,allplayer[2].pos);
            allplayer[2].pos+=n;
            if(allplayer[2].pos>30){allplayer[2].pos-=30;check_beginning(2);}
            check_passenger_new(2,allplayer[2].pos);
            check_status(allplayer[2].pos,2);
            system("clear");
            print_map();
            numr-=1;
            if(numr==0){break;}
            if(nump==1){break;}
        }}
        else{
            cout << "You should stay here! Sorry" << endl;
            allplayer[0].pulse=0;
            numr-=1;
            if(numr==0){break;}
        }
        if (allplayer[3].pulse==0){
        if(lose[3]!=-1){
            cout<<"Player4 please enter a number to cast the dice: ";
            n=castdice();
            check_passenger_old(3,allplayer[3].pos);
            allplayer[3].pos+=n;
            if(allplayer[3].pos>30){allplayer[3].pos-=30;check_beginning(3);}
            check_passenger_new(3,allplayer[3].pos);
            check_status(allplayer[3].pos,3);
            system("clear");
            print_map();
            numr-=1;
        }}
        else {
            cout << "You should stay here! Sorry" << endl;
            allplayer[0].pulse=0;
            numr-=1;
        }
        for(int i=0;i<4;i++){
            if(lose[i]!=-1){cout<<"player "<<i+1<<" has "<<allplayer[i].cash<<" in total."<<endl;}
        }
    }
    int x=1;
    int max=0;
    if(numr==0){
        cout<<"Round over!"<<endl;
        for(int i=1;i<4;i++){
            if(allplayer[max].cash==allplayer[i].cash){x+=1;}
            if(allplayer[max].cash<allplayer[i].cash){max=i;x=1;}
        }
        if(x==1){cout<<"Congratulations! Player "<<max+1<<" is the richest and wins the game!"<<endl;}
        else{
        cout<<"Congratulations! ";
        cout<<"Player"<<max+1<<" has "<<allplayer[max].cash<<" ."<<endl;
        for(int i=max;i<4;i++){
            if(allplayer[i].cash==allplayer[max].cash){cout<<"Player"<<i+1<<" has "<<allplayer[i].cash<<" ."<<endl;}
        }
        cout<<"They both win! "<<endl;
        }
    }
    else{
        for(int i=0;i<4;i++){
        if(lose[i]==0){cout<<"Congratulations! Player "<<i+1<<" wins the game!"<<endl;}
        }
    }
    delete [] chances;
    delete [] chanceses;
    delete [] paytax;
return 0;
}
