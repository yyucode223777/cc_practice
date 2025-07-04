#ifndef DECK_H
#define DECK_H

#include <memory>
#include <vector>

#include "card.h"

class Deck {
  public:
    // コンストラクタ
    Deck();

    // デッキを初期化
    void init();

    // デッキを取得(getter)
    const std::vector<std::unique_ptr<Card>> &getDeck() const;

    // デッキをシャッフル
    void shuffle();

    // デッキからカードのポインタを取得
    const std::unique_ptr<Card> draw();

    // 捨てカードを再利用
    void reuse(std::vector<std::unique_ptr<Card>> &&discards);

    // デッキの情報を表示
    void printDeck() const;

  private:
    std::vector<std::unique_ptr<Card>> deck;
};

#endif