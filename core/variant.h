#ifndef VARIANT_H
#define VARIANT_H

/*************************************************************************/
/*  Variant.h                                                          */
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

#include <gdn/variant.h>

#include "defs.h"

#include "aabb.h"
#include "basis.h"
#include "color.h"
#include "node_path.h"
#include "plane.h"
#include "pool_arrays.h"
#include "projection.h"
#include "quaternion.h"
#include "rect2.h"
#include "rect2i.h"
#include "rid.h"
#include "transform.h"
#include "transform_2d.h"
#include "ustring.h"
#include "vector2.h"
#include "vector2i.h"
#include "vector3.h"
#include "vector3i.h"
#include "vector4.h"
#include "vector4i.h"

class Dictionary;

class Array;

class Variant {
	pandemonium_variant _pandemonium_variant;

	friend class Array;
	inline explicit Variant(pandemonium_variant v) {
		_pandemonium_variant = v;
	}

public:
	enum Type {

		NIL,

		// atomic types
		BOOL,
		INT,
		REAL,
		STRING,

		// math types
		RECT2, // 5
		RECT2I,
		VECTOR2,
		VECTOR2I,
		VECTOR3,
		VECTOR3I, // 10
		VECTOR4,
		VECTOR4I,

		PLANE,
		QUATERNION,
		AABB, // 15
		BASIS,
		TRANSFORM,
		TRANSFORM2D,
		PROJECTION,

		// misc types
		COLOR, // 20
		NODE_PATH,
		RID,
		OBJECT,
		STRING_NAME,
		DICTIONARY, // 25
		ARRAY,

		// arrays
		POOL_BYTE_ARRAY,
		POOL_INT_ARRAY,
		POOL_REAL_ARRAY,
		POOL_STRING_ARRAY, // 30
		POOL_VECTOR2_ARRAY,
		POOL_VECTOR2I_ARRAY,
		POOL_VECTOR3_ARRAY,
		POOL_VECTOR3I_ARRAY,
		POOL_VECTOR4_ARRAY, // 35
		POOL_VECTOR4I_ARRAY,
		POOL_COLOR_ARRAY,

		VARIANT_MAX // 38
	};

	enum Operator {

		// comparation
		OP_EQUAL,
		OP_NOT_EQUAL,
		OP_LESS,
		OP_LESS_EQUAL,
		OP_GREATER,
		OP_GREATER_EQUAL,

		// mathematic
		OP_ADD,
		OP_SUBSTRACT,
		OP_MULTIPLY,
		OP_DIVIDE,
		OP_NEGATE,
		OP_POSITIVE,
		OP_MODULE,
		OP_STRING_CONCAT,

		// bitwise
		OP_SHIFT_LEFT,
		OP_SHIFT_RIGHT,
		OP_BIT_AND,
		OP_BIT_OR,
		OP_BIT_XOR,
		OP_BIT_NEGATE,

		// logic
		OP_AND,
		OP_OR,
		OP_XOR,
		OP_NOT,

		// containment
		OP_IN,
		OP_MAX

	};

	Variant();

	Variant(const Variant &v);

	Variant(bool p_bool);

	Variant(signed int p_int);

	Variant(unsigned int p_int);

	Variant(signed short p_short);

	inline Variant(unsigned short p_short) :
			Variant((unsigned int)p_short) {}

	inline Variant(signed char p_char) :
			Variant((signed int)p_char) {}

	inline Variant(unsigned char p_char) :
			Variant((unsigned int)p_char) {}
	Variant(int64_t p_char);

	Variant(uint64_t p_char);

	Variant(float p_float);

	Variant(double p_double);

	Variant(const String &p_string);
	Variant(const StringName &p_string);

	Variant(const char *const p_cstring);

	Variant(const wchar_t *p_wstring);

	Variant(const Vector2 &p_vector2);
	Variant(const Vector2i &p_vector2i);

	Variant(const Rect2 &p_rect2);
	Variant(const Rect2i &p_rect2i);

	Variant(const Vector3 &p_vector3);
	Variant(const Vector3i &p_vector3i);

	Variant(const Vector4 &p_vector4);
	Variant(const Vector4i &p_vector4i);

	Variant(const Plane &p_plane);

	Variant(const ::AABB &p_aabb);

	Variant(const Quaternion &p_quaternion);

	Variant(const Basis &p_transform);

	Variant(const Transform2D &p_transform);

	Variant(const Transform &p_transform);

	Variant(const Projection &p_projection);

	Variant(const Color &p_color);

	Variant(const NodePath &p_path);

	Variant(const ::RID &p_rid);

	Variant(const Object *p_object);

	Variant(const Dictionary &p_dictionary);

	Variant(const Array &p_array);

	Variant(const PoolByteArray &p_raw_array);

	Variant(const PoolIntArray &p_int_array);

	Variant(const PoolRealArray &p_real_array);

	Variant(const PoolStringArray &p_string_array);

	Variant(const PoolVector2Array &p_vector2_array);

	Variant(const PoolVector3Array &p_vector3_array);

	Variant(const PoolColorArray &p_color_array);

	Variant &operator=(const Variant &v);

	operator bool() const;
	operator signed int() const;
	operator unsigned int() const;
	operator signed short() const;
	operator unsigned short() const;
	operator signed char() const;
	operator unsigned char() const;
	operator int64_t() const;
	operator uint64_t() const;

	operator wchar_t() const;

	operator float() const;

	operator double() const;
	operator String() const;
	operator StringName() const;
	operator Vector2() const;
	operator Vector2i() const;
	operator Rect2() const;
	operator Rect2i() const;
	operator Vector3() const;
	operator Vector3i() const;
	operator Vector4() const;
	operator Vector4i() const;
	operator Plane() const;
	operator ::AABB() const;
	operator Quaternion() const;
	operator Basis() const;
	operator Transform() const;
	operator Transform2D() const;
	operator Projection() const;

	operator Color() const;

	operator NodePath() const;
	operator ::RID() const;
	operator pandemonium_object *() const;

	template <typename T>
	operator T *() const { return static_cast<T *>(T::___get_from_variant(*this)); }

	operator Dictionary() const;
	operator Array() const;

	operator PoolByteArray() const;
	operator PoolIntArray() const;
	operator PoolRealArray() const;
	operator PoolStringArray() const;
	operator PoolVector2Array() const;
	operator PoolVector3Array() const;
	operator PoolColorArray() const;

	Type get_type() const;

	Variant call(const String &method, const Variant **args, const int arg_count);

	bool has_method(const String &method);

	bool operator==(const Variant &b) const;

	bool operator!=(const Variant &b) const;

	bool operator<(const Variant &b) const;

	bool operator<=(const Variant &b) const;

	bool operator>(const Variant &b) const;

	bool operator>=(const Variant &b) const;

	bool hash_compare(const Variant &b) const;

	bool booleanize() const;

	~Variant();
};

#endif // VARIANT_H
