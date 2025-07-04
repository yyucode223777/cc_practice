#ifndef VALUE_OF_CARD_H
#define VALUE_OF_CARD_H

#include <string>

enum class ValueOfCard {
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

// Valueをenum classから文字列に変換
std::string valueToString(ValueOfCard value);

// Valueをenum classからint型に変換
int valueToInt(ValueOfCard value);

#endif