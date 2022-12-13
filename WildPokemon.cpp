#include <iostream>
#include "WildPokemon.h"

using namespace std;

WildPokemon::WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc):GameObject('W', id, in_loc)
{
    this -> name = name;
    this -> attack = attack;
    this -> health = health;
    this -> variant = variant;
    this -> id_num = id;
    this -> location = in_loc;
    &get_in_combat = false;
    state = IN_ENVIRONMENT;
}

void WildPokemon::follow(Trainer* t)
{
    current_trainer = t;

    if ((((current_trainer -> GetLocation()).x) == (location.x)) && ((((current_trainer -> GetLocation()).y) == (location.y))))
    {
        state = IN_TRAINER;
    }
    else
    {
        state = IN_ENVIRONMENT;
    }
}

bool WildPokemon::get_variant()
{
    return variant;
}

double WildPokemon::get_attack()
{
    return attack;
}

double WildPokemon::get_health()
{
    return health;
}

bool WildPokemon::get_in_combat()
{
    if (current_trainer -> GetLocation() == location)
    {
        return in_combat;
    }

    else
    {
        return in_combat;
    }
}

bool WildPokemon::Update()
{
    if (state == IN_ENVIRONMENT)
    {
        return false;
    }

    else if (health <= 0)
    {
        state = DEAD;
    }

    else if (state == IN_TRAINER)
    {
        (location.x) = ((current_trainer -> GetLocation()).x);
        (location.y) = ((current_trainer -> GetLocation()).y);
        //Still things that need to be added
    }
}

void WildPokemon::ShowStatus()
{
    cout << "Wild Pokemon Status: " << endl;
    GameObject::ShowStatus();

    if (isAlive() == true)
    {
        cout << "State: Alive" << endl;
    }
    else
    {
        cout << "State: Dead" << endl;
    }
}

bool WildPokemon::isAlive()
{
    if (health > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}