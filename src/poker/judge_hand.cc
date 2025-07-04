#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <vector>

#include "../../include/poker/judge_hand.h"
#include "../../include/versatile/value_of_card.h"

bool JudgeHand::isOnePair(const std::vector<std::unique_ptr<Card>> &hand) {
    std::set<ValueOfCard> valueSet;

    for (const auto &card : hand) {
        // valueSetに手札内のカードのvalueを追加
        auto insertResult = valueSet.insert(card->getValue());

        // 追加処理を実行した結果、要素が追加されていなければ同じvalueが既に存在
        // -> 手札内に同じ数字のペア1組が存在するのでtrueを返す
        if (!insertResult.second) {
            return true;
        }
    }

    return false;
}

bool JudgeHand::isTwoPair(const std::vector<std::unique_ptr<Card>> &hand) {
    std::map<ValueOfCard, int> valueMap;

    for (const auto &card : hand) {
        ValueOfCard current = card->getValue();
        auto iterator = valueMap.find(current);

        // valueMap内に同じ数字のカードが見つかった場合
        // -> 値をインクリメント
        if (iterator != valueMap.end()) {
            valueMap[current]++;
        }
        // valueMap内に同じ数字のカードが見つからなかった場合
        // -> valueMapに新規追加
        else {
            valueMap.emplace(current, 1);
        }
    }

    int pairCount = 0;

    for (const auto &[key, value] : valueMap) {
        if (value >= 2) {
            pairCount++;
        }
    }

    return pairCount == 2;
}

bool JudgeHand::isThreeCards(const std::vector<std::unique_ptr<Card>> &hand) {
    std::map<ValueOfCard, int> valueMap;

    for (const auto &card : hand) {
        ValueOfCard current = card->getValue();
        auto iterator = valueMap.find(current);

        // valueMap内に同じ数字のカードが見つかった場合
        // -> 値をインクリメント
        if (iterator != valueMap.end()) {
            valueMap[current]++;
        }
        // valueMap内に同じ数字のカードが見つからなかった場合
        // -> valueMapに新規追加
        else {
            valueMap.emplace(current, 1);
        }
    }

    for (const auto &[key, value] : valueMap) {
        if (value == 3) {
            return true;
        }
    }

    return false;
}

bool JudgeHand::isStraight(const std::vector<std::unique_ptr<Card>> &hand) {
    // set -> 要素は常にソートされた状態で格納される
    std::set<ValueOfCard> valueSet;

    for (const auto &card : hand) {
        // valueSetに手札内のカードのvalueを追加
        auto insertResult = valueSet.insert(card->getValue());

        // 追加処理を実行した結果、要素が追加されていなければ同じvalueが既に存在
        // ->
        // 手札内の全てのカードの数字が連続して並ぶ条件に合致しないのでfalseを返す
        if (!insertResult.second) {
            return false;
        }
    }

    for (auto it = valueSet.begin(); it != valueSet.end(); ++it) {
        ValueOfCard currentValue = *it;

        auto next_it = std::next(it);
        // 次の要素が存在しない場合はループ終了
        if (next_it != valueSet.end()) {
            ValueOfCard nextValue = *next_it;
            if ((valueToInt(currentValue) + 1) == valueToInt(nextValue)) {
                continue;
            }

            return false;
        }
    }

    return true;
}

bool JudgeHand::isFlush(const std::vector<std::unique_ptr<Card>> &hand) {
    for (auto it = hand.begin(); it != hand.end(); ++it) {
        auto next_it = std::next(it);
        // 次の要素が存在しない場合はループ終了
        if (next_it != hand.end()) {
            if (((*it)->getSuit()) == (*next_it)->getSuit()) {
                continue;
            }

            return false;
        }
    }

    return true;
}

bool JudgeHand::isFullHouse(const std::vector<std::unique_ptr<Card>> &hand) {
    return JudgeHand::isTwoPair(hand) && JudgeHand::isThreeCards(hand);
}

bool JudgeHand::isFourCards(const std::vector<std::unique_ptr<Card>> &hand) {
    std::map<ValueOfCard, int> valueMap;

    for (const auto &card : hand) {
        ValueOfCard current = card->getValue();
        auto iterator = valueMap.find(current);

        // valueMap内に同じ数字のカードが見つかった場合
        // -> 値をインクリメント
        if (iterator != valueMap.end()) {
            valueMap[current]++;
        }
        // valueMap内に同じ数字のカードが見つからなかった場合
        // -> valueMapに新規追加
        else {
            valueMap.emplace(current, 1);
        }
    }

    for (const auto &[key, value] : valueMap) {
        if (value == 4) {
            return true;
        }
    }

    return false;
}

bool JudgeHand::isStraightFlush(
    const std::vector<std::unique_ptr<Card>> &hand) {
    return JudgeHand::isStraight(hand) && JudgeHand::isFlush(hand);
}