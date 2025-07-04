#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

#include "../../include/poker/hand_role.h"
#include "../../include/poker/judge_hand.h"
#include "../../include/poker/player.h"
#include "../../include/versatile/card.h"

Player::Player() : hand() {}

Player::~Player() {}

const std::vector<std::unique_ptr<Card>> &Player::getHand() const {
    return hand;
}

void Player::initHand() { hand.clear(); }

void Player::addToHand(std::unique_ptr<Card> cardPtr) {
    hand.push_back(std::move(cardPtr));
}

void Player::addToHand(std::unique_ptr<Card> cardPtr, size_t index) {
    hand.insert(hand.begin() + index, std::move(cardPtr));
}

const std::unique_ptr<Card> Player::getDiscard() {
    if (hand.empty()) {
        return nullptr;
    }

    std::unique_ptr<Card> discard(std::move(hand.at(hand.size() - 1)));

    // 末尾を削除
    hand.pop_back();

    return discard;
}

const std::unique_ptr<Card> Player::getDiscard(size_t index) {
    if (hand.empty() || hand.size() - 1 < index) {
        return nullptr;
    }

    std::unique_ptr<Card> discard(std::move(hand.at(index)));
    //--------------------------------------------------------------------------
    // 上記でunique_ptrの所有権を移動させたので、hand.at(index)はnullptrになってるのか確認
    //--------------------------------------------------------------------------

    // 移動元の要素は不要なので削除
    hand.erase(hand.begin() + index);

    return discard;
}

void Player::swapCards(int index, std::unique_ptr<Card> cardPtr) {
    if (index < hand.size() && index >= 0) {
        hand.erase(hand.begin() + index);
        hand.insert(hand.begin() + index, std::move(cardPtr));
    } else {
        std::cerr << "Index out of bounds." << std::endl;
    }
}

HandRole Player::getHandRole() const {
    if (JudgeHand::isStraightFlush(hand)) {
        return HandRole::StraightFlush;
    } else if (JudgeHand::isFourCards(hand)) {
        return HandRole::FourCards;
    } else if (JudgeHand::isFullHouse(hand)) {
        return HandRole::FullHouse;
    } else if (JudgeHand::isFlush(hand)) {
        return HandRole::Flush;
    } else if (JudgeHand::isStraight(hand)) {
        return HandRole::Straight;
    } else if (JudgeHand::isThreeCards(hand)) {
        return HandRole::ThreeCards;
    } else if (JudgeHand::isTwoPair(hand)) {
        return HandRole::TwoPair;
    } else if (JudgeHand::isOnePair(hand)) {
        return HandRole::OnePair;
    } else {
        return HandRole::NoPair;
    }
}

void Player::printHand() const {
    int index = 0;
    for (const auto &card : hand) {
        // デッキ内のカードがなくなった後、card(ポインタがnullPtr)->toString()を呼び出す際にエラーになっている
        std::cout << "[" << index << "] " << card->toString() << " |";
        ++index;
    }

    std::cout << std::endl;
}