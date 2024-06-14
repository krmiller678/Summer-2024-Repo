// Module 3 Example Video 2
#include <iostream>
#include<string>
#include <vector>
#include "Hero.h"
using namespace std;

class Enemy
{
	Hero* _target; // Pointer is a primary way to share data
public:
	void SetTarget(Hero* target);
	void PrintTargetInfo();
	void ClearTarget();
};

void Enemy::SetTarget(Hero* target)
{
	cout << "Target acquired! Tracking " << target->GetName() << endl;
	_target = target;
}

void Enemy::PrintTargetInfo()
{
	cout << "Target: " << _target->GetName() << " Hitpoints: " << _target->GetHitpoints() << endl;
}

void Enemy::ClearTarget()
{
	cout << "Stand-by mode activated. " << endl;
	_target = nullptr;
}

int main()
{
	Hero wolverine("Wolverine", 50, 60);
	Hero cyclops("Cyclops", 30, 80);

	Enemy sentinel; // stores a Hero pointer
	sentinel.SetTarget(&wolverine);

	sentinel.PrintTargetInfo();

	wolverine.TakeDamage(20);

	sentinel.PrintTargetInfo();
	sentinel.SetTarget(&cyclops);
	sentinel.PrintTargetInfo();

	// Go to stand-by mode, don't track anyone
	//sentinel.SetTarget(nullptr); this could cause a crash. Add in checks to member functions
	sentinel.ClearTarget();

	return 0;
}