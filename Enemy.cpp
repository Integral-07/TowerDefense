#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(Game* game) :Actor(game)
{
	GetGame()->AddEnemy(this);
}

void Enemy::UpdateActor()
{
}

void Enemy::ActorInput()
{
}
