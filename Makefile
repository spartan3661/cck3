CXX =  g++-14.2.0 -std=c++20 -fmodules-ts
CXXFLAGS = -Wall -g
HEADERFLAGS = -c -x c++-system-header
SOURCES = Objects/Currency/Currency.cc \
		Objects/Currency/Currency-impl.cc \
		Objects/Position/Position.cc \
		Objects/Position/Position-impl.cc \
		main.cc
# list of all .cc files in the current directory

HEADERS = iostream vector compare string
EXEC = submission

$(EXEC): $(SOURCES)
	$(CXX) $(HEADERFLAGS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEC)
	rm -rf gcm.cache

.PHONY: clean 
clean:
	rm -r ./gcm.cache
	rm -f $(EXEC)