/*************************************************************************/
/*  Math.h                                                             */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           PANDEMONIUM ENGINE                                */
/*                      https://pandemoniumengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Pandemonium Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef PANDEMONIUM_MATH_H
#define PANDEMONIUM_MATH_H

#include "defs.h"

#include <float.h>
#include <math.h>
#include <cmath>

class Math {
public:
	// Functions reproduced as in Pandemonium's source code `math_funcs.h`.
	// Some are overloads to automatically support changing real_t into either double or float in the way Pandemonium does.

	static _ALWAYS_INLINE_ double fmod(double p_x, double p_y) {
		return ::fmod(p_x, p_y);
	}
	static _ALWAYS_INLINE_ float fmod(float p_x, float p_y) {
		return ::fmodf(p_x, p_y);
	}

	static _ALWAYS_INLINE_ double floor(double p_x) {
		return ::floor(p_x);
	}
	static _ALWAYS_INLINE_ float floor(float p_x) {
		return ::floorf(p_x);
	}

	static _ALWAYS_INLINE_ double exp(double p_x) {
		return ::exp(p_x);
	}
	static _ALWAYS_INLINE_ float exp(float p_x) {
		return ::expf(p_x);
	}

	static _ALWAYS_INLINE_ double sin(double p_x) {
		return ::sin(p_x);
	}
	static _ALWAYS_INLINE_ float sin(float p_x) {
		return ::sinf(p_x);
	}

	static _ALWAYS_INLINE_ double cos(double p_x) {
		return ::cos(p_x);
	}
	static _ALWAYS_INLINE_ float cos(float p_x) {
		return ::cosf(p_x);
	}

	static _ALWAYS_INLINE_ double tan(double p_x) {
		return ::tan(p_x);
	}
	static _ALWAYS_INLINE_ float tan(float p_x) {
		return ::tanf(p_x);
	}

	static _ALWAYS_INLINE_ double asin(double p_x) {
		return ::asin(p_x);
	}
	static _ALWAYS_INLINE_ float asin(float p_x) {
		return ::asinf(p_x);
	}

	static _ALWAYS_INLINE_ double acos(double p_x) {
		return ::acos(p_x);
	}
	static _ALWAYS_INLINE_ float acos(float p_x) {
		return ::acosf(p_x);
	}

	static _ALWAYS_INLINE_ double atan(double p_x) {
		return ::atan(p_x);
	}
	static _ALWAYS_INLINE_ float atan(float p_x) {
		return ::atanf(p_x);
	}

	static _ALWAYS_INLINE_ double atan2(double p_y, double p_x) {
		return ::atan2(p_y, p_x);
	}
	static _ALWAYS_INLINE_ float atan2(float p_y, float p_x) {
		return ::atan2f(p_y, p_x);
	}

	static _ALWAYS_INLINE_ double sqrt(double p_x) {
		return ::sqrt(p_x);
	}
	static _ALWAYS_INLINE_ float sqrt(float p_x) {
		return ::sqrtf(p_x);
	}

	static _ALWAYS_INLINE_ float lerp(float minv, float maxv, float t) {
		return minv + t * (maxv - minv);
	}
	static _ALWAYS_INLINE_ double lerp(double minv, double maxv, double t) {
		return minv + t * (maxv - minv);
	}

	static _ALWAYS_INLINE_ double lerp_angle(double p_from, double p_to, double p_weight) {
		double difference = fmod(p_to - p_from, Math_TAU);
		double distance = fmod(2.0 * difference, Math_TAU) - difference;
		return p_from + distance * p_weight;
	}
	static _ALWAYS_INLINE_ float lerp_angle(float p_from, float p_to, float p_weight) {
		float difference = fmod(p_to - p_from, (float)Math_TAU);
		float distance = fmod(2.0f * difference, (float)Math_TAU) - difference;
		return p_from + distance * p_weight;
	}

	template <typename T>
	static _ALWAYS_INLINE_ T clamp(T x, T minv, T maxv) {
		if (x < minv) {
			return minv;
		}
		if (x > maxv) {
			return maxv;
		}
		return x;
	}

	template <typename T>
	static _ALWAYS_INLINE_ T min(T a, T b) {
		return a < b ? a : b;
	}

	template <typename T>
	static _ALWAYS_INLINE_ T max(T a, T b) {
		return a > b ? a : b;
	}

	template <typename T>
	static _ALWAYS_INLINE_ T sign(T x) {
		return static_cast<T>(x < 0 ? -1 : 1);
	}

	static _ALWAYS_INLINE_ double deg2rad(double p_y) {
		return p_y * Math_PI / 180.0;
	}
	static _ALWAYS_INLINE_ float deg2rad(float p_y) {
		return p_y * static_cast<float>(Math_PI) / 180.f;
	}

	static _ALWAYS_INLINE_ double rad2deg(double p_y) {
		return p_y * 180.0 / Math_PI;
	}
	static _ALWAYS_INLINE_ float rad2deg(float p_y) {
		return p_y * 180.f / static_cast<float>(Math_PI);
	}

	static _ALWAYS_INLINE_ double inverse_lerp(double p_from, double p_to, double p_value) {
		return (p_value - p_from) / (p_to - p_from);
	}
	static _ALWAYS_INLINE_ float inverse_lerp(float p_from, float p_to, float p_value) {
		return (p_value - p_from) / (p_to - p_from);
	}

	static _ALWAYS_INLINE_ double range_lerp(double p_value, double p_istart, double p_istop, double p_ostart, double p_ostop) {
		return Math::lerp(p_ostart, p_ostop, Math::inverse_lerp(p_istart, p_istop, p_value));
	}
	static _ALWAYS_INLINE_ float range_lerp(float p_value, float p_istart, float p_istop, float p_ostart, float p_ostop) {
		return Math::lerp(p_ostart, p_ostop, Math::inverse_lerp(p_istart, p_istop, p_value));
	}

	static _ALWAYS_INLINE_ bool is_equal_approx(real_t a, real_t b) {
		// Check for exact equality first, required to handle "infinity" values.
		if (a == b) {
			return true;
		}
		// Then check for approximate equality.
		real_t tolerance = CMP_EPSILON * ABS(a);
		if (tolerance < CMP_EPSILON) {
			tolerance = CMP_EPSILON;
		}
		return ABS(a - b) < tolerance;
	}

	static _ALWAYS_INLINE_ bool is_equal_approx(real_t a, real_t b, real_t tolerance) {
		// Check for exact equality first, required to handle "infinity" values.
		if (a == b) {
			return true;
		}
		// Then check for approximate equality.
		return ABS(a - b) < tolerance;
	}

	static _ALWAYS_INLINE_ bool is_zero_approx(real_t s) {
		return ABS(s) < CMP_EPSILON;
	}

	static _ALWAYS_INLINE_ double smoothstep(double p_from, double p_to, double p_weight) {
		if (is_equal_approx(static_cast<real_t>(p_from), static_cast<real_t>(p_to))) {
			return p_from;
		}
		double x = clamp((p_weight - p_from) / (p_to - p_from), 0.0, 1.0);
		return x * x * (3.0 - 2.0 * x);
	}
	static _ALWAYS_INLINE_ float smoothstep(float p_from, float p_to, float p_weight) {
		if (is_equal_approx(p_from, p_to)) {
			return p_from;
		}
		float x = clamp((p_weight - p_from) / (p_to - p_from), 0.0f, 1.0f);
		return x * x * (3.0f - 2.0f * x);
	}

	static _ALWAYS_INLINE_ double move_toward(double p_from, double p_to, double p_delta) {
		return ABS(p_to - p_from) <= p_delta ? p_to : p_from + sign(p_to - p_from) * p_delta;
	}

	static _ALWAYS_INLINE_ float move_toward(float p_from, float p_to, float p_delta) {
		return ABS(p_to - p_from) <= p_delta ? p_to : p_from + sign(p_to - p_from) * p_delta;
	}

	static _ALWAYS_INLINE_ double linear2db(double p_linear) {
		return log(p_linear) * 8.6858896380650365530225783783321;
	}
	static _ALWAYS_INLINE_ float linear2db(float p_linear) {
		return log(p_linear) * 8.6858896380650365530225783783321f;
	}

	static _ALWAYS_INLINE_ double db2linear(double p_db) {
		return exp(p_db * 0.11512925464970228420089957273422);
	}
	static _ALWAYS_INLINE_ float db2linear(float p_db) {
		return exp(p_db * 0.11512925464970228420089957273422f);
	}

	static _ALWAYS_INLINE_ double round(double p_val) {
		return (p_val >= 0) ? floor(p_val + 0.5) : -floor(-p_val + 0.5);
	}
	static _ALWAYS_INLINE_ float round(float p_val) {
		return (p_val >= 0) ? floor(p_val + 0.5f) : -floor(-p_val + 0.5f);
	}

	static _ALWAYS_INLINE_ int64_t wrapi(int64_t value, int64_t min, int64_t max) {
		int64_t range = max - min;
		return range == 0 ? min : min + ((((value - min) % range) + range) % range);
	}

	static _ALWAYS_INLINE_ float wrapf(real_t value, real_t min, real_t max) {
		const real_t range = max - min;
		return is_zero_approx(range) ? min : value - (range * floor((value - min) / range));
	}

	static _ALWAYS_INLINE_ float stepify(float p_value, float p_step) {
		if (p_step != 0) {
			p_value = floor(p_value / p_step + 0.5f) * p_step;
		}
		return p_value;
	}
	static _ALWAYS_INLINE_ double stepify(double p_value, double p_step) {
		if (p_step != 0) {
			p_value = floor(p_value / p_step + 0.5) * p_step;
		}
		return p_value;
	}

	static _ALWAYS_INLINE_ unsigned int next_power_of_2(unsigned int x) {
		if (x == 0)
			return 0;

		--x;
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;

		return ++x;
	}

	static _ALWAYS_INLINE_ bool is_nan(double p_val) {
#ifdef _MSC_VER
		return _isnan(p_val);
#elif defined(__GNUC__) && __GNUC__ < 6
		union {
			uint64_t u;
			double f;
		} ieee754;
		ieee754.f = p_val;
		// (unsigned)(0x7ff0000000000001 >> 32) : 0x7ff00000
		return ((((unsigned)(ieee754.u >> 32) & 0x7fffffff) + ((unsigned)ieee754.u != 0)) > 0x7ff00000);
#else
		return isnan(p_val);
#endif
	}

	static _ALWAYS_INLINE_ bool is_nan(float p_val) {
#ifdef _MSC_VER
		return _isnan(p_val);
#elif defined(__GNUC__) && __GNUC__ < 6
		union {
			uint32_t u;
			float f;
		} ieee754;
		ieee754.f = p_val;
		// -----------------------------------
		// (single-precision floating-point)
		// NaN : s111 1111 1xxx xxxx xxxx xxxx xxxx xxxx
		//     : (> 0x7f800000)
		// where,
		//   s : sign
		//   x : non-zero number
		// -----------------------------------
		return ((ieee754.u & 0x7fffffff) > 0x7f800000);
#else
		return isnan(p_val);
#endif
	}
};

#endif // PANDEMONIUM_MATH_H
