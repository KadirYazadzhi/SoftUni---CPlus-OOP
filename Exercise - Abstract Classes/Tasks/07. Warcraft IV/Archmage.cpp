#include "Archmage.h"
#include <iostream>

Archmage::Archmage(const std::string &name,
                       const int maxMana,
                       const int baseManaRegenRate,
                       const int manaRegenModifier) :
        Hero (name, maxMana, baseManaRegenRate), _manaRegenModifier(manaRegenModifier) {}

void Archmage::castSpell(const SpellType spell) {
    const Spell & sp = _spells[spell];

    if (_currMana >= sp.manaCost) {
        std::cout << _name << " casted " << sp.name << " for " << sp.manaCost << " mana " << std::endl;
        _currMana -= sp.manaCost;

        if (spell == SpellType::ULTIMATE) {
           regenerateMana();
        }
    }
    else {
        std::cout << _name << " - not enough mana to cast " << sp.name << std::endl;
    }

}

void Archmage::regenerateMana() {
    _currMana += (_manaRegenRate * _manaRegenModifier);
    if (_currMana > _maxMana) {
        _currMana = _maxMana;
    }
}