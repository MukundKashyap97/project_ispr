out: func.h func.cpp func_rk4.h func_rk4.cpp func_segway.h func_segway.cpp main.cpp

	g++ -o out main.cpp func.cpp func_rk4.cpp func_segway.cpp
clean:
	rm out