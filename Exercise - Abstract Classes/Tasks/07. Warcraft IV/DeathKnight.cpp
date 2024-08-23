#include "DeathKnight.h"
#include <iostream>

DeathKnight::DeathKnight(const std::string &name,
                   const int maxMana,
                   const int baseManaRegenRate) :
        Hero (name, maxMana, baseManaRegenRate) {}

void DeathKnight::castSpell(const SpellType spell) {
    const Spell & sp = _spells[spell];

    if (_currMana >= sp.manaCost) {
        std::cout << _name << " casted " << sp.name << " for " << sp.manaCost << " mana " << std::endl;
        _currMana -= sp.manaCost;

        if (spell == SpellType::ULTIMATE) {
            std::cout << _name << " casted " << _spells[SpellType::BASIC].name << " for 0 mana " << std::endl;
        }
    }
    else {
        std::cout << _name << " - not enough mana to cast " << sp.name << std::endl;
    }

}

void DeathKnight::regenerateMana() {
    _currMana += _manaRegenRate;
    if (_currMana > _maxMana) {
        _currMana = _maxMana;
    }
}
