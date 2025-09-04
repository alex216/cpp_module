#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>

class PmergeMe {
private:
    static std::vector<size_t> genAlterJacobsthalSeq(size_t n);

    template<typename Container>
    static void sort(Container& arr, int& comparisions) {
        const size_t n = arr.size();
        if (n <= 1) return;
        
        std::vector<std::pair<int, int> > pairs;
        int straggler;
        bool is_exist_stragger = false;
        
        // Step 1: Create pairs
        for (size_t i = 0; i < n - 1; i += 2) {
            int first = arr[i];
            int second = arr[i + 1];
            comparisions++;
            if (first > second) {
                pairs.push_back(std::make_pair(first, second));
            } else {
                pairs.push_back(std::make_pair(second, first));
            }
        }
        if (n % 2 == 1) {
            straggler = arr[n - 1];
            is_exist_stragger = true;
        }
        
        // Step 2: Sort the main_chain
        Container main_chain;
        for (size_t i = 0; i < pairs.size(); ++i) {
            main_chain.push_back(pairs[i].first);
        }
        sort(main_chain, comparisions);
        
        // Step 3: Create the sub_chain
        std::vector<int> sub_chain;
        for (size_t i = 0; i < main_chain.size(); ++i) {
            for (size_t j = 0; j < pairs.size(); ++j) {
                if (pairs[j].first == main_chain[i]) {
                    sub_chain.push_back(pairs[j].second);
                    break;
                }
            }
        }
        if (is_exist_stragger)
            sub_chain.push_back(straggler);
        
        // Step 4: Insert first element of sub_chain at the beginning
        if (!sub_chain.empty()) {
            main_chain.insert(main_chain.begin(), sub_chain[0]);
        }
        
        // Step 5: Generate Jacobsthal sequence
        std::vector<size_t> altered_jacobsthal = genAlterJacobsthalSeq(sub_chain.size());

        // Step 6: Insert sub_chain elements using Jacobsthal sequence
        // altered_jacobsthal: 0, 1, 1, 3,     5,     11,...
        // <start, end> =              <2,0>, <4,2>, <10, 4>...
        for (size_t i = 3;  altered_jacobsthal[i - 1] - 1 < sub_chain.size(); ++i) {
            if (i >= altered_jacobsthal.size())
                break;
            const size_t start_index = altered_jacobsthal[i] - 1;
            const size_t end_index = altered_jacobsthal[i - 1] - 1;

            for (size_t j = start_index; j > end_index; --j) {
                if (j >= sub_chain.size())
                    continue;
                const int pos = binarySearch(main_chain, sub_chain[j], (1<<(i-1))-1, comparisions);
                main_chain.insert(main_chain.begin() + pos, sub_chain[j]);
            }
        }
        
        arr = main_chain;
    }

    template<typename Container>
    static int binarySearch(const Container& arr, int target, int end, int& comparisions) {
        int left = 0;
        int right = end;
        
        while (left < right) {
            const int mid = (left + right) / 2;
            comparisions++;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

public:
    template<typename Container>
    static int sortContainer(Container& arr) {
        int comparisons = 0;
        sort(arr, comparisons);
        return comparisons;
    }
    
    static bool parseArguments(int argc, char** argv, std::vector<int>& numbers);
    static void printSequence(const std::vector<int>& arr, const std::string& label);
};

#endif
