#ifndef _CORE_H_
#define _CORE_H_

#include <map>

#include "p2Defs.h"
#include "StaticEntity.h"

class Deck;


class Core : public StaticEntity
{
public:
	enum CardNumber {
		CN_UNKNOWN = -1,
		CN_FIRST,
		CN_SECOND,
		CN_THIRD,
		CN_FOURTH
	};

public:
	Core(pugi::xml_node entity_config, fPoint position, Faction faction);
	~Core();

	bool Update(float dt);

	bool CleanUp();

	void UseCard(CardNumber number, fPoint position);
	void SetDeck(Deck* new_deck);
	Card* GetCard(CardNumber card_num) const;

	Stat* GetEnergy() const;


private:
	const uint ENEGY_TICK_RATE = 1000;
	Deck* deck = nullptr;

	PerfTimer energy_timer;

};

#endif // _CORE_H_




