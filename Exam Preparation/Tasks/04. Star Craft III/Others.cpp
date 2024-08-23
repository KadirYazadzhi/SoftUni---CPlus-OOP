#include "Viking.h"
#include "Phoenix.h"
#include "ProtossAirShip.h"
#include "BattleCruser.h"
#include "Carrier.h"
#include "TerranAirShip.h"

#include <iostream>
#include <vector>
#include <memory>

bool doDamage(AirShip * attacker, std::vector<std::unique_ptr<AirShip>> & enemyFleet, int damage) {
    AirShip * victim = enemyFleet.back().get();

    victim->takeDamage(damage);
    if (!victim->isAlive()) {
        switch (attacker->getAirShipType()) {
            case AirShipType::CARRIER:
                std::cout << "Carrier";
                break;
            case AirShipType::PHOENIX:
                std::cout << "Phoenix";
                break;
            case AirShipType::VIKING:
                std::cout << "Viking";
                break;
            case AirShipType::BATTLE_CRUSER:
                std::cout << "BattleCruser";
                break;
        }
        std::cout << " with ID: " << attacker->getAirShipId() << " killed enemy airship with ID: "
                  << victim->getAirShipId() << std::endl;

        enemyFleet.pop_back();
        return true;
    }

    return false;
}



TerranAirShip::TerranAirShip(const AirShipType type,
                             const int maxHealth,
                             const int damage,
                             const int shipId)
: AirShip(type, maxHealth, damage, shipId), _passedTurns(1) {}

void TerranAirShip::takeDamage(const int damage) {
    _currHealth -= damage;
    if (_currHealth < 0) {
        _currHealth = 0;
    }
}

void TerranAirShip::finishTurn() {
    _passedTurns++;
}



ProtossAirShip::ProtossAirShip(const AirShipType type,
               const int health,
               const int damage,
               const int maxShield,
               const int shieldRegenerateRate,
               const int shipId)
: AirShip(type, health, damage, shipId),
                _maxShield(maxShield),
                _shieldRegenerateRate(shieldRegenerateRate),
                _currShield(maxShield) {}

void ProtossAirShip::takeDamage(const int damage) {
    _currShield -= damage;
    if (_currShield < 0) {
        _currHealth += _currShield;
        _currShield = 0;
        if (_currHealth < 0) {
            _currHealth = 0;
        }
    }
}

void ProtossAirShip::finishTurn() {
    _currShield += _shieldRegenerateRate;
    if (_currShield > _maxShield) {
        _currShield = _maxShield;
    }
}



Viking::Viking(const AirShipType type,
               const int health,
               const int baseDamage,
               const int shipId)
: TerranAirShip(type, health, baseDamage, shipId) {}

void Viking::dealDamage (std::vector<std::unique_ptr<AirShip>> & enemyFleet) {
    AirShip * victim = enemyFleet.back().get();
    int damage = victim->getAirShipType() == AirShipType::PHOENIX ? _damage * 2 : _damage;

    doDamage(this, enemyFleet, damage);
}



Phoenix::Phoenix(const AirShipType type,
                 const int health,
                 const int damage,
                 const int maxShield,
                 const int shieldRegenerateRate,
                 const int shipId)
: ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId) {}

void Phoenix::dealDamage(std::vector <std::unique_ptr<AirShip>> &enemyFleet) {
    doDamage(this, enemyFleet, _damage);
}



BattleCruser::BattleCruser(const AirShipType type,
                           const int health,
                           const int damage,
                           const int shipId)
: TerranAirShip(type, health, damage, shipId) {}

void BattleCruser::dealDamage(std::vector <std::unique_ptr<AirShip>> &enemyFleet) {
    int damage = _damage;
    if (_passedTurns % (YAMATO_CANNON_LOADING_TIME + 1) == 0) {
        damage *= 5;
    }
    doDamage(this, enemyFleet, damage);
}



Carrier::Carrier(const AirShipType type,
                 const int health,
                 const int damage,
                 const int maxShield,
                 const int shieldRegenerateRate,
                 const int shipId)
: ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId), _activeInterceptors(MAX_INTERCEPTORS) {}

void Carrier::takeDamage(const int damage) {
    ProtossAirShip::takeDamage(damage);
    if (_currHealth < _maxHealth) {
        _activeInterceptors = DAMAGED_STATUS_INTERCEPTORS;
    }
}

void Carrier::dealDamage(std::vector <std::unique_ptr<AirShip>> &enemyFleet) {
    for (size_t curIc = 0; curIc < _activeInterceptors; curIc++) {
        if (doDamage(this, enemyFleet, _damage)) {
            if (enemyFleet.empty()) {
                return;
            }
        }
    }
}