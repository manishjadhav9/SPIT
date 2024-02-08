#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
list<int> lruList;
unordered_map<int, list<int>::iterator> pageMap;
int capacity;

public:
LRUCache(int capacity) {
this->capacity = capacity;
}

void referPage(int page) {
if (pageMap.find(page) == pageMap.end()) {
if (lruList.size() == capacity) {
int last = lruList.back();
lruList.pop_back();
pageMap.erase(last);
}
} else {
lruList.erase(pageMap[page]);
}

lruList.push_front(page);
pageMap[page] = lruList.begin();
}

void displayPages() {
for (auto it = lruList.begin(); it != lruList.end(); ++it)
cout << *it << " ";
cout << endl;
}
};

int main() {
LRUCache cache(3);

cache.referPage(28);
cache.referPage(9);
cache.referPage(13);
cache.displayPages();

cache.referPage(2);
cache.displayPages();

cache.referPage(19);
cache.displayPages();

cache.referPage(10);
cache.displayPages();

return 0;
}