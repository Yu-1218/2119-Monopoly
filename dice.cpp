#include "dice.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

int castdice(){
    int dianshu;
    string n;
    cin>>n;
    srand(time(NULL));
    dianshu=rand()%6+1;
    cout<<"The number of dice is "<<dianshu<<endl;
    return dianshu;
}
//What it does: cast the dice in each round
//What the input are: any number
//What the output are: a random number of 1-6, on behalf of the number of dice