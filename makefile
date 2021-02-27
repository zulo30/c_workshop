### If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

LIBS =  -I/usr/local/Cellar/gmp/6.2.1/include -L/usr/local/Cellar/gmp/6.2.1/lib -lgmp

ALL_SRCS = $(wildcard src/*.c)
ALL_SRCS += $(wildcard src/vendor/*.c)
ALL_SRCS += $(wildcard src/utils/*.c)
ALL_SRCS += $(wildcard src/exercise_*/*.c)

MAINS = src/main.c
MAINS += $(wildcard src/exercise_*/main.c)

SRCS = $(filter-out $(MAINS), $(ALL_SRCS))


TEST_DIR = test
TEST_RNS = test/test_runners

BIN = test
###
CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer


all: build

.PHONY: build
build: build/main.out
	@./build/main.out
	
build/main.out: src/*.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/main.c $(SRC) -o build/main.out $(LIBS)

.PHONY: ex%
ex%: build/exercise_%.out
	@./build/exercise_$*.out

build/exercise_%.out: src/exercise_%/*.c
	@echo Compiling $@
	@$(CC) $(CFLAGS)  $^ -o $@ $(LIBS)

.PHONY: test
test: build/exercise_01.test.out build/exercise_02.test.out\
	build/exercise_03.test.out build/exercise_04.test.out\
	build/exercise_05.test.out build/exercise_06.test.out\
	build/exercise_07.test.out build/exercise_08.test.out\
	build/exercise_09.test.out build/exercise_10.test.out\
	build/exercise_11.test.out build/exercise_12.test.out
	@echo =======================
	@echo Running Test Suites
	@echo -----------------------
	@echo  01.	Excercise 1
	@echo -----------------------
	@./build/exercise_01.test.out
	@echo -----------------------
	@echo  02.	Excercise 2
	@echo -----------------------
	@./build/exercise_02.test.out
	@echo -----------------------
	@echo  03.	Excercise 3
	@echo -----------------------
	@./build/exercise_03.test.out
	@echo -----------------------
	@echo  04.	Excercise 4
	@echo -----------------------
	@./build/exercise_04.test.out
	@echo -----------------------
	@echo  05.	Excercise 5
	@echo -----------------------
	@./build/exercise_05.test.out
	@echo -----------------------
	@echo  06.	Excercise 6
	@echo -----------------------
	@./build/exercise_06.test.out
	@echo -----------------------
	@echo  07.	Excercise 7
	@echo -----------------------
	@./build/exercise_07.test.out
	@echo -----------------------
	@echo  08.	Excercise 8
	@echo -----------------------
	@./build/exercise_08.test.out
	@echo -----------------------
	@echo  10.	Excercise 10
	@echo -----------------------
	@./build/exercise_10.test.out
	@echo -----------------------
	@echo  11.	Excercise 11
	@echo -----------------------
	@./build/exercise_11.test.out
	@echo -----------------------
	@echo  12.	Excercise 12
	@echo -----------------------
	@./build/exercise_12.test.out
	@echo -----------------------


build/exercise_%.test.out: $(TEST_DIR)/exercises/test_exercise_%.c $(TEST_RNS)/test_ex_%_runner.c
	@$(CC) $(CFLAGS) $(SRCS) test/vendor/unity.c $^ -o $@ $(LIBS)


.PHONY: clean
clean:
	rm -rf build/*.o build/*.out build/*.out.dSYM
