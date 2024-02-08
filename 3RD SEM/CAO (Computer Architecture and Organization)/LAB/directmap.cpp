#include <iostream>

// Cache size and block size (in bytes)
#define CACHE_SIZE 256
#define BLOCK_SIZE 16

// Number of cache lines
#define NUM_LINES (CACHE_SIZE / BLOCK_SIZE)

// Main memory size (in bytes)
#define MEMORY_SIZE 1024

// Function to calculate the cache index for a given memory address
int getCacheIndex(int memoryAddress) {
    return memoryAddress / BLOCK_SIZE % NUM_LINES;
}

int main() {
    // Simulate main memory as an array
    int mainMemory[MEMORY_SIZE];

    // Simulate cache as a 2D array
    int cache[NUM_LINES][BLOCK_SIZE];

    // Initialize main memory with some data
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        mainMemory[i] = i;
    }

    // Access memory addresses and update the cache
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        // Calculate the cache index for the current memory address
        int cacheIndex = getCacheIndex(i);

        // Check if the block is not present in the cache (a cache miss)
        if (cache[cacheIndex][0] != mainMemory[i - i % BLOCK_SIZE]) {
            // Update the cache with the block from main memory
            for (int j = 0; j < BLOCK_SIZE; ++j) {
                cache[cacheIndex][j] = mainMemory[i - i % BLOCK_SIZE + j];
            }
            std::cout << "Cache miss at memory address " << i << std::endl;
        }

        // Access the data from the cache
        int data = cache[cacheIndex][i % BLOCK_SIZE];
        std::cout << "Data at memory address " << i << ": " << data << std::endl;
    }

    return 0;
}
