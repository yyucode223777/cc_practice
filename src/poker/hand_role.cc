#include <stdexcept>
#include <string>

#include "../../include/poker/hand_role.h"

std::string handRoleToString(HandRole handRole) {
    switch (handRole) {
    case HandRole::NoPair:
        return "ノーペア";
    case HandRole::OnePair:
        return "ワン・ペア";
    case HandRole::TwoPair:
        return "ツー・ペア";
    case HandRole::ThreeCards:
        return "スリーカード";
    case HandRole::Straight:
        return "ストレート";
    case HandRole::Flush:
        return "フラッシュ";
    case HandRole::FullHouse:
        return "フルハウス";
    case HandRole::FourCards:
        return "フォー・カード";
    case HandRole::StraightFlush:
        return "ストレートフラッシュ";
    default:
        throw std::runtime_error("不正な値を検出しました");
    }
}

int handRoleToInt(HandRole handRole) { return static_cast<int>(handRole); }