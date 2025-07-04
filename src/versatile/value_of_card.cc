#include <stdexcept>
#include <string>

#include "../../include/versatile/value_of_card.h"

std::string valueToString(ValueOfCard value) {
    switch (value) {
    case ValueOfCard::Ace:
        return "A";
    case ValueOfCard::Two:
        return "2";
    case ValueOfCard::Three:
        return "3";
    case ValueOfCard::Four:
        return "4";
    case ValueOfCard::Five:
        return "5";
    case ValueOfCard::Six:
        return "6";
    case ValueOfCard::Seven:
        return "7";
    case ValueOfCard::Eight:
        return "8";
    case ValueOfCard::Nine:
        return "9";
    case ValueOfCard::Ten:
        return "10";
    case ValueOfCard::Jack:
        return "J";
    case ValueOfCard::Queen:
        return "Q";
    case ValueOfCard::King:
        return "K";
    default:
        throw std::runtime_error("不正な値を検出しました");
    }
}

int valueToInt(ValueOfCard value) { return static_cast<int>(value); }