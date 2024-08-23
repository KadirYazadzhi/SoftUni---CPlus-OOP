#include "Glock.h"

#include <iostream>

Glock::Glock(const int damagePerRound,
                         const int clipSize,
                         const int remainingAmmo)
: Pistol(damagePerRound, clipSize, remainingAmmo) {

}

bool Glock::fire(PlayerVitalData &enemyPlayerData) {
    int healedDamage = _damagePerRound / 2;
    int armorDamage = _damagePerRound / 2;

    for (int currShot = 0; currShot < ROUNDS_PER_FIRE && enemyPlayerData.health > 0; currShot++) {
        if (_currClipBullets <= 0) {
            reload();
            return false;
        }

        _currClipBullets--;

        enemyPlayerData.armor -= armorDamage;
        if (enemyPlayerData.armor < 0) {
            enemyPlayerData.health += enemyPlayerData.armor;
            enemyPlayerData.armor = 0;
        }

        enemyPlayerData.health -= healedDamage;

        std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor" << std::endl;

    }

    return enemyPlayerData.health <= 0;
}