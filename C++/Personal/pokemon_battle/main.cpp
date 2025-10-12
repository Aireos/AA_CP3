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
    
    vector<pokemen> pokedex = {{"tardigrade", 200, 200, {{100, 1}, {80, 2}, {60, 3}}, 1, "space"},{"bristlemouth", 120, 120, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"},{"quelea", 60, 60, {{40, 1}, {30, 2}, {20, 3}}, 1, "sky"},{"ant", 90, 90, {{30, 1}, {25, 2}, {15, 3}}, 1, "ground"},{"salamander", 110, 90, {{35, 1}, {25, 2}, {20, 3}}, 1, "fire"},{"owl", 75, 100, {{45, 1}, {35, 2}, {25, 3}}, 1, "sky"},{"bison", 150, 60, {{20, 1}, {15, 2}, {10, 3}}, 1, "ground"},{"squid", 85, 115, {{40, 1}, {30, 2}, {25, 3}}, 1, "water"},{"rhino", 140, 70, {{30, 1}, {25, 2}, {15, 3}}, 1, "ground"},{"falcon", 80, 120, {{50, 1}, {40, 2}, {30, 3}}, 1, "sky"},{"jellyfish", 100, 80, {{25, 1}, {20, 2}, {15, 3}}, 1, "water"},{"lion", 105, 105, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"spider", 95, 95, {{35, 1}, {30, 2}, {20, 3}}, 1, "ground"},{"puffin", 85, 85, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"bear", 130, 80, {{35, 1}, {25, 2}, {20, 3}}, 1, "ground"},{"otter", 90, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"scorpion", 100, 100, {{40, 1}, {30, 2}, {20, 3}}, 1, "ground"},{"eel", 110, 110, {{45, 1}, {35, 2}, {25, 3}}, 1, "water"},{"mole", 120, 80, {{25, 1}, {20, 2}, {15, 3}}, 1, "ground"},{"kingfisher", 70, 110, {{40, 1}, {35, 2}, {25, 3}}, 1, "water"},{"gecko", 80, 120, {{50, 1}, {40, 2}, {30, 3}}, 1, "ground"},{"pigeon", 65, 75, {{25, 1}, {20, 2}, {15, 3}}, 1, "sky"},{"dolphin", 105, 95, {{35, 1}, {25, 2}, {20, 3}}, 1, "water"},{"sloth", 130, 50, {{15, 1}, {10, 2}, {5, 3}}, 1, "ground"},{"frog", 95, 95, {{35, 1}, {25, 2}, {20, 3}}, 1, "water"},{"vulture", 75, 110, {{45, 1}, {35, 2}, {25, 3}}, 1, "sky"},{"coyote", 90, 110, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"crab", 110, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"koala", 120, 60, {{20, 1}, {15, 2}, {10, 3}}, 1, "ground"},{"bat", 70, 120, {{50, 1}, {40, 2}, {30, 3}}, 1, "sky"},{"beaver", 115, 85, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"gazelle", 80, 120, {{50, 1}, {40, 2}, {30, 3}}, 1, "ground"},{"pelican", 100, 80, {{25, 1}, {20, 2}, {15, 3}}, 1, "water"},{"ferret", 90, 100, {{35, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"seagull", 80, 80, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"chameleon", 90, 100, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"wasp", 95, 95, {{35, 1}, {30, 2}, {20, 3}}, 1, "sky"},{"lobster", 120, 100, {{40, 1}, {30, 2}, {20, 3}}, 1, "water"},{"wombat", 130, 70, {{25, 1}, {20, 2}, {15, 3}}, 1, "ground"},{"seahorse", 90, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"lemur", 85, 95, {{35, 1}, {30, 2}, {20, 3}}, 1, "ground"},{"platypus", 105, 105, {{40, 1}, {30, 2}, {25, 3}}, 1, "water"},{"chimpanzee", 100, 100, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"kiwi", 70, 80, {{30, 1}, {25, 2}, {20, 3}}, 1, "ground"},{"tuna", 110, 110, {{45, 1}, {35, 2}, {25, 3}}, 1, "water"},{"meerkat", 80, 100, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"swan", 95, 95, {{35, 1}, {25, 2}, {20, 3}}, 1, "water"},{"otter", 90, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"gopher", 100, 90, {{35, 1}, {25, 2}, {20, 3}}, 1, "ground"},{"albatross", 90, 120, {{50, 1}, {40, 2}, {30, 3}}, 1, "sky"},{"koala", 120, 60, {{20, 1}, {15, 2}, {10, 3}}, 1, "ground"},{"dodo", 1, 1, {{1, 1}, {1, 2}, {1, 3}}, 1, "useless"},{"elephant", 180, 70, {{25, 1}, {20, 2}, {15, 3}}, 1, "ground"},{"tiger", 110, 110, {{45, 1}, {35, 2}, {25, 3}}, 1, "ground"},{"eagle", 85, 125, {{55, 1}, {45, 2}, {35, 3}}, 1, "sky"},{"whale", 220, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"cheetah", 90, 150, {{60, 1}, {50, 2}, {40, 3}}, 1, "ground"},{"shark", 130, 130, {{55, 1}, {45, 2}, {35, 3}}, 1, "water"},{"gorilla", 160, 80, {{35, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"crocodile", 140, 100, {{40, 1}, {30, 2}, {25, 3}}, 1, "water"},{"kangaroo", 120, 110, {{45, 1}, {35, 2}, {25, 3}}, 1, "ground"},{"leopard", 100, 130, {{50, 1}, {40, 2}, {30, 3}}, 1, "ground"},{"orca", 150, 150, {{60, 1}, {50, 2}, {40, 3}}, 1, "water"},{"hippopotamus", 190, 60, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"},{"polar_bear", 170, 90, {{40, 1}, {35, 2}, {30, 3}}, 1, "ground"},{"panther", 105, 135, {{55, 1}, {45, 2}, {35, 3}}, 1, "ground"},{"walrus", 160, 80, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"sealion", 110, 110, {{40, 1}, {30, 2}, {25, 3}}, 1, "water"},{"grizzly_bear", 175, 85, {{35, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"penguin", 80, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"snake", 95, 140, {{60, 1}, {50, 2}, {40, 3}}, 1, "ground"},{"starfish", 70, 70, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"},{"armadillo", 110, 80, {{25, 1}, {20, 2}, {15, 3}}, 1, "ground"},{"swordfish", 120, 140, {{65, 1}, {55, 2}, {45, 3}}, 1, "water"},{"owl", 75, 100, {{45, 1}, {35, 2}, {25, 3}}, 1, "sky"},{"deer", 100, 120, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"octopus", 105, 105, {{40, 1}, {30, 2}, {25, 3}}, 1, "water"},{"fox", 90, 110, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"turtule", 130, 70, {{25, 1}, {20, 2}, {15, 3}}, 1, "water"},{"wolf", 110, 110, {{45, 1}, {35, 2}, {25, 3}}, 1, "ground"},{"salmon", 80, 100, {{35, 1}, {25, 2}, {20, 3}}, 1, "water"},{"warthog", 100, 80, {{25, 1}, {20, 2}, {15, 3}}, 1, "ground"},{"anglerfish", 100, 70, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"},{"cobra", 95, 130, {{50, 1}, {40, 2}, {30, 3}}, 1, "ground"},{"manatee", 150, 80, {{25, 1}, {20, 2}, {15, 3}}, 1, "water"},{"raccoon", 85, 95, {{30, 1}, {25, 2}, {20, 3}}, 1, "ground"},{"pufferfish", 90, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"badger", 105, 85, {{30, 1}, {25, 2}, {20, 3}}, 1, "ground"},{"morayeel", 115, 120, {{50, 1}, {40, 2}, {30, 3}}, 1, "water"},{"gopher", 100, 90, {{35, 1}, {25, 2}, {20, 3}}, 1, "ground"},{"seahorse", 90, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"lemur", 85, 95, {{35, 1}, {30, 2}, {20, 3}}, 1, "ground"},{"platypus", 105, 105, {{40, 1}, {30, 2}, {25, 3}}, 1, "water"},{"chimpanzee", 100, 100, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"kiwi", 70, 80, {{30, 1}, {25, 2}, {20, 3}}, 1, "ground"},{"tuna", 110, 110, {{45, 1}, {35, 2}, {25, 3}}, 1, "water"},{"meerkat", 80, 100, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"swan", 95, 95, {{35, 1}, {25, 2}, {20, 3}}, 1, "water"},{"otter", 90, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"gopher", 100, 90, {{35, 1}, {25, 2}, {20, 3}}, 1, "ground"},{"albatross", 90, 120, {{50, 1}, {40, 2}, {30, 3}}, 1, "sky"},{"koala", 120, 60, {{20, 1}, {15, 2}, {10, 3}}, 1, "ground"},{"dodo", 1, 1, {{1, 1}, {1, 2}, {1, 3}}, 1, "useless"},{"elephant", 180, 70, {{25, 1}, {20, 2}, {15, 3}}, 1, "ground"},{"tiger", 110, 110, {{45, 1}, {35, 2}, {25, 3}}, 1, "ground"},{"eagle", 85, 125, {{55, 1}, {45, 2}, {35, 3}}, 1, "sky"},{"whale", 220, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"cheetah", 90, 150, {{60, 1}, {50, 2}, {40, 3}}, 1, "ground"},{"shark", 130, 130, {{55, 1}, {45, 2}, {35, 3}}, 1, "water"},{"gorilla", 160, 80, {{35, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"crocodile", 140, 100, {{40, 1}, {30, 2}, {25, 3}}, 1, "water"},{"kangaroo", 120, 110, {{45, 1}, {35, 2}, {25, 3}}, 1, "ground"},{"leopard", 100, 130, {{50, 1}, {40, 2}, {30, 3}}, 1, "ground"},{"orca", 150, 150, {{60, 1}, {50, 2}, {40, 3}}, 1, "water"},{"hippopotamus", 190, 60, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"},{"polar_bear", 170, 90, {{40, 1}, {35, 2}, {30, 3}}, 1, "ground"},{"panther", 105, 135, {{55, 1}, {45, 2}, {35, 3}}, 1, "ground"},{"walrus", 160, 80, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"sealion", 110, 110, {{40, 1}, {30, 2}, {25, 3}}, 1, "water"},{"grizzly_bear", 175, 85, {{35, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"penguin", 80, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"snake", 95, 140, {{60, 1}, {50, 2}, {40, 3}}, 1, "ground"},{"starfish", 70, 70, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"},{"armadillo", 110, 80, {{25, 1}, {20, 2}, {15, 3}}, 1, "ground"},{"swordfish", 120, 140, {{65, 1}, {55, 2}, {45, 3}}, 1, "water"},{"owl", 75, 100, {{45, 1}, {35, 2}, {25, 3}}, 1, "sky"},{"deer", 100, 120, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"octopus", 105, 105, {{40, 1}, {30, 2}, {25, 3}}, 1, "water"},{"fox", 90, 110, {{40, 1}, {30, 2}, {25, 3}}, 1, "ground"},{"turtule", 130, 70, {{25, 1}, {20, 2}, {15, 3}}, 1, "water"},{"wolf", 110, 110, {{45, 1}, {35, 2}, {25, 3}}, 1, "ground"},{"salmon", 80, 100, {{35, 1}, {25, 2}, {20, 3}}, 1, "water"},{"warthog", 100, 80, {{25, 1}, {20, 2}, {15, 3}}, 1, "ground"},{"anglerfish", 100, 70, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"},{"cobra", 95, 130, {{50, 1}, {40, 2}, {30, 3}}, 1, "ground"},{"manatee", 150, 80, {{25, 1}, {20, 2}, {15, 3}}, 1, "water"},{"raccoon", 85, 95, {{30, 1}, {25, 2}, {20, 3}}, 1, "ground"},{"pufferfish", 90, 90, {{30, 1}, {25, 2}, {20, 3}}, 1, "water"},{"badger", 105, 85, {{30, 1}, {25, 2}, {20, 3}}, 1, "ground"},{"morayeel", 115, 120, {{50, 1}, {40, 2}, {30, 3}}, 1, "water"}};
    
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