class LRUCache:
    
    def __init__(self, capacity: int):
        self.cache = {}
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        val = self.cache.pop(key)# day cai duoc get xuong cuoi
        self.cache[key] = val
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.pop(key)
        else:
            if len(self.cache) == self.capacity:
                del self.cache[next(iter(self.cache))]
        self.cache[key] = value


if __name__ == "__main__":
    newcache = LRUCache(2)
    newcache.put(1, 1)
    newcache.put(2, 2)
    newcache.get(1)
    newcache.put(3, 3)
    newcache.get(2)
    newcache.put(4, 4)
    newcache.get(1)
    newcache.get(3)
    newcache.get(4)