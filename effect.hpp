#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "spell.hpp"

// Declaration instead of #include to prevent circular inclusion.
// Let's hope the linker figures it out!
class Character;

class Effect {
public:
    Effect();

    virtual void apply(Character &character) const;
private:

};

class ModifyAC : public Effect {
public:
    ModifyAC(int delta_in);
    
    void apply(Character &character) const override;
private:
    int delta;
};

class ModifyHP : public Effect {
public:
    ModifyHP(int delta_in);

    void apply(Character &character) const override;

private:
    int delta;
};

class AddToSpellList : public Effect {
public:
    AddToSpellList(Spell *spell_in);

    void apply(Character &character) const override;
private:
    Spell *spell;
};

class RemoveFromSpellList : public Effect {
public:
    RemoveFromSpellList(Spell *spell_in);

    void apply(Character &character) const override;
private:
    Spell *spell;
};

#endif // EFFECT_HPP
