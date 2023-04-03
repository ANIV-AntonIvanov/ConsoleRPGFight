#ifndef MAINCLASS_H
#define MAINCLASS_H
#include <string>

using namespace std;

class MainClass
{
	public:
		MainClass();
		~MainClass();
		void setHealth(short int healthNew);
	    void setWeapon(string weaponNew);
	    void setEnergy(short int energyNew);
	    void setSpecial(string specialNew);
	    int getHealth();
	    int getEnergy();
	    string GetInfo();
	private:
		short int health;
		string weapon;
		short int energy;
		string special;
};

class Knight : public MainClass
{
	
};

class Enemy : public MainClass
{
	
};

#endif
