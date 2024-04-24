//1211201118 林優花
/*課題や授業に関するコメント
どのプログラムファイルにどの関数を実装すべきなのか問題を理解するのが難しかった。いまも正しく要望通りにできているのかわからない。一週間で完成させる量とは思えないほどに食べ応えがあった。
このプログラムでこだわったところは所持金や最大設定金額、掛け金の設定の際に期待しない値が入力された際に処理のやり直し、または処理の中止が実行されるようにしたことである。少しプログラムを書くのが楽しみになると、早めに始めることができるので楽しめるところもあった。毎回かなり苦戦するが、今回はとりわけ難しかった。自分がいかに用語を理解していないか、苦手意識を積み上げてきてしまったかがよく分かった。
そして”残念でした”の処理がうまくいかない。無理くり完成させた。*/

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "report-3-1211201118_pokergame.h"

using namespace std;
PokerGame a;

int main () {
  int money, Maximum, bet = 0;
	
  cout << "最初の所持金を設定してください(  ͡   ͜   ͡   )" << endl; //カジノの入り口の笑顔
	scanf("%d", &money);
  if ( money <= 0 ) { //お金を持たない客は帰ってもらいましょう
    cout << "おかねがないとあそべないよ" << endl;
    return 0;
  }
  
  cout << "最大金額を設定してください" << endl;	
  scanf("%d", &Maximum);
	
  if ( money >= Maximum && Maximum > 0 ) {
    do {
      cout << "最大金額は所持金より多くしてください　再度、最大金額を設定してください" << endl;	
      scanf("%d", &Maximum);
    } while ( money >= Maximum );
	}
	
  cout << "所持金は" << money << " 円、最大金額は" << Maximum <<" 円と設定されました。" << endl;
  
  do {
    cout << "いくら賭けますか？‪" << endl;	//女ディーラーのイメージで
    scanf("%d", &bet);
    while ( money < bet || bet <= 0 ) {
      if ( money < bet ) { //お金が足りないときは煽りましょう
        do{
          cout << "お金足りないよww" << endl;
          cout << "いくら賭けますか？‪ ( 厂˙ω˙ )厂" << endl;	
          scanf("%d", &bet);
        } while ( money < bet ); //掛け金が所持金より多いときは聞き直し
      }
      if ( bet <= 0 ) { //客が金をかけずに遊ぼうとするときも煽りましょう
        do{
	        cout << "漢なら勝負しろよ" << endl;	
	        cout << "いくら賭けますか？‪ ( 厂˙ω˙ )厂" << endl;	
          scanf("%d", &bet);
	      } while ( bet <= 0 ); //掛け金が0円の時は聞き直し
      }
    }
    
    money = money - bet;
    cout << "掛け金は" << bet << " 円と設定されました" << endl;
    cout << "所持金の残りは" << money << "円です "<< endl << endl;
    
    a.shuffle_cards();
    a.draw_cards();
    a.print_cards();
    
    for (int i=0; i<2; i++) {    
      cout << i+1 << "回目の交換です。" << endl;
      a.change_cards();
      a.print_cards();
      cout << endl;
    } 
  
    int result1 = a.decision();
    cout << result1 << endl;
    
    if ( result1 == 0 ) {//残念でした…
      money -= bet;
      bet = 0;
    }
	  else if ( result1 == 1 ){//ワンペア
		 bet += bet / 10;//一割だけ返す
	  }
	  else if ( result1 == 2 ){//Jacks or Better
		 bet += bet / 10 * 3;//3割だけ返す
	  }
	  else if ( result1 == 3 ){//ツーペア
		 bet = bet * 2;
	  }
	 else if ( result1 == 4 ){//スリーカード
		 bet = bet * 3;
	 }
	 else if ( result1 == 5 ){//ストレート
		 bet = bet * 4;
	 }
	 else if ( result1 == 6 ){//フラッシュ
		 bet = bet * 5;
	 }
	 else if ( result1 == 7 ){//フルハウス
		 bet = bet * 7;
	 }
	 else if ( result1 == 8 ){//フォーカード
		 bet = bet * 10;
	 }
	 else if ( result1 == 9 ){//ストレートフラッシュ
		 bet = bet * 50;
	 }
	 else if( result1 == 10 ){//ロイヤルストレートフラッシュ
		 bet = bet * 100;
	 } 


   money = money + bet;
	 cout << "払戻額: " << bet << "円  " << "所持金: " << money << "円" << endl << endl;
  } while ( money > 0 && money < Maximum);
	
  cout << endl;
  if ( money <= 0 ) {
   cout << "ギャンブルはほどほどにね　(お金が無くなりました)" << endl;
  } else if ( money > Maximum ) {
    cout << "やるやん！　(設定された最大金額を超えました)" << endl;
  }

  return 0;	 
}