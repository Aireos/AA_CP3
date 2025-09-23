#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
using namespace std;

enum Menu {
    Explore = 1,
    Battle = 2,
    Heal_Pokemon = 3,
    Exit = 4
};

enum Battle {
    Wild = 1,
    Trainer = 2
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

Pokemen getRandomWildPokemon(const vector<Pokemen>& pokedex) {
    int randomIndex = rand() % pokedex.size();
    return pokedex[randomIndex];
}

void battle(vector<Pokemen>& inventory, const vector<Pokemen>& pokedex, int choice){
    if (inventory.empty()) {
        cout << "You have no Pokemon to battle with!" << endl;
        return;
    }
    if(choice == 1){
        cout << "Welcome to the battle stadium! Pick your fighter.\n";
        for(size_t i = 0; i < inventory.size(); i++){
            cout << (i+1) << ". " <<inventory[i].name << endl;
        }
        cout << "Selection: ";
        int fighter_choice;
        cin >> fighter_choice;
        cout << endl;

        if (fighter_choice < 1 || fighter_choice > inventory.size()) {
            cout << "Invalid choice." << endl;
            return;
        }
        
        Pokemen& fighter = inventory[fighter_choice - 1];
        Pokemen wildPokemon = getRandomWildPokemon(pokedex);

        cout << "A wild " << wildPokemon.name << " appears!" << endl;
        cout << "You chose " << fighter.name << "." << endl;

        while (fighter.current_hp > 0 && wildPokemon.current_hp > 0) {
            cout << fighter.name << " (HP: " << fighter.current_hp << ") vs " << wildPokemon.name << " (HP: " << wildPokemon.current_hp << ")" << endl;
            
            cout << fighter.name << " can do the following attacks, which one do you want it to do?\n";
            for(size_t i = 0; i < fighter.attacks.size(); i++){
                cout << (i+1) << ". " <<"Damage: "<<fighter.attacks[i].damage <<" Amount left: "<<fighter.attacks[i].amount << endl;
            }
            cout << "Choice: ";
            int attack_choice;
            cin >> attack_choice;
            cout << endl;

            if (attack_choice > 0 && attack_choice <= fighter.attacks.size() && fighter.attacks[attack_choice - 1].amount > 0) {
                int damage = fighter.attacks[attack_choice - 1].damage;
                fighter.attacks[attack_choice - 1].amount--;
                wildPokemon.current_hp -= damage;
                cout << fighter.name << " used an attack dealing " << damage << " damage to " << wildPokemon.name << "!" << endl;
            } else {
                cout << "Invalid attack choice or no uses left. You miss your turn." << endl;
            }

            if (wildPokemon.current_hp <= 0) {
                cout << wildPokemon.name << " fainted! You won!" << endl;
                break;
            }

            int wildAttackIndex = rand() % wildPokemon.attacks.size();
            int wildDamage = wildPokemon.attacks[wildAttackIndex].damage;
            fighter.current_hp -= wildDamage;
            cout << wildPokemon.name << " attacked, dealing " << wildDamage << " damage to " << fighter.name << "!" << endl;

            if (fighter.current_hp <= 0) {
                cout << fighter.name << " fainted! You lost." << endl;
                break;
            }
        }
    }else if(choice == 2){
        cout << "Trainer battles are not yet implemented." << endl;
    }
}

void healPokemon(vector<Pokemen>& inventory) {
    if (inventory.empty()) {
        cout << "You have no Pokemon to heal." << endl;
        return;
    }
    cout << "Healing all your Pokemon..." << endl;
    for (auto& pokemon : inventory) {
        pokemon.current_hp = pokemon.max_hp;
    }
    cout << "All your Pokemon have been fully healed!" << endl;
}

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
        
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

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
            cout << endl <<
            "1. Wild Pokemon\n" <<
            "2. Trainer\n" <<
            "Selection: ";
            int choice;
            cin >> choice;
            cout << endl;

            if(choice == Battle::Wild || choice == Battle::Trainer){
                battle(inventory, Pokedex, choice);
            }else{
                cout << "Not an option.\n";
            }
        }else if (input == Menu::Heal_Pokemon) {
            healPokemon(inventory);

        }else if (input == Menu::Exit) {
            return 0;

        }else {
            cout << "Not an option.\n";
        }
    }
}