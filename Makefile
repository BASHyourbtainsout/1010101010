make guess_a_number: guess_a_number.cpp
	echo "Compiling "Guess a Number" game"
	g++ guess_a_number.cpp -o build/guess_a_number -lstdc++

make guess_a_number2: guess_a_number2.cpp
	echo "Compiling "Complicated Guess a Number" game"
	g++ guess_a_number.cpp -o build/guess_a_number2 -lstdc++

make hacked_rps: hacked_rps.cpp
	echo "Compiling "Hacked Rock Paper Scissors" game"
	g++ hacked_rps.cpp -o build/hacked_rps -lstdc++

make rps_vs_com: rps_vs_com.cpp
	echo "Compiling "Rock Paper Scissors with Computer" game"
	g++ rps_vs_com.cpp -o build/rps_vs_com -lstdc++

make tic_tac_toe: tic_tac_toe.cpp
	echo "Compiling "Tic Tac Toe" game"
	g++ tic_tac_toe.cpp -o build/tic_tac_toe -lstdc++

make treasure_island: treasure_island.cpp
	echo "Compiling "Treasure Island" game"
	g++ treasure_island.cpp -o build/treasure_island -lstdc++

make western_game: western_game.cpp
	echo "Compiling "Western Game""
	g++ western_game.cpp -o build/western_game -lstdc++
