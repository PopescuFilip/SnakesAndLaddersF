//
// Created by Alexandru Pestritu on 28.11.2024.
//

#ifndef DICEVALUE_H
#define DICEVALUE_H

enum class DiceValue {
    DICE_0 = 0,
    DICE_1 = 1,
    DICE_2 = 2,
    DICE_3 = 3,
    DICE_4 = 4,
    DICE_5 = 5,
    DICE_6 = 6
};


inline QString getDiceImagePath(const DiceValue& diceValue) {
    switch (diceValue) {
        case DiceValue::DICE_0: return ":/images/dice-6.png";
        case DiceValue::DICE_1: return ":/images/dice-1.png";
        case DiceValue::DICE_2: return ":/images/dice-2.png";
        case DiceValue::DICE_3: return ":/images/dice-3.png";
        case DiceValue::DICE_4: return ":/images/dice-4.png";
        case DiceValue::DICE_5: return ":/images/dice-5.png";
        case DiceValue::DICE_6: return ":/images/dice-6.png";
    }
    return {};
}

#endif //DICEVALUE_H
