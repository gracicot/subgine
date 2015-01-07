#pragma once

#include <mutex>
#include <iostream>
#include <functional>
#include <algorithm>
#include <thread>

namespace sbg {

const int maxThreads = std::thread::hardware_concurrency();

template<typename IteratorType, typename F>
void parallel_for(IteratorType first, IteratorType last, F worker)
{
	const int count = std::min(static_cast<int>(std::distance(first, last)), maxThreads);
	
	if (count > 1) {
		std::vector<std::thread> workers;
		for (int i = 0 ; i < count ; i++) {
			auto launchFunction = [worker, count, i, &first, &last]() {
				auto it = first;
				std::advance(it, i);
				
				while (it != last) {
					worker(*it);
					if (std::distance(it, last) > count) {
						std::advance(it, count);
					} else {
						it = last;
					}
				}
			};
			if (i == count-1) {
				launchFunction();
			} else {
				workers.push_back(std::thread(launchFunction));
			}
		}
		for (auto& workerThread : workers) {
			if (workerThread.joinable()) {
				workerThread.join();
			}
		}
	} else {
		for (auto it = first ; it != last ; it++) {
			worker(*it);
		}
	}
}

}
