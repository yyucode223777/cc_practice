#ifndef HAND_ROLE_H
#define HAND_ROLE_H

#include <string>

enum class HandRole {
    NoPair = 1,
    OnePair,
    TwoPair,
    ThreeCards,
    Straight,
    Flush,
    FullHouse,
    FourCards,
    StraightFlush
};

// HandRoleをenum classから文字列に変換
std::string handRoleToString(HandRole handRole);

// HandRoleをenum classからint型に変換
int handRoleToInt(HandRole handRole);

#endif
