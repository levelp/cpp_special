g++ -Wall -Wl,--stack=20000 main.cpp -o main_20000.exe
g++ -Wall -Wl,--stack=1000000 main.cpp -o main_1000000.exe
g++ -Wall -Wl,--stack=2000000 main.cpp -o main_2000000.exe
g++ -Wall -Wl,--stack=100000000 main.cpp -o main_100000000.exe
main_20000.exe
main_1000000.exe
main_2000000.exe

