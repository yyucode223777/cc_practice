#ifndef POKER_H
#define POKER_H

#include <array>
#include <memory>
#include <vector>

#include "../versatile/card.h"
#include "../versatile/deck.h"
#include "../versatile/game_flow.h"
#include "./player.h"

class Poker : public GameFlow {
  public:
    // コンストラクタ
    Poker();

    // ゲームの概要を説明
    void introduceGame() const override;

    // ゲームのメイン処理
    void playGame() override;

    // ゲームの初期化処理
    void initGame() override;

    // カードの配布
    void distributeCard(Player &p);

    // 手札内のカードを交換するかの確認
    bool confirmCardTrade();

    // 手札から捨てるカードを選択
    std::array<bool, 5> selectDiscard();

  private:
    const int rounds;
    Deck deck;
    std::vector<std::unique_ptr<Card>> discards;
    Player gamePlayer;
    Player dealer;
};

#endif