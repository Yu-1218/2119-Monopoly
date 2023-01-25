#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "dice.h"
#include "main.h"
using namespace std;
void print_map_firstline(void){
    for (int i=1;i<11;i++){
        cout << map[i].up; 
    }
    cout << endl;
    for (int i=1;i<11;i++){
        cout << "|  "  << setw(5) << left <<map[i].name_land; 
    }
    cout << "|";
    cout << endl;
    for (int i=1;i<11;i++){
        cout <<  "|  "  << setw(5) << left  << map[i].name_owner;
    }
    cout << "|";
    cout << endl;
    for (int i=1;i<11;i++){
        cout << "|  "  << setw(5) << left << map[i].name_passenger;
    }
    cout << "|";
    cout << endl;
    for (int i=1;i<11;i++){
        cout << map[i].down;
    }
    cout << endl;
}
//What it does: print the first line of the map
//What the input are: none
//What the output are: none
void medium_line(int i,int j){
    cout << "|  " << setw(5) << left << map[i].name_land << "|" << setw(64) << right << "|" << "  " << setw(5) << left << map[j].name_land << "|" << endl;
    cout << "|  " << setw(5) << left << map[i].name_owner << "|" << setw(64) << right << "|" << "  " << setw(5) << left << map[j].name_owner << "|" << endl;
    cout << "|  " << setw(5) << left << map[i].name_passenger << "|" << setw(64) << right << "|" << "  " << setw(5) << left << map[j].name_passenger << "|" << endl;
    if (i!=26){
        cout << "---------" << setw(71) << right << "--------";
        cout << endl;
    }
    else{
        return;
    }
}
//What it does: print  each medium line
//What the input are: none
//What the output are: none
void print_map_medium(void){
    medium_line(30,11);
    medium_line(29,12);
    medium_line(28,13);
    medium_line(27,14);
    medium_line(26,15);
}
//What it does: trigger the medium_line function
//What the input are: none
//What the output are: none
void print_map_lastline(void){
    for (int i=25;i>15;i--){
        cout << map[i].up; 
    }
    cout << endl;
    for (int i=25;i>15;i--){
        cout << "|  "  << setw(5) << left <<map[i].name_land; 
    }
    cout << "|";
    cout << endl;
    for (int i=25;i>15;i--){
        cout <<  "|  "  << setw(5) << left  << map[i].name_owner;
    }
    cout << "|";
    cout << endl;
    for (int i=25;i>15;i--){
        cout << "|  "  << setw(5) << left << map[i].name_passenger;
    }
    cout << "|";
    cout << endl;
    for (int i=25;i>15;i--){
        cout << map[i].down;
    }
    cout << endl;
}
//What it does: print the bottom line of the map
//What the input are: none
//What the output are: none

void print_map(){
    print_map_firstline();
    print_map_medium();
    print_map_lastline();
}   
//What it does: trigger the functions mentioned before
//What the input are: none
//What the output are: none

vector<map_land> load_map(void){
    map_land m;
    ifstream fin;
    fin.open("map.txt");
    for (int i=1;i<32;i++){
    fin >> m.up;
    fin >> m.name_land;
    fin >> m.name_owner;
    fin >> m.name_passenger;
    fin >> m.down;
    fin >> m.status;
    map.push_back(m);
    }
    fin.close();
    map[1].name_land="==>";map[1].status="beginning";
    map[1].name_owner="==>";
    map[1].name_passenger="@#$&";
    map[2].name_land="Den";map[2].status="city";
    map[3].name_land="LAX";map[3].status="city";
    map[4].name_land="!!!";
    map[4].status="destiny";
    map[4].name_owner="---";
    map[5].name_land="CHI";map[5].status="city";
    int tax[4]={6,16,22,23};
    for (int i=0;i<4;i++){map[tax[i]].name_land="Pay";map[tax[i]].name_owner="Tax";map[tax[i]].status="pay";};
    map[7].name_land="DPS";map[7].status="travel";
    map[8].name_land="???";
    map[8].status="chance";
    map[8].name_owner="---";
    map[9].name_land="HKG";map[9].status="city";
    map[10].name_land="Rest";
    map[10].name_owner="Area";
    map[10].status="rest";
    map[11].name_land="RIO";map[11].status="city";
    map[12].name_land="DXB";map[12].status="travel";
    map[13].name_land="LON";map[13].status="city";
    map[14].name_land="???";
    map[14].status="chance";
    map[14].name_owner="---";
    map[15].name_land="PAR";map[15].status="city";
    map[17].name_land="BER";map[17].status="city";
    map[18].name_land="ATH";map[18].status="city";
    map[19].name_land="!!!";
    map[19].status="destiny";
    map[19].name_owner="---";
    map[20].name_land="THR";map[20].status="city";
    map[21].name_land="PHX";map[21].status="travel";
    map[24].name_land="DEL";map[24].status="city";
    map[25].name_land="TYO";map[25].status="city";
    map[26].name_land="SYD";map[26].status="city";
    map[27].name_land="HAV";map[27].status="travel";
    map[28].name_land="BEJ";map[28].status="city";
    map[29].name_land="RGN";map[29].status="city";
    map[30].name_land="SEL";map[30].status="city";
    ofstream fout;
    fout.open("mapp.txt");
    for (int i=0;i<31;i++){
        fout << map[i].name_land << " ";
        fout << map[i].name_owner << " ";
        fout << map[i].name_passenger << " ";
        fout << map[i].pos << " ";
    }
    fout.close();
    return map;
}
//What it does: initiate the content of the map
//What the input are: none
//What the output are: none
