//1211201118 林優花
#include "report-3-1211201118_pokergame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

PokerGame::PokerGame(){}

void PokerGame::shuffle_cards() {// 数字列をシャッフルして上から順番にとる。
  srand((unsigned int)time(NULL));  
	
	for (int i = 0; i < 52; i++) {
		random[i] = i;
	}
	
	int i=51;
	int tmp;

  while (i > 0) {
    int j = rand() % (i+1);
	  tmp = random[j];
    random[j] = random[i];
    random[i] = tmp;
    i--;
  }	
}

void PokerGame::convert_cards(int change_card_num) {
  
	if (random[card_stock_index] <= 12) {
		mark[change_card_num] = 'S';
		number[change_card_num] = random[card_stock_index] + 1;
	} else if (random[card_stock_index] >= 13 && random[card_stock_index] <= 25) {
		mark[change_card_num] = 'D';
		number[change_card_num] = random[card_stock_index] % 13 + 1;
	} else if (random[card_stock_index] >= 26 && random[card_stock_index] <= 38) {
		mark[change_card_num] = 'H';
		number[change_card_num] = random[card_stock_index] % 26 + 1;
	} else if (random[card_stock_index] >= 39) {
		mark[change_card_num] = 'C';
		number[change_card_num] = random[card_stock_index] % 39 + 1;
	}
}

void PokerGame::draw_cards() {
  cout << "カードをランダムで五枚引きます ｶﾞﾝﾊﾞｯﾃﾈ" << endl << endl;
  


	card_stock_index = 0;
	for (int j = 0; j < 5; j++) {
		convert_cards(j);
	  card_stock_index++;
	}


}

void PokerGame::change_cards() {

	int m;
  for (int j = 0; j < 5; j++) {
	  cout << j+1 <<"番目のカードを交換しますか？（0:交換しない, 1:交換する）" << endl;
    scanf(" %d", &m);
    if (m == 1) {
			
		  cout << j+1 <<"番目のカードを交換します" << endl;
      convert_cards(j);

			card_stock_index++;
	  } else {
		  cout << j+1 <<"番目のカードは交換しません" << endl;

	  }
  cout << endl;

  }

}

