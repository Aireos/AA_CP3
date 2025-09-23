#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

enum Menu {
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

int main() {
    srand(time(0));
    bool all_found = false;
    vector<Pokemen> Pokedex = {{"Tardigrade", 200, 200, {{100, 1}, {80, 2}, {60, 3}}, 1, "space"}, {"Bristlemouth", 120, 120, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"}, {"Quelea", 60, 60, {{40, 1}, {30, 2}, {20, 3}}, 1, "sky"}, {"Ant", 90, 90, {{30, 1}, {25, 2}, {15, 3}}, 1, "ground"}, {"Dodo", 5, 5, {{1, 1}, {1, 2}, {1, 3}}, 1, "useless"}};;
    vector<Pokemen> inventory;

    while(true){
        cout << endl <<
            "1. Explore\n" <<
            "2. Battle\n" <<
            "3. Heal_Pokemon\n" <<
            "4. Exit\n" <<
            "Selection: ";
        int input;
        cin >> input;
        cout << endl;

        if (input == Menu::Explore) {
            if (!all_found){
                cout << "Exploring for new Pokemon..." << endl;
                int randomIndex = rand() % Pokedex.size();
                Pokemen randomPokemon = Pokedex[randomIndex];
                    
                bool isDuplicate = false;
                for (const auto& ownedPokemon : inventory) {
                    if (ownedPokemon.name == randomPokemon.name) {
                        isDuplicate = true;
                        break;
                    }
                }
                    
                if (!isDuplicate) {
                    cout << "You have found a " << randomPokemon.name << "! It has been added to your inventory." << endl;
                    inventory.push_back(randomPokemon);

                }else if(inventory.size() == Pokedex.size()){
                    cout << "You have found every single pokemon!" << endl;
                    all_found = true;
                }else {
                    cout << "You found a " << randomPokemon.name << ", but you already have one." << endl;
                }
            }else{
                cout << "You have found every single pokemon! Now stop trying to find new ones!" << endl;
            }

        }else if (input == Menu::Battle) {
            cout;

        }else if (input == Menu::Heal_Pokemon) {
            cout;

        }else if (input == Menu::Exit) {
            return 0;

        }else {
            cout << "Not an option.\n";
        }
    }
}