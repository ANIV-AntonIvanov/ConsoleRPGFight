#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "MainClass.h"

using namespace std;

//Enemy encounter
void enemyEncounter(bool enemyEn)
{
	do
    {
    	enemyEn = rand() % (1+1) + 0;
    	if(enemyEn == 1)
		    break;
        cout << "You did not encounter an enemy,trying again." << endl;
	}while(enemyEn == 0);
	cout << "You've encountered an enemy" << endl;
}

//Fightlogic
int FightLogic(short int hp,short int en,short int hpAI,short int enAI)
{
	while(hpAI > 0 && hp > 0)
    {
	    unsigned short int attackCase;
	    bool attackCaseAI = rand() % (1+1) + 0; 
	    unsigned short int attack;
	    unsigned short int attackAI;
	    //Player----------------------
	    cout << "---------------------------------" << endl;
	    cout << "---------------------------------" << endl;
	    cout << "---------------------------------" << endl;
	    cout << "---------------------------------" << endl;
	    cout << "Type 1 for Normal Attack" << endl;
	    cout << "Type 2 for Special Attack" << endl;
	    cin >> attackCase;
	    switch(attackCase)
	    {
		    case 1:
			    attack = (rand() % (34 + 1 - 20)) + 20;
			    cout << attack << " ";
			    cout << "Damage dealt from Normal Attack" << endl;
			    break;
		    case 2:
			    if(en < 20)
	            {
	        	    cout << "Your energy is below 20 you can not use Special Attack" << endl;
		            attack = (rand() % (34 + 1 - 20)) + 20;
		            cout << "Damage dealt from Normal Attack:" << attack << endl;
		            break;
	            }
			    attack = (rand() % (50 + 1 - 35)) + 35;
			    cout << "Damage dealt from Special Attack:"<< attack << endl;
			    en -= 20;
		        cout << "Energy left:" << en << endl;
			    break;
	    }
	    
	    hpAI = hpAI - attack;
	
	    if(hpAI <= 0)
	        break;
	
	    cout << "Enemy health left:" << hpAI << endl;
	
	    //AI----------------AI
	    cout << "--------------------------------" << endl;
	    cout << "Enemy's turn" << endl;
	    cout << "Enemy attacks" << endl;
	    
	    switch(attackCaseAI)
	    {
	    	case 0:
	    		attackAI = (rand() % (34 + 1 - 20)) + 20;
	    		cout << "Damage dealt from Enemy:" << attackAI << endl;
	    		break;
	    	case 1:
	    		if(enAI < 20)
		        {
		            attackAI = (rand() % (34 + 1 - 20)) + 20;
		            cout << "Enemy does not have enough energy for a Special Attack" << endl;
		            cout << "Damage dealt by enemy:" << attackAI << endl;
		            break;
		        }
		        attackAI = (rand() % (50 + 1 - 35)) + 35;
				cout << "Enemy tries to use a Special Attack" << endl;
		        cout << "Damage dealt by Special Attack:" << attackAI << endl;
		        enAI -= 20;
		        cout << "Enemy's energy:" << enAI << endl;
		        break;
		}

	    if(hp <= 0)
	        break;
			
	    hp = hp - attackAI;
	    cout << "Health Left:" << hp << endl;
    }
    
    cout << "----------------------------------------------------" << endl;
    
    if(hp > 0)
    	cout << "You Win!!" << endl;
	else 
	    cout << "You Lose!!" << endl;
}


int main(int argc, char** argv) 
{
	srand(time(NULL));
	
	string game = "Yes";
	
	bool enemyEn;
	
	cout << "Type: 'Knight' to start the game" << endl;
	
	string userIn;
	cin >> userIn;
	
    if(userIn == "Knight")
    {
    	while(game == "Yes")
    	{
    	    Enemy enemyOne;
    	    Knight heroOne;
    	    MainClass * hOne;
    	    MainClass * eOne;
    	    
    	    hOne = &heroOne;
    	    eOne = &enemyOne;
    	    
    	    hOne->setHealth(150);
    	    hOne->setWeapon("Long Sword");
    	    hOne->setEnergy(50);
    	    hOne->setSpecial("Charge attack");
    	    cout << hOne->GetInfo() << endl;
    	    
    	    short int health,energy;
    	    health = hOne->getHealth();
    	    energy = hOne->getEnergy();
    	    
    	    enemyEncounter(enemyEn);
    	    
    	    eOne->setHealth(rand() % ((130 + 1 - 120)) + 100);
            eOne->setWeapon("dagger");
            eOne->setEnergy(50);
            eOne->setSpecial("double attack");
            cout << eOne->GetInfo() << endl;
        
            short int healthAI,energyAI;
            healthAI = eOne->getHealth();
            energyAI = eOne->getEnergy();
            
            FightLogic(health,energy,healthAI,energyAI);
            
            cout << "Type 'Yes' if you want to play again" << endl;
            cin >> game;
            system("cls");
        }
	}
	return 0;
}
