#ifndef _STATIC_ENTITY_H_
#define _STATIC_ENTITY_H_

#include "Entity.h"

enum Static_State {
	STATIC_IDLE,
	STATIC_DIE,
	STATIC_DESTROYED,
	STATIC_HOVERED = 1,
	STATIC_OFF = 2
};


class StaticEntity : public Entity
{
public:
	StaticEntity();
	StaticEntity(pugi::xml_node entity_node, fPoint position, Faction faction);
	~StaticEntity();

	virtual bool PreUpdate() { return true; };
	virtual bool Update(float dt);
	virtual bool PostUpdate();
	virtual bool CleanUp();

	virtual void Die();

protected:
	Static_State state = STATIC_IDLE;
};

#endif // _STATIC_ENTITY_H_



