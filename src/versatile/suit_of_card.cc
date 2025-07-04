#include <stdexcept>
#include <string>

#include "../../include/versatile/suit_of_card.h"

std::string suitToString(SuitOfCard suit) {
    switch (suit) {
    case SuitOfCard::Spade:
        return "♠";
    case SuitOfCard::Heart:
        return "♥";
    case SuitOfCard::Diamond:
        return "♦";
    case SuitOfCard::Club:
        return "♣";
    default:
        throw std::runtime_error("不正な値を検出しました");
    }
}