CC = $(CLANG_PREFIX)clang++
LAB_OPTS = -I./src src/entity.cpp src/list.cpp
C_OPTS = -std=gnu++14 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)
V_FLAGS=--tool=memcheck --leak-check=full --show-reachable=yes --undef-value-errors=yes --track-origins=no --child-silent-after-fork=no --trace-children=no --error-exitcode=1

clean:
	rm -rf dist

prep:
	mkdir dist

compile: main.bin 

main.bin: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: clean prep compile
	./dist/main.bin

doxygen:
	doxygen Doxyfile

check:
	clang-format --verbose --dry-run --Werror src/* test/*
	$(CLANG_PREFIX)clang-tidy src/*.cpp -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	cppcheck --enable=all --inconclusive --addon=cert --error-exitcode=1 -v --suppress=unreadVariable:*/main.cpp --suppress=knownConditionTrueFalse:*/main.cpp --suppress=missingIncludeSystem --check-config --suppress=*:*/test.cpp --suppress=unmatchedSuppression:*/main.cpp .
	rm -rf src/*.dump test/*.dump

leak-check: clean prep compile
	valgrind $(V_FLAGS) --log-file=dist/valgrind.log --xml-file=dist/valgrind.xml --xml=yes dist/main.bin
	valgrind $(V_FLAGS) --log-file=dist/valgrind.log --xml-file=dist/valgrind.xml --xml=yes dist/test.bin

all: clean prep compile