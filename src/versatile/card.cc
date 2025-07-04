#include <string>
#include <iostream>

#include "../../include/versatile/card.h"
#include "../../include/versatile/suit_of_card.h"
#include "../../include/versatile/value_of_card.h"

Card::Card(SuitOfCard suit, ValueOfCard value) : suit(suit), value(value) {}

Card::Card(const Card &other) : suit(other.getSuit()), value(other.getValue()) {}

Card::~Card() {}

std::string Card::toString() const
{
    return suitToString(suit) + valueToString(value);
    // "(" + std::to_string(valueToInt(value)) + ")"
}

SuitOfCard Card::getSuit() const
{
    return suit;
}

ValueOfCard Card::getValue() const
{
    return value;
}