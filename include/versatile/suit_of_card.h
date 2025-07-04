#ifndef SUIT_OF_CARD_H
#define SUIT_OF_CARD_H

#include <string>

enum class SuitOfCard { Spade, Heart, Diamond, Club };

// Suitをenum classから文字列に変換
std::string suitToString(SuitOfCard suit);

#endif