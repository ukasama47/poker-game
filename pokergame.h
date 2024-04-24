
#include "report-3_poker.h"

class PokerGame : public Poker {

private:
int random[51];
int card_stock_index;//カードをカウント

public:
  PokerGame(); // コンストラクタ、引数なし

  void shuffle_cards(); //カードを繰ります

  void convert_cards(int change_card_num);//対応するカードを決める
     
  void draw_cards(); // カードをランダムに五枚引く、引数なし

  void change_cards(); // カードを交換、引数なし

}; // class PokerGame
