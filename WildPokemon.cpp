#include <iostream>
#include "WildPokemon.h"

using namespace std;

WildPokemon::WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc):GameObject(in_loc, id, 'W')
{
    this -> name = name;
    this -> attack = attack;
    this -> health = health;
    this -> variant = variant;
    this -> id_num = id;
    this -> location = in_loc;
    state = IN_ENVIRONMENT;
}

void WildPokemon::follow(Trainer* t)
{
    current_trainer = t;
    int x;
    int y;
    (location.x) = ((current_trainer -> GetLocation()).x);
    (location.y) = ((current_trainer -> GetLocation()).y);
    
    if (state == DEAD){
        cout << display_code << id_num << "Your Pokemon Died" << endl;
    }
    else if (GetDistanceBetween(t -> GetLocation(), location) == 0){
        state = IN_TRAINER;
        cout << display_code << id_num << "Pokemon is following Trainer" << endl;
    }
    else{
        state = IN_ENVIRONMENT;
        cout << display_code << id_num << current_trainer -> GetId () << endl;
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
    return in_combat;
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
        return false;
    }

    else if (GetDistanceBetween(current_trainer -> GetLocation(), location) == 0)
    {
        state = IN_TRAINER;
        cout << display_code << id_num << "Pokemon is following Trainer" << endl;
        return false;
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

bool WildPokemon::ShouldBeVisible()
{
    if (state == DEAD){
        return false;
    }
    else{
        return true;
    }
}
