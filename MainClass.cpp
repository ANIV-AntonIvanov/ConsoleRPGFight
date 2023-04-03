#include "MainClass.h"
#include <string>
#include <iostream>

using namespace std;

MainClass::MainClass()
{
}

MainClass::~MainClass()
{
}

void MainClass::setHealth(short int healthNew){health = healthNew;}
void MainClass::setWeapon(string weaponNew){weapon = weaponNew;}
void MainClass::setEnergy(short int energyNew){energy = energyNew;}
void MainClass::setSpecial(string specialNew){special = specialNew;}
string MainClass::GetInfo(){return "Health:" + to_string(health) + " Weapon:" + weapon + " Energy:" + to_string(energy) + " Special:" + special;}
int MainClass::getHealth(){return health;}
int MainClass::getEnergy(){return energy;}

