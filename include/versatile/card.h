#ifndef CARD_H
#define CARD_H

#include <string>

#include "suit_of_card.h"
#include "value_of_card.h"

class Card {
  public:
    // コンストラクタ
    Card(SuitOfCard suit, ValueOfCard value);

    // コピーコンストラクタ
    Card(const Card &other);

    // デストラクタ
    ~Card();

    // カードの情報を文字列で返す
    std::string toString() const;

    // suitを取得
    SuitOfCard getSuit() const;

    // valueを取得
    ValueOfCard getValue() const;

  private:
    const SuitOfCard suit;
    const ValueOfCard value;
};

#endif