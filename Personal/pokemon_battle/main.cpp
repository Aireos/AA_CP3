// AKA Pokemon Battle

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <memory>
using namespace std;

enum Menu{
    Explore = 1,
    Battle = 2,
    Heal_Pokemon = 3,
    Exit = 4
};

struct Attacks {
    int damage;
    int amount;
};

struct Pokemen {
    string name;
    int max_hp;
    int current_hp;
    vector<Attacks> attacks;
    int level;
    string type;
};

int main(){
    vector<Pokemen> Pokemen = {{"Tardigrade",1,1,{{1,1},{1,1},{1,1}},1,"space"},{"Bristlemouth",1,1,{{1,1},{1,1},{1,1}},1,"water"},{"(Quelea",1,1,{{1,1},{1,1},{1,1}},1,"sky"},{"ant",1,1,{{1,1},{1,1},{1,1}},1,"ground"},{"dodo bird",1,1,{{1,1},{1,1},{1,1}},1,"useless"}};
    cout << endl <<
    "1. Explore\n" <<
    "2. Battle\n" <<
    "3. Heal_Pokémon\n" <<
    "4. Exit\n" <<
    "Selection: ";
    int input;
    cin >> input;
    cout << endl;
    if(input == Menu::Explore){

    }else if(input == Menu::Battle){
        
    }else if(input == Menu::Heal_Pokemon){
        
    }else if(input == Menu::Exit){
        return 0;
    }else{
        cout << "Not a option.\n";
    }
}