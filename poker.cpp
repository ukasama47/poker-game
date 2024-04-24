//1211201118 林優花
#include <stdio.h>
#include <stdlib.h>
#include "report-3_poker.h"

Poker::Poker() {
  for (int i = 0; i < 5; i++) {
    mark[i] = 'S';
    number[i] = i + 1;
  }
}
    
void Poker::input_cards() { // 引くカードを入力

  for (int i = 0; i < 5; i++) {
    printf("%d番目のカードを入力して下さい (マーク, 数字)\n", (i+1));
    scanf(" %c, %d", &mark[i], &number[i]);

    if (mark[i] != 'S' && mark[i] != 'H' && mark[i] != 'D' &&  mark[i] != 'C') {
      printf("入力したマークは無効です\n");
      exit(1);
    }

    if (number[i] < 1 || number[i] > 13) {
      printf("入力した数字は無効です\n");
      exit(1);
    }
  }

  return;
} // void input_cards()

void Poker::print_cards() { // 引いたカードを表示

  for (int i = 0; i < 5; i++) {
    printf("-%d-  ", (i+1));
  }
  printf("\n");

  for (int i = 0; i < 5; i++) {
    printf("%c", mark[i]);
    printf("%2d  ", number[i]);
  }
  printf("\n");

  return;
} // void print_cards()

int Poker::flush() { // フラッシュ判定 return 1:フラッシュ return 0:フラッシュでない

  for (int i = 1; i < 5; i++) {
    if (mark[0] != mark[i]) { // 1枚でもマークが違えばフラッシュでない
      return 0;
    }
  }

  // マークが違うカードが1枚も無ければフラッシュ
  return 1;
}

int Poker::straight() { // ストレート判定 return 1:ストレート return 0:ストレートでない

  if (number[0] == 1 && number[1] == 10 && number[2] == 11 
      && number[3] == 12 && number[4] == 13) { // 数字が連続しないパターンを先に判定
    return 1;
  }

  for (int i = 0; i < 4; i++) {
    if (number[i] + 1 != number[i+1]) { // 1つでも数字が連続しなければストレートでない
      return 0;
    }
  }

  return 1;
}

int Poker::pair() { // 同一数字に関係するハンドを判定
  // return 1:ワンペア 2:ツーペア 3:スリーカード 4:フルハウス 5:フォーカード 0:該当なし

  // 5:フォーカード
  for (int i = 0; i < 2; i++) {
    // 数字がソートされているためnumber[0]またはnumber[4]のみの数字が異なる
    if (number[i] == number[i+3]) {
      return 5;
    }
  }

  // 4:フルハウス
  if (number[0] == number[2] && number[3] == number[4] 
      || number[0] == number[1] && number[2] == number[4]) {

    return 4;
  }

  // 3:スリーカード
  for (int i = 0; i < 3; i++) {
    if (number[i] == number[i+2]) {
      return 3;
    }
  }

  // 2:ツーペア
  for (int i = 0; i < 2; i++) {
    if (number[i] == number[i + 1]) {
      for (int j = i + 2; j < 4; j++) {
        if (number[j] == number[j + 1]) {
          return 2;
        }
      }
    }
  }

  // 1:ワンペア
  for (int i = 0; i < 4; i++) {
    if (number[i] == number[i+1]) {

    // 6: 新しいハンド Jacks or Better (J以上のワンペア)
    if (number[i] >= 11) {
      return 6;
    } else {

      // ワンペア
      return 1;
    }
    }
  }

  return 0;
} // int pair()

int Poker::decision() { // ハンドを判定

  int decision1, decision2, tmp;

  // 数が小さい順に並べ替え
  for (int i = 0; i < 5; i++) {
    for (int j = i+1; j < 5; j++) {
      if(number[i] > number[j]) {
        tmp = number[i];
        number[i] = number[j];
        number[j] = tmp;
      }
    }
  }

  decision1 = flush();
  decision2 = straight();

  if (decision1 == 1 && decision2 == 1) {
  // 数字がソートされているため最小1その次最小10で該当
    if (number[0] == 1 && number[1] == 10) {
      printf("ロイヤルストレートフラッシュ\n");
      return 10;

    } else {
      printf("ストレートフラッシュ\n");
      return 9;
    }
  } else if (decision1 == 1) {
    printf("フラッシュ\n");
    return 6;

  } else if (decision2 == 1) {
    printf("ストレート\n");
    return 5;
  }

  decision1 = pair();

  if (decision1 == 5) {
    printf("フォーカード\n");
    return 8;
  } else if (decision1 == 4) {
    printf("フルハウス\n");
    return 7;
  } else if (decision1 == 3) {
    printf("スリーカード\n");
    return 4;
  } else if (decision1 == 2) {
    printf("ツーペア\n");
    return 3;
  } else if (decision1 == 1) {
    printf("ワンペア\n");
    return 1;
  } else if (decision1 == 6) {
    printf("Jacks or Better\n");
    return 2;
  } else if (decision1 == 0) {
    printf("残念でした…\n");
  }

  return 0;
} // int decision()
