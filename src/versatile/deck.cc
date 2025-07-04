#include <algorithm>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

#include "../../include/versatile/card.h"
#include "../../include/versatile/deck.h"
#include "../../include/versatile/helper_func.h"
#include "../../include/versatile/suit_of_card.h"
#include "../../include/versatile/value_of_card.h"

Deck::Deck() : deck() {}

void Deck::init() {
    // デッキ内の全てのカード情報を削除
    deck.clear();

    // Suitの情報を配列化
    SuitOfCard suits[] = {SuitOfCard::Spade, SuitOfCard::Heart,
                          SuitOfCard::Diamond, SuitOfCard::Club};
    // Valueの情報を配列化
    ValueOfCard values[] = {
        ValueOfCard::Ace,   ValueOfCard::Two,   ValueOfCard::Three,
        ValueOfCard::Four,  ValueOfCard::Five,  ValueOfCard::Six,
        ValueOfCard::Seven, ValueOfCard::Eight, ValueOfCard::Nine,
        ValueOfCard::Ten,   ValueOfCard::Jack,  ValueOfCard::Queen,
        ValueOfCard::King};

    for (SuitOfCard suit : suits) {
        for (ValueOfCard value : values) {
            deck.push_back(std::make_unique<Card>(suit, value));
        }
    }
}

const std::vector<std::unique_ptr<Card>> &Deck::getDeck() const { return deck; }

void Deck::shuffle() {
    // パターン1
    // 乱数生成器の準備
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(deck.begin(), deck.end(), g);

    // パターン2
    //  std::size_t deckSize = deck.size();
    //  for (size_t i = 0; i < deckSize; ++i)
    //  {
    //      int randomNum =
    //      HelperFunc::getRandomNumber(static_cast<int>(deckSize));
    //      std::swap(deck.at(i), deck.at(randomNum));
    //  }
}

const std::unique_ptr<Card> Deck::draw() {
    if (deck.empty()) {
        return nullptr;
    }

    // 最後の要素を取得
    std::unique_ptr<Card> drawCard(std::move(deck.back()));

    // 最後の要素を削除
    deck.pop_back();

    return drawCard;
}

void Deck::reuse(std::vector<std::unique_ptr<Card>> &&discards) {
    deck = std::move(discards);
}

void Deck::printDeck() const {
    for (const auto &ptr : deck) {
        std::cout << ptr->toString() << std::endl;
    }
}