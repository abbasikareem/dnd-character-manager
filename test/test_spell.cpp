#include "../utility/unit_test_framework.hpp"
#include "../header/spell.hpp"

TEST(test_fire_bolt_level_1) {
    csvstream csv("test_spellbook.csv");
    Spell fire_bolt_1(csv);
    assert(true);
}

TEST(test_fire_bolt_level_2) {
    assert(true);
}

TEST_MAIN()
