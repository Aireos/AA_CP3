// AKA Pokemon Battle

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>

using namespace std;

enum menu {
    explore = 1,
    battle = 2,
    heal_pokemon_menu = 3,
    exiting = 4
};

enum battle_type {
    wild = 1,
    trainer = 2
};

struct attacks {
    int damage;
    int amount;
};

struct pokemen {
    string name;
    int max_hp;
    int current_hp;
    vector<attacks> attacks;
    int level;
    string type;

    void heal() {
        current_hp = max_hp;
    }

    bool operator==(const pokemen& other) const {
        return name == other.name;
    }
};

pokemen get_random_wild_pokemon(vector<pokemen>& pokedex) {
    int random_index = rand() % pokedex.size();
    pokemen wild_pokemon = pokedex[random_index];
    wild_pokemon.level = (rand() % 5) + 1;
    wild_pokemon.max_hp += (wild_pokemon.level - 1) * 10;
    wild_pokemon.current_hp = wild_pokemon.max_hp;
    for (int i = 0; i < wild_pokemon.attacks.size(); i++) {
        wild_pokemon.attacks[i].damage += (wild_pokemon.level - 1) * 5;
    }
    return wild_pokemon;
}

string get_random_name(vector<string>& names) {
    int random_index = rand() % names.size();
    return names[random_index];
}

float get_type_effectiveness(string& attacker_type, string& defender_type) {
    if (attacker_type == "space") {
        return 2.0f;
    } else if (attacker_type == "useless") {
        return 0.5f;
    } else if (attacker_type == "water") {
        if (defender_type == "sky") return 2.0f;
        if (defender_type == "ground") return 0.5f;
    } else if (attacker_type == "sky") {
        if (defender_type == "ground") return 2.0f;
        if (defender_type == "water") return 0.5f;
    } else if (attacker_type == "ground") {
        if (defender_type == "water") return 2.0f;
        if (defender_type == "sky") return 0.5f;
    }
    return 1.0f;
}

void level_up(pokemen& p) {
    p.level++;
    p.max_hp += 10;
    
    for (int i = 0; i < p.attacks.size(); i++) {
        p.attacks[i].damage += 5;
    }
    
    cout << p.name << " leveled up to level " << p.level << "!\n";
    cout << p.name << "'s stats have been increased!\n";
}

void explore_pokemon(vector<pokemen>& inventory, vector<pokemen>& pokedex) {
    pokemen found_pokemon = get_random_wild_pokemon(pokedex);
    cout << "\nYou found a wild " << found_pokemon.name << "! (Level:" << found_pokemon.level <<") Do you want to catch it? (y/n): ";
    char choice_char;
    cin >> choice_char;

    if (choice_char == 'y') {
        auto i = find(inventory.begin(), inventory.end(), found_pokemon);
        if (i == inventory.end()) {
            inventory.push_back(found_pokemon);
            cout << found_pokemon.name << " has been added to your team!\n";
        } else {
            cout << "You already have a " << found_pokemon.name << " on your team!\n";
        }
    } else {
        cout << "You let " << found_pokemon.name << " go.\n";
    }
}

void heal_inventory(vector<pokemen>& inventory) {
    if (inventory.empty()) {
        cout << "You have no pokemon to heal or regain attacks for." << endl;
        return;
    }
    for (auto& pokemon : inventory) {
        pokemon.heal();
    }
    cout << "Your pokemon have been healed!" << endl;

    for (auto& pokemon : inventory) {
        for(int i = 0; i < pokemon.attacks.size(); i++){
            pokemon.attacks[i].amount = i + 1; 
        }
    }
    cout << "Your pokemon have had their attacks restored!" << endl;
}

