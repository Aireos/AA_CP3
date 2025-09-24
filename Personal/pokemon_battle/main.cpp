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
    heal_pokemon = 3,
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
};

pokemen get_random_wild_pokemon(vector<pokemen>& pokedex) {
    int random_index = rand() % pokedex.size();
    return pokedex[random_index];
}

string get_random_name(vector<string>& names) {
    int random_index = rand() % names.size();
    return names[random_index];
}

float get_type_effectiveness(const string& attacker_type, const string& defender_type) {
    if (attacker_type == "space") {
        return 2.0f;
    } else if (attacker_type == "useless") {
        return 0.5f;
    } else if (attacker_type == "water") {
        if (defender_type == "ground") return 2.0f;
        if (defender_type == "sky") return 0.5f;
    } else if (attacker_type == "sky") {
        if (defender_type == "ground") return 2.0f;
        if (defender_type == "water") return 0.5f;
    } else if (attacker_type == "ground") {
        if (defender_type == "water") return 2.0f;
        if (defender_type == "sky") return 0.5f;
    }
    return 1.0f;

void level_up(pokemen& p) {
    p.level++;
    p.max_hp += 10;
    
    for (size_t i = 0; i < p.attacks.size(); i++) {
        p.attacks[i].damage += 5;
    }
    
    cout << p.name << " leveled up to level " << p.level << "!\n";
    cout << p.name << "'s stats have been increased!\n";
}

void battle_logic(vector<pokemen>& inventory, vector<pokemen>& pokedex, vector<string>& names, int choice) {
    if (inventory.empty()) {
        cout << "You don't have any pokemon to battle with!\n";
        return;
    }

    if (choice == battle_type::wild) {
        cout << "welcome to the battle stadium! pick your fighter.\n";
        for (size_t i = 0; i < inventory.size(); i++) {
            cout << (i + 1) << ". " << inventory[i].name << " (Level: " << inventory[i].level << ")" << endl;
        }
        cout << "selection: ";
        int fighter_choice;
        cin >> fighter_choice;
        cout << endl;

        if (fighter_choice < 1 || fighter_choice > inventory.size()) {
            cout << "invalid choice of pokemon." << endl;
            return;
        }

        pokemen& fighter = inventory[fighter_choice - 1];
        pokemen wild_pokemon = get_random_wild_pokemon(pokedex);
        
        wild_pokemon.level = (rand() % 5) + 1;
        wild_pokemon.max_hp += (wild_pokemon.level - 1) * 10;
        wild_pokemon.current_hp = wild_pokemon.max_hp;
        for (size_t i = 0; i < wild_pokemon.attacks.size(); i++) {
            wild_pokemon.attacks[i].damage += (wild_pokemon.level - 1) * 5;
        }

        cout << "a wild " << wild_pokemon.name << " (Level: " << wild_pokemon.level << ") appears!" << endl;
        cout << "you chose " << fighter.name << "." << endl;

        if (fighter.current_hp <= 0) {
            cout << "you cannot fight with a dead pokemon!\n";
        } else {
            while (fighter.current_hp > 0 && wild_pokemon.current_hp > 0) {
                cout << fighter.name << " (hp: " << fighter.current_hp << ") vs " << wild_pokemon.name << " (hp: " << wild_pokemon.current_hp << ")" << endl;

                cout << fighter.name << " can do the following attacks, which one do you want it to do?\n";
                for (size_t i = 0; i < fighter.attacks.size(); i++) {
                    cout << (i + 1) << ". " << "damage: " << fighter.attacks[i].damage << " amount left: " << fighter.attacks[i].amount << endl;
                }
                cout << "choice: ";
                int attack_choice;
                cin >> attack_choice;
                cout << endl;

                if (attack_choice > 0 && attack_choice <= fighter.attacks.size() && fighter.attacks[attack_choice - 1].amount > 0) {
                    int damage = fighter.attacks[attack_choice - 1].damage;
                    fighter.attacks[attack_choice - 1].amount--;
                    
                    float effectiveness = get_type_effectiveness(fighter.type, wild_pokemon.type);
                    wild_pokemon.current_hp -= (int)(damage * effectiveness);
                    cout << fighter.name << " used an attack dealing " << (int)(damage * effectiveness) << " damage to " << wild_pokemon.name << "!" << endl;
                    if (effectiveness > 1.0f) {
                        cout << "It's super effective!\n";
                    } else if (effectiveness < 1.0f) {
                        cout << "It's not very effective...\n";
                    }
                } else {
                    cout << "invalid attack choice or no uses left. you miss your turn." << endl;
                }

                if (wild_pokemon.current_hp <= 0) {
                    cout << wild_pokemon.name << " fainted! you won!" << endl;
                    level_up(fighter);
                    break;
                }

                int wild_attack_index = rand() % wild_pokemon.attacks.size();
                int wild_damage = wild_pokemon.attacks[wild_attack_index].damage;
                
                float wild_effectiveness = get_type_effectiveness(wild_pokemon.type, fighter.type);
                fighter.current_hp -= (int)(wild_damage * wild_effectiveness);
                cout << wild_pokemon.name << " attacked, dealing " << (int)(wild_damage * wild_effectiveness) << " damage to " << fighter.name << "!" << endl;
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
        cout << "welcome to the battle stadium! pick your fighter.\n";
        for (size_t i = 0; i < inventory.size(); i++) {
            cout << (i + 1) << ". " << inventory[i].name << " (Level: " << inventory[i].level << ")" << endl;
        }
        cout << "selection: ";
        int fighter_choice;
        cin >> fighter_choice;
        cout << endl;

        if (fighter_choice < 1 || fighter_choice > inventory.size()) {
            cout << "invalid choice." << endl;
            return;
        }

        pokemen& fighter = inventory[fighter_choice - 1];
        pokemen wild_pokemon = get_random_wild_pokemon(pokedex);
        string trainer_name = get_random_name(names);
        
        wild_pokemon.level = (rand() % 5) + 1;
        wild_pokemon.max_hp += (wild_pokemon.level - 1) * 10;
        wild_pokemon.current_hp = wild_pokemon.max_hp;
        for (size_t i = 0; i < wild_pokemon.attacks.size(); i++) {
            wild_pokemon.attacks[i].damage += (wild_pokemon.level - 1) * 5;
        }

        cout << "trainer " << trainer_name << " challenges you with their " << wild_pokemon.name << " (Level: " << wild_pokemon.level << ")!" << endl;
        cout << "you chose " << fighter.name << "." << endl;

        if (fighter.current_hp <= 0) {
            cout << "you cannot fight with a dead pokemon!\n";
        } else {
            while (fighter.current_hp > 0 && wild_pokemon.current_hp > 0) {
                cout << fighter.name << " (hp: " << fighter.current_hp << ") vs " << wild_pokemon.name << " (hp: " << wild_pokemon.current_hp << ")" << endl;

                cout << fighter.name << " can do the following attacks, which one do you want it to do?\n";
                for (size_t i = 0; i < fighter.attacks.size(); i++) {
                    cout << (i + 1) << ". " << "damage: " << fighter.attacks[i].damage << " amount left: " << fighter.attacks[i].amount << endl;
                }
                cout << "choice: ";
                int attack_choice;
                cin >> attack_choice;
                cout << endl;

                if (attack_choice > 0 && attack_choice <= fighter.attacks.size() && fighter.attacks[attack_choice - 1].amount > 0) {
                    int damage = fighter.attacks[attack_choice - 1].damage;
                    fighter.attacks[attack_choice - 1].amount--;

                    float effectiveness = get_type_effectiveness(fighter.type, wild_pokemon.type);
                    wild_pokemon.current_hp -= (int)(damage * effectiveness);
                    cout << fighter.name << " used an attack dealing " << (int)(damage * effectiveness) << " damage to " << wild_pokemon.name << "!" << endl;
                    if (effectiveness > 1.0f) {
                        cout << "It's super effective!\n";
                    } else if (effectiveness < 1.0f) {
                        cout << "It's not very effective...\n";
                    }
                } else {
                    cout << "invalid attack choice or no uses left. you miss your turn." << endl;
                }

                if (wild_pokemon.current_hp <= 0) {
                    cout << wild_pokemon.name << " fainted! you won against trainer " << trainer_name << "!" << endl;
                    level_up(fighter);
                    break;
                }

                int wild_attack_index = rand() % wild_pokemon.attacks.size();
                int wild_damage = wild_pokemon.attacks[wild_attack_index].damage;

                float wild_effectiveness = get_type_effectiveness(wild_pokemon.type, fighter.type);
                fighter.current_hp -= (int)(wild_damage * wild_effectiveness);
                cout << wild_pokemon.name << " attacked, dealing " << (int)(wild_damage * wild_effectiveness) << " damage to " << fighter.name << "!" << endl;
                if (wild_effectiveness > 1.0f) {
                    cout << "It's super effective!\n";
                } else if (wild_effectiveness < 1.0f) {
                    cout << "It's not very effective...\n";
                }

                if (fighter.current_hp <= 0) {
                    cout << fighter.name << " fainted! you lost to trainer " << trainer_name << "." << endl;
                    break;
                }
            }
        }
    }
}

void pokemon_heal(vector<pokemen>& inventory) {
    if (inventory.empty()) {
        cout << "you have no pokemon to heal." << endl;
        return;
    }
    cout << "healing all your pokemon..." << endl;
    for (auto& pokemon : inventory) {
        pokemon.current_hp = pokemon.max_hp;
    }
    cout << "your pokemon have been healed!" << endl;
}

int main() {
    srand(time(0));
    vector<pokemen> pokedex = {{"tardigrade", 200, 200, {{100, 1}, {80, 2}, {60, 3}}, 1, "space"}, {"bristlemouth", 120, 120, {{20, 1}, {15, 2}, {10, 3}}, 1, "water"}, {"quelea", 60, 60, {{40, 1}, {30, 2}, {20, 3}}, 1, "sky"}, {"ant", 90, 90, {{30, 1}, {25, 2}, {15, 3}}, 1, "ground"}, {"dodo", 1, 1, {{1, 1}, {1, 2}, {1, 3}}, 1, "useless"}};;
    vector<pokemen> inventory;
    vector<string> names = {"Dave", "Larose", "Nick", "Jonas", "Alex"};
    
    while (true) {
        cout << endl <<
            "1. explore\n" <<
            "2. battle\n" <<
            "3. heal_pokemon\n" <<
            "4. exit\n" <<
            "selection: ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "enter a number from 1 to 4 next time." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == menu::explore) {
            int random_index = rand() % pokedex.size();
            pokemen found_pokemon = pokedex[random_index];
            
            found_pokemon.level = (rand() % 5) + 1;
            found_pokemon.max_hp += (found_pokemon.level - 1) * 10;
            found_pokemon.current_hp = found_pokemon.max_hp;
            for (size_t i = 0; i < found_pokemon.attacks.size(); i++) {
                found_pokemon.attacks[i].damage += (found_pokemon.level - 1) * 5;
            }
            
            cout << "you found a wild " << found_pokemon.name << " (Level: " << found_pokemon.level << ")!" << endl;
            inventory.push_back(found_pokemon);
            cout << found_pokemon.name << " added to your inventory." << endl;
        } else if (choice == menu::battle) {
            cout << "what type of battle do you want?\n";
            cout << "1. wild battle\n";
            cout << "2. trainer battle\n";
            cout << "selection: ";
            int battle_choice;
            cin >> battle_choice;
            if (battle_choice == battle_type::wild || battle_choice == battle_type::trainer) {
                battle_logic(inventory, pokedex, names, battle_choice);
            } else {
                cout << "enter a nummber from 1 to 2 next time." << endl;
            }
        } else if (choice == menu::heal_pokemon) {
            pokemon_heal(inventory);
        } else if (choice == menu::exiting) {
            cout << "exiting..." << endl;
            return 0;
        } else {
            cout << "enter a number from 1 to 4 next time." << endl;
        }
    }
    return 0;
}