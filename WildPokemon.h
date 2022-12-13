#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H

#include "GameObject.h"
#include "Trainer.h"

#include <string>

using namespace std;

enum WildPokemonStates{
    IN_ENVIRONMENT = 10,
    DEAD = 11,
    IN_TRAINER = 12
};

class WildPokemon : public GameObject
{
    protected:
    double attack = 5.0;

    double health = 2.0;

    bool variant;

    bool in_combat = false;

    string name;

    Trainer* current_trainer;
    
    public:
    WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc);

    void follow(Trainer* t); //didnt finish definition

    bool get_variant();

    double get_attack();

    double get_health();

    bool get_in_combat();

    bool Update(); //didnt finish definition

    void ShowStatus();

    bool isAlive();

    

};

#endif