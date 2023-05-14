G = g++ -std=c++17
GCC = $(G) -Wall -Wextra -Werror -Wuninitialized
TEST_LIBS = -lgtest -lgmock -pthread
FLAG_LEAKS = -lgtest -lstdc++ -lpthread -std=c++17 -g -lcheck


ifeq (${OS}, Linux)
	CHECK_FLAGS += -lsubunit -lrt
endif

b:
	$(G) parsing/s21_viewer.cc parsing/main.cc Facade/s21_facade.cc -g && ./a.out

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
	open 'https://github.com/Selloni/3D_Viever_C#readme'

dist:
	rm -rf Archive_3DViewer
	mkdir Archive_3DViewer
	tar -cf Archive_3DViewer/3DViewer.tar build

test:
	$(GCC) $(TEST_LIBS) parsing/s21_viewer.cc parsing/s21_test.cc Facade/s21_facade.cc -o test.out
# ./test.out --gtest_repeat=3 --gtest_break_on_failure
	./test.out

gcov_report:
	rm -f *.g*
	$(CC+FLAGS) --coverage $(CHECK_FLAGS) parsing/s21_*.c -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html
	rm -rf ./*.gcno ./*.gcda ./gcov*

3DViewer.o:
	$(CC+FLAGS) -c *.c


check:
	clang-format -style=Google -dump-config > .clang-format
	clang-format -i parsing/*.c 				\
					parsing/*.h 				\
					3DWieve/*.cpp 			\
					3DWieve/*.h 			\
					GIFCreation/gifImage/*.cpp  \
					GIFCreation/gifImage/*.h 	\
					GIFCreation/gifLib/*.c 		\
					GIFCreation/gifLib/*.h
	clang-format -n parsing/*.c 				\
					parsing/*.h 				\
					3DWieve/*.cpp 			\
					3DWieve/*.h 			\
					GIFCreation/gifImage/*.cpp  \
					GIFCreation/gifImage/*.h 	\
					GIFCreation/gifLib/*.c 		\
					GIFCreation/gifLib/*.h
	rm .clang-format

clean:
	rm -rf *.o *.a
	rm -rf *.gcda *.gcno *.info
	rm -rf s21_test report
	rm -rf a.out
	rm -rf test.out
	rm -rf Archive_3DViewer


# install lcov:
# 	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
# 	brew install lcov

rebuild: clean uninstall all

reinstall: clean uninstall install

#Ты молодец, и еще ты мне нравишься)
