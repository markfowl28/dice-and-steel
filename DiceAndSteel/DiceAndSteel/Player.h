#pragma once

struct Player {
	int health = 10;

	bool isAlive() const {
		return health > 0;
	}

	void takeDamage(int amount) {
		health -= amount;
		if (health < 0) health = 0;
	}
};
