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
    srand(time(0));
    vector<Pokemen> Pokedex = {{"Tardigrade", 200, 200, {{100, 1}, {80, 2}, {60, 3}}, 1, "space"},{"Bristlemouth", 120, 120, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"},{"Quelea", 60, 60, {{40, 1}, {30, 2}, {20, 3}}, 1, "sky"},{"Ant", 90, 90, {{30, 1}, {25, 2}, {15, 3}}, 1, "ground"},{"Dodo", 5, 5, {{1, 1}, {1, 2}, {1, 3}}, 1, "useless"}};    
    cout << endl <<
    "1. Explore\n" <<
    "2. Battle\n" <<
    "3. Heal_Pokemon\n" <<
    "4. Exit\n" <<
    "Selection: ";
    int input;
    cin >> input;
    cout << endl;
    if(input == Menu::Explore){
        for(int i = 0; i < 5; i++){
            int randomIndex = rand() % Pokedex.size();
            Pokemen randomPokemon = Pokedex[randomIndex];
            cout << "You have found a " << randomPokemon.name << ".";
        }
    }else if(input == Menu::Battle){
        
    }else if(input == Menu::Heal_Pokemon){
        
    }else if(input == Menu::Exit){
        return 0;
    }else{
        cout << "Not a option.\n";
    }
}