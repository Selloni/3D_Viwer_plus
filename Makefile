CC+FLAGS = gcc -std=c11 -Wall -Wextra -Werror
GCOVFLAGS = -L. --coverage
CHECK_FLAGS = -lcheck -lm -lpthread

all: install tests

install: 
	rm -rf build
	mkdir build
	cd build/ && qmake ../3DWieve && make
	open build/3DWieve.app

open:
	open build/3DWieve.app

uninstall: clean
	rm -rf build

dvi:
	open 'https://github.com/Selloni/3D_Viwer_plus#readme'

dist:
	rm -rf Archive_3DViewer
	mkdir Archive_3DViewer
	tar -cf Archive_3DViewer/3DViewer.tar build

tests:
	parsing/s21_viewer.c parsing/s21_test.c -lcheck -o test.out
	./test.out

check:
	clang-format -style=Google -dump-config > .clang-format
	clang-format -i parsing/*.cc				\
					parsing/*.h 				\
					3DWieve/*.cpp 				\
					3DWieve/*.h 				\
					GIFCreation/gifImage/*.cpp  \
					GIFCreation/gifImage/*.h 	\
					GIFCreation/gifLib/*.c 		\
					GIFCreation/gifLib/*.h		\
					Controller/*.h 				\
					Facade/*.h 					\
					Facade/*.cc
	clang-format -n parsing/*.cc 				\
					parsing/*.h 				\
					3DWieve/*.cpp 				\
					3DWieve/*.h 				\
					GIFCreation/gifImage/*.cpp  \
					GIFCreation/gifImage/*.h 	\
					GIFCreation/gifLib/*.c 		\
					GIFCreation/gifLib/*.h 		\
					Controller/*.h 				\
					Facade/*.h 					\
					Facade/*.cc
	rm .clang-format

clean:
	rm -rf *.o *.a
	rm -rf *.gcda *.gcno *.info
	rm -rf s21_test report
	rm -rf a.out
	rm -rf test.out
	rm -rf Archive_3DViewer

rebuild: clean uninstall all

reinstall: clean uninstall install

#Ты молодец, и еще ты мне нравишься)

