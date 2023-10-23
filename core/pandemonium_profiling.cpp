
#include "pandemonium_profiling.h"

#include "os.h"

#include <cstdio>

FunctionProfiling::FunctionProfiling(const char *p_function, const int p_line) {
	snprintf(signature, 1024, "::%d::%s", p_line, p_function);
	ticks = OS::get_singleton()->get_ticks_usec();
}

FunctionProfiling::~FunctionProfiling() {
	uint64_t t = OS::get_singleton()->get_ticks_usec() - ticks;
	if (t > 0) {
		Pandemonium::gdnative_profiling_add_data(signature, t);
	}
}
