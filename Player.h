/*
 * Player.h
 *
 *  Created on: 18 мая 2022 г.
 *      Author: Vlad
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>
#include "Map.h"

class Player final{
private:
	double _x {}, _y {}, _dir {};
	std::shared_ptr<Map> _map {};

public:
	Player() = default;
	void spawn(std::shared_ptr<Map> & m);

	double dir() const {return _dir;}
	double x () const {return _x;}
	double y () const {return _y;}

	void walk_fwd(double dist);
	void walk_back(double dist);
	void shift_left(double dist);
	void shift_right(double dist);
	void turn_left(double angle);
	void turn_right(double angle);


};

#endif
