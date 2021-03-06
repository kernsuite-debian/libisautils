// Copyright 2015 Alessio Sclocco <a.sclocco@vu.nl>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <Timer.hpp>

namespace isa {
namespace utils {

Timer::Timer() : stats(Stats< double >()), starting(std::chrono::high_resolution_clock::time_point()), totalTime(0.0), time(0.0) {}

void Timer::start() {
	starting = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
	time = (std::chrono::duration_cast< std::chrono::duration< double > >(std::chrono::high_resolution_clock::now() - starting)).count();
	totalTime += time;
	stats.addElement(time);
}

void Timer::reset() {
	starting = std::chrono::high_resolution_clock::time_point();
	totalTime = 0.0;
	time = 0.0;
}

} // utils
} // isa
