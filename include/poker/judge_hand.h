#ifndef JUDGE_HAND_H
#define JUDGE_HAND_H

#include <memory>
#include <vector>

#include "../versatile/card.h"

class JudgeHand {
  public:
    // 同じ数字のカード2枚のペア1組が存在する時trueを返す
    static bool isOnePair(const std::vector<std::unique_ptr<Card>> &hand);
    // 同じ数字のカード2枚のペアが2組存在する時trueを返す
    static bool isTwoPair(const std::vector<std::unique_ptr<Card>> &hand);
    // 同じ数字のカード3枚存在する時trueを返す
    static bool isThreeCards(const std::vector<std::unique_ptr<Card>> &hand);
    // リスト内のカードの数字が全て連続している時trueを返す
    static bool isStraight(const std::vector<std::unique_ptr<Card>> &hand);
    // リスト内のカードが全て同じSuitの時trueを返す
    static bool isFlush(const std::vector<std::unique_ptr<Card>> &hand);
    // ツー・ペアとスリーカードの組み合わせの時trueを返す
    static bool isFullHouse(const std::vector<std::unique_ptr<Card>> &hand);
    // 同じ数字のカード4枚存在する時trueを返す
    static bool isFourCards(const std::vector<std::unique_ptr<Card>> &hand);
    // リスト内のカードが全て連続していて、尚且つ全てのカードが同じスートの時trueを返す
    static bool isStraightFlush(const std::vector<std::unique_ptr<Card>> &hand);
};

#endif