CXX = g++
FLAGS = -Werror -Wpedantic -Wall
RUN = Lab2
TEST_RUN = test

SRC = $(wildcard src/*.cpp)
TEST_SRC = $(wildcard tests/*.cpp)

SRC_WITHOUT_MAIN = $(filter-out src/main.cpp, $(SRC))

OBJDIR = src/obj
TEST_OBJDIR = tests/obj

OBJS = $(SRC:src/%.cpp=$(OBJDIR)/%.o)
TEST_OBJS = $(TEST_SRC:tests/%.cpp=$(TEST_OBJDIR)/%.o)
TEST_DEPS_OBJS = $(SRC_WITHOUT_MAIN:src/%.cpp=$(OBJDIR)/%.o)

all: $(RUN)

$(RUN): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(TEST_RUN): $(OBJS) $(TEST_OBJS)
	$(CXX) $(TEST_DEPS_OBJS) $(TEST_OBJS) -o $@ -lgtest -lgtest_main -pthread

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	$(CXX) -c $< $(FLAGS) -o $@

$(TEST_OBJDIR)/%.o: tests/%.cpp | $(TEST_OBJDIR)
	$(CXX) -c $< $(FLAGS) -I../src -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TEST_OBJDIR):
	mkdir -p $(TEST_OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TEST_OBJDIR) $(RUN) $(TEST_RUN)

cleanall: clean

.PHONY: all clean cleanall test
