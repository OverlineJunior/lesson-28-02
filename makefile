all: main.exe run

main.exe: src/main.c libs/lesson/lesson.c
	@clang -Wall -lm -o main.exe src/main.c libs/lesson/lesson.c

run: main.exe
	@./main.exe
