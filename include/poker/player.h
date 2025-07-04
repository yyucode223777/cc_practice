#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <vector>

#include "../versatile/card.h"
#include "./hand_role.h"

class Player {
  public:
    // コンストラクタ
    Player();

    // デストラクタ
    ~Player();

    // 手札を取得(getter)
    const std::vector<std::unique_ptr<Card>> &getHand() const;

    // 手札を初期化
    void initHand();

    // 手札にカードを追加
    void addToHand(std::unique_ptr<Card> cardPtr);

    // 手札の任意の位置にカードを追加
    void addToHand(std::unique_ptr<Card> cardPtr, size_t index);

    // 手札内の末尾のカードを破棄
    const std::unique_ptr<Card> getDiscard();

    // 手札内のカードを破棄
    const std::unique_ptr<Card> getDiscard(size_t index);

    // 手札内のカードを交換する
    void swapCards(int index, std::unique_ptr<Card> cardPtr);

    // 手札の役を取得
    HandRole getHandRole() const;

    // 手札を表示
    void printHand() const;

  private:
    std::vector<std::unique_ptr<Card>> hand;
};

#endif