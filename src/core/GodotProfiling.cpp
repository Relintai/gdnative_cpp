
#include "GodotProfiling.hpp"

#include "OS.hpp"

#include <cstdio>

namespace godot {

FunctionProfiling::FunctionProfiling(const char *p_function, const int p_line) {
	snprintf(signature, 1024, "::%d::%s", p_line, p_function);
	ticks = OS::get_singleton()->get_ticks_usec();
}

FunctionProfiling::~FunctionProfiling() {
	uint64_t t = OS::get_singleton()->get_ticks_usec() - ticks;
	if (t > 0) {
		Godot::gdnative_profiling_add_data(signature, t);
	}
}

} // namespace godot