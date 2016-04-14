CXXFLAGS := -Wall -Wextra -std=c++11 -ggdb3 -pipe
BIN := TestList
BUILD := g++ $(CXXFLAGS) -o $(BIN) TestList.cc

.PHONY: dev
dev:
	$(BUILD) -fdiagnostics-color=always 2>&1 | less
	ctags -f .tags -R .

TestList:
	$(BUILD)

.PHONY: clean
clean:
	rm -rf $(BIN)