void battle_logic(vector<pokemen>& inventory, vector<pokemen>& pokedex, vector<string>& names, int choice) {

    if (choice == battle_type::wild) {
        cout << "welcome to the battle stadium! pick your fighter.\n";
        for (int i = 0; i < inventory.size(); i++) {
            cout << (i + 1) << ". " << inventory[i].name << " (Level: " << inventory[i].level << ")" << endl;
        }
        cout << "selection: ";
        int fighter_choice;
        cin >> fighter_choice;
        cout << endl;

        if (cin.fail() || fighter_choice < 1 || fighter_choice > inventory.size()) {
            cout << "invalid choice of pokemon." << endl;
            return;
        }

        pokemen& fighter = inventory[fighter_choice - 1];
        pokemen wild_pokemon = get_random_wild_pokemon(pokedex);
        
        cout << "a wild " << wild_pokemon.name << " (Level: " << wild_pokemon.level << ") appears!" << endl;
        cout << "you chose " << fighter.name << "." << endl;

        if (fighter.current_hp <= 0) {
            cout << "you cannot fight with a dead pokemon!\n";
        } else {
            while (fighter.current_hp > 0 && wild_pokemon.current_hp > 0) {
                cout << fighter.name << " (hp: " << fighter.current_hp << ") vs " << wild_pokemon.name << " (hp: " << wild_pokemon.current_hp << ")" << endl;

                cout << fighter.name << " can do the following attacks, which one do you want it to do?\n";
                for (int i = 0; i < fighter.attacks.size(); i++) {
                    cout << (i + 1) << ". " << "damage: " << fighter.attacks[i].damage << ", uses left: " << fighter.attacks[i].amount << endl;
                }
                cout << "choice: ";
                int attack_choice;
                cin >> attack_choice;
                cout << endl;

                if (cin.fail() || attack_choice < 1 || attack_choice > fighter.attacks.size() || fighter.attacks[attack_choice - 1].amount <= 0) {
                    cout << "invalid attack choice or no uses left. you miss your turn." << endl;
                } else {
                    int damage = fighter.attacks[attack_choice - 1].damage;
                    fighter.attacks[attack_choice - 1].amount--;
                    
                    float effectiveness = get_type_effectiveness(fighter.type, wild_pokemon.type);
                    wild_pokemon.current_hp -= int(damage * effectiveness);
                    cout << fighter.name << " used an attack, dealing " << int(damage * effectiveness) << " damage to " << wild_pokemon.name << "!" << endl;
                    if (effectiveness > 1.0f) {
                        cout << "It's super effective!\n";
                    } else if (effectiveness < 1.0f) {
                        cout << "It's not very effective...\n";
                    }
                }

                if (wild_pokemon.current_hp <= 0) {
                    cout << wild_pokemon.name << " fainted! you won!" << endl;
                    level_up(fighter);
                    break;
                }

                int wild_attack_index = rand() % wild_pokemon.attacks.size();
                int wild_damage = wild_pokemon.attacks[wild_attack_index].damage;
                
                float wild_effectiveness = get_type_effectiveness(wild_pokemon.type, fighter.type);
                fighter.current_hp -= int(wild_damage * wild_effectiveness);
                cout << wild_pokemon.name << " attacked, dealing " << int(wild_damage * wild_effectiveness) << " damage to " << fighter.name << "!" << endl;
                if (wild_effectiveness > 1.0f) {
                    cout << "It's super effective!\n";
                } else if (wild_effectiveness < 1.0f) {
                    cout << "It's not very effective...\n";
                }

                if (fighter.current_hp <= 0) {
                    cout << fighter.name << " fainted! you lost." << endl;
                    break;
                }
            }
        }
    } else if (choice == battle_type::trainer) {
        cout << "\nTrainer battles are not yet implemented.\n";
    }
}

int main() {
    srand(time(0));
    
    vector<pokemen> pokedex = {
        {"tardigrade", 200, 200, {{100, 1}, {80, 2}, {60, 3}}, 1, "space"},
        {"bristlemouth", 120, 120, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"},
        {"quelea", 60, 60, {{40, 1}, {30, 2}, {20, 3}}, 1, "sky"},
        {"ant", 90, 90, {{30, 1}, {25, 2}, {15, 3}}, 1, "ground"},
        {"dodo", 1, 1, {{1, 1}, {1, 2}, {1, 3}}, 1, "useless"}
    };
    
    vector<pokemen> inventory;
    vector<string> names = {"Dave", "Larose", "Nick", "Jonas", "Alex"};
    
    while (true) {
        cout << endl <<
            "1. explore\n" <<
            "2. battle\n" <<
            "3. heal and rejuvenate pokemon\n" <<
            "4. exit\n" <<
            "selection: ";
        int choice;
        cin >> choice;
        cout << endl;

        if (cin.fail()) {
            cout << "enter a number from 1 to 4 next time." << endl;
            continue;
        }

        if (choice == menu::explore) {
            explore_pokemon(inventory, pokedex);
        } else if (choice == menu::battle) {
            if (inventory.empty()) {
            cout << "You don't have any pokemon to battle with!\n";
            continue;
            }
            cout << "what type of battle do you want?\n";
            cout << "1. wild battle\n";
            cout << "2. trainer battle\n";
            cout << "selection: ";
            int battle_choice;
            cin >> battle_choice;
            cout << endl;
            if (cin.fail() || (battle_choice != battle_type::wild && battle_choice != battle_type::trainer)) {
                cout << "enter a number from 1 to 2 next time." << endl;
            } else {
                battle_logic(inventory, pokedex, names, battle_choice);
            }
        } else if (choice == menu::heal_pokemon_menu) {
            heal_inventory(inventory);
        } else if (choice == menu::exiting) {
            cout << "exiting..." << endl;
            return 0;
        } else {
            cout << "enter a number from 1 to 4 next time." << endl;
        }
    }
    return 0;
}