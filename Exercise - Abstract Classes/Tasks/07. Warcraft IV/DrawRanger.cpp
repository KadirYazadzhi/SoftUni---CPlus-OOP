#include "DrawRanger.h"
#include <iostream>

DrawRanger::DrawRanger(const std::string &name,
                       const int maxMana,
                       const int baseManaRegenRate) :
                       Hero (name, maxMana, baseManaRegenRate) {}

void DrawRanger::castSpell(const SpellType spell) {
    const Spell & sp = _spells[spell];

    if (_currMana >= sp.manaCost) {
        std::cout << _name << " casted " << sp.name << " for " << sp.manaCost << " mana " << std::endl;
        _currMana -= sp.manaCost;

        if (spell == SpellType::BASIC) {
            std::cout << _name << " casted " << sp.name << " for " << 0 << " mana " << std::endl;
        }
    }
    else {
        std::cout << _name << " - not enough mana to cast " << sp.name << std::endl;
    }

}

void DrawRanger::regenerateMana() {
    _currMana += _manaRegenRate;
    if (_currMana > _maxMana) {
        _currMana = _maxMana;
    }
}