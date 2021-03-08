CXX = g++
CXXFLAGS = -c

all: testLoader

testLoader: test.o PageLoader.o LoadResult.o CurlException.o
	$(CXX) test.o PageLoader.o LoadResult.o CurlException.o -lcurl -o testLoader

test.o: test.cpp PageLoader.h
	$(CXX) $(CXXFLAGS) test.cpp -o test.o

PageLoader.o: PageLoader.cpp LoadResult.h CurlException.h
	$(CXX) $(CXXFLAGS) PageLoader.cpp -o PageLoader.o

LoadResult.o: LoadResult.cpp
	$(CXX) $(CXXFLAGS) LoadResult.cpp -o LoadResult.o

CurlException.o: CurlException.cpp
	$(CXX) $(CXXFLAGS) CurlException.cpp -o CurlException.o

clean:
	rm *.o testLoader
