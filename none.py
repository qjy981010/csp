class Archmage(MinionCard ) :
    def __init__ (self) :
        super().__init__("Archmage", 6, CHARACTER_CLASS.ALL, CARD_RARITY.COMMON)

    def create_minion (self, player) :
        return Minion(4, 7, spell_damage = 1)


{
    NAME:   "archmage"
    ATK:    4
    DEF:    7
    COST:   6
    DUR:    -1
    TYPE:   "Minion"
    CLASS:  "Neutral"
    RACE:   None
    RARITY: "Common"
    DESCRIPTION: "Spell Damage +1"
}
