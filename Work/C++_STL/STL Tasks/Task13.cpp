#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <chrono>
#include <type_traits>
#include <algorithm>

using WordVector = std::vector<std::string>;
using MilliSeconds = std::chrono::duration<double, std::milli>;

const int NUM_WORDS = 100000; 
const int NUM_LOOKUP_TESTS = 10000; 
const int NUM_NONEXISTENT_WORDS = 10000;

template<typename Func>
double measureTime(const std::string &description, Func func)
{
    auto start = std::chrono::high_resolution_clock::now(); 
    func(); 
    auto end = std::chrono::high_resolution_clock::now(); 

    MilliSeconds duration_ms = end - start;

    std::cout << std::fixed << std::setprecision(3);
    std::cout << " " << std::left << std::setw(35) 
              << (description + ":") 
              << duration_ms.count() << " ms\n";

    return duration_ms.count(); 
}

WordVector generateWords(int count, const std::string &prefix)
{
    WordVector words;
    words.reserve(count);

    for (int i = 0; i < count; i++) {
        words.push_back(prefix + std::to_string(i));
    }
    return words;
}

template <typename MapType> 
void conditionallyReserve(MapType& map, size_t count) 
{
    if constexpr (std::is_same_v<MapType, std::unordered_map<std::string, int>>) {
        map.reserve(count); 
        std::cout << " (Reserved " << count << " buckets for unordered_map)\n";
    }
}

template <typename MapType> 
void benchmarkContainer(const WordVector& words_to_insert,
                        const WordVector& non_existent_words)
{
    MapType my_container;

    conditionallyReserve(my_container, words_to_insert.size());

    measureTime("Insertion", [&]() {
        for (int i = 0; i < (int)words_to_insert.size(); ++i) {
            my_container[words_to_insert[i]] = i;
        }
    });

    volatile int found_count = 0; 
    measureTime("Lookup (Existing Keys)", [&]() {
        int limit = std::min((int)words_to_insert.size(), NUM_LOOKUP_TESTS);
        for (int i = 0; i < limit; ++i) {
            auto it = my_container.find(words_to_insert[i]); 
            if (it != my_container.end()) {
                found_count++;
            }
        }
    });

    volatile int not_found_count = 0;
    measureTime("Lookup (Non-Existing Keys)", [&]() {
        int limit = std::min((int)non_existent_words.size(), NUM_NONEXISTENT_WORDS);
        for (int i = 0; i < limit; ++i) {
            auto it = my_container.find(non_existent_words[i]); 
            if (it == my_container.end()) {
                not_found_count++;
            }
        }
    });

    std::cout << "Size of the container: " << my_container.size() << "\n"; 
}

int main()
{
    std::cout << "=== C++ Container Benchmarking ===\n";

    std::cout << "Generating " << NUM_WORDS << " unique words...\n"; 
    WordVector words_to_insert = generateWords(NUM_WORDS, "word_"); 

    std::cout << "Generating " << NUM_NONEXISTENT_WORDS 
              << " non-existent words for lookup tests...\n"; 

    WordVector non_existent_words = generateWords(NUM_NONEXISTENT_WORDS, "nonexistent_word_");

    std::cout << "Data generation complete.\n\n";

    std::cout << "--- Benchmarking std::map ---\n";
    benchmarkContainer<std::map<std::string, int>>(
        words_to_insert, non_existent_words);
    
    std::cout << "\n--- Benchmarking std::unordered_map ---\n";
    benchmarkContainer<std::unordered_map<std::string, int>>(
        words_to_insert, non_existent_words);
    
    std::cout << "\n=== Benchmarking Complete ===\n";

    return 0;
}