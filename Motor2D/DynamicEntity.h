#ifndef _DYNAMIC_ENTITY_
#define _DYNAMIC_ENTITY_

#include "Entity.h"

struct Card;

enum DynamicState {
	DYNAMIC_IDLE,
	DYNAMIC_MOVING,
	DYNAMIC_ATTACKING,
	DYNAMIC_DYING
};

enum EntiyDirection {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UP_RIGHT,
	UP_LEFT,
	DOWN_RIGHT,
	DOWN_LEFT
};

class DynamicEntity : public Entity
{
public:
	DynamicEntity();
	~DynamicEntity();
	DynamicEntity(pugi::xml_node config, fPoint position, Card* card, Faction faction);

	virtual bool PreUpdate();
	virtual bool Update(float dt);
	virtual bool PostUpdate();
	virtual bool CleanUp() { return true; };
	virtual bool Start();


protected:
	void CalcDirection();
	void CheckDestination();
	virtual void Die() {};
	virtual void Move(float dt);
	virtual void Attack() {};
protected:
	DynamicState state = DYNAMIC_IDLE;
	int current_point = 0;
	int previous_point = 0;
	EntiyDirection direction = UP;
	Card* entity_card = nullptr;
	std::vector<iPoint> path;
};

#endif // !_DYNAMIC_ENTITY_



