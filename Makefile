#1211201118 林優花
#コンパイル時には生成されたpoker_main.exeを指定して実行してください。
CXX=g++

poker_main: report-3_poker.o report-3-1211201118_main.o report-3-1211201118_pokergame.o
	$(CXX) -o poker_main.exe report-3_poker.o report-3-1211201118_main.o report-3-1211201118_pokergame.o


report-3_poker.o:report-3-1211201118_pokergame.cpp

report-3-1211201118_main.o:report-3-1211201118_main.cpp

report-3-1211201118_pokergame.o:report-3-1211201118_pokergame.cpp

clean:
	rm -f poker_main.exe report-3_poker.o report-3-1211201118_main.o report-3-1211201118_pokergame.o

