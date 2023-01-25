#ifndef MAIN_H
#define MAIN_H
#include <vector>
#include <string>
using namespace std;

struct map_land{
    string up;
    string name_land;
    string name_owner;
    string name_passenger;
    string down;
    string status;
    int pos;
    };
extern vector<map_land> map;
vector<map_land> load_map(void);

#endif