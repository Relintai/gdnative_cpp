#ifndef PACKED_TYPED_ARRAY_H
#define PACKED_TYPED_ARRAY_H

#include <gdn/packed_typed_array.h>

/*************************************************************************/
/*  typed_array.h                                                            */
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

class String;
class StringName;

class Variant;
class PoolByteArray;
class PoolIntArray;
class PoolRealArray;
class PoolStringArray;
class PoolVector2Array;
class PoolVector2iArray;
class PoolVector3Array;
class PoolVector3iArray;
class PoolVector4Array;
class PoolVector4iArray;
class PoolColorArray;

class Object;

class PackedTypedArray {
	pandemonium_packed_typed_array _pandemonium_packed_typed_array;

	friend class Variant;
	friend class Dictionary;
	friend class String;
	inline explicit PackedTypedArray(const pandemonium_packed_typed_array &other) {
		_pandemonium_packed_typed_array = other;
	}

public:
	enum IntType {
		INT_TYPE_SIGNED_8,
		INT_TYPE_UNSIGNED_8,
		INT_TYPE_SIGNED_16,
		INT_TYPE_UNSIGNED_16,
		INT_TYPE_SIGNED_32,
		INT_TYPE_UNSIGNED_32,
		INT_TYPE_SIGNED_64,
		INT_TYPE_UNSIGNED_64,
	};

	const Variant operator[](const int idx) const;
	
	//todo fix gdnative bind
	//bool set(int p_idx, const Variant &p_value);
	void set(int p_idx, const Variant &p_value);
	const Variant get(int p_idx) const;

	int size() const;
	bool empty() const;
	void clear();
	
	bool deep_equal(const PackedTypedArray& p_array, const int p_recursion_count = 0) const;
	bool deep_equal_approx(const PackedTypedArray& p_array, const int p_recursion_count = 0) const;
	bool operator==(const PackedTypedArray &p_array);
	
	uint32_t hash() const;
	PackedTypedArray &operator=(const PackedTypedArray &other);
	
	void push_back(const Variant &v);
	void append(const Variant &v);
	void append_array(const PackedTypedArray& p_array);
	void append_from(const Variant& p_array);
	void resize(const int size);

	void insert(const int pos, const Variant &value);
	void remove(const int idx);
	void fill(const Variant &p_value);

	Variant front() const;
	Variant back() const;

	void sort();
	void sort_custom(Object *obj, const String &func);
	void shuffle();

	int bsearch(const Variant &value, const bool before = true);
	int bsearch_custom(const Variant &value, const Object *obj, const String &func, const bool before = true);

	void invert();

	int find(const Variant &what, const int from = 0) const;
	int rfind(const Variant &what, const int from = -1) const;
	int find_last(const Variant &what) const;
	int count(const Variant &v);
	bool has(const Variant &what) const;

	void erase(const Variant &v);

	void push_front(const Variant &v);
	Variant pop_back();
	Variant pop_front();
	Variant pop_at(int p_pos);

	PackedTypedArray duplicate(const bool deep = false) const;

	PackedTypedArray slice(int p_begin, int p_end, int p_step = 1, bool p_deep = false) const;

	Variant min() const;
	Variant max() const;
	
	// Not exposed in gdnative
	//bool operator<(const PackedTypedArray &p_array) const;
	//bool operator<=(const PackedTypedArray &p_array) const;
	//bool operator>(const PackedTypedArray &p_array) const;
	//bool operator>=(const PackedTypedArray &p_array) const;

	String get_typename_string() const;
	
	int get_variant_type() const;
	void set_variant_type(const int p_variant_type);
	
	IntType get_int_type() const;
	void set_int_type(const IntType p_int_type);
	
	StringName get_object_class_name() const;
	void set_object_class_name(const StringName &p_object_type_name);
	
	void set_type_from_name(const StringName &p_type_name);
	void set_type_from_variant(const Variant &p_variant);
	void set_type_from_array_element(const Variant &p_array);
	void set_type_from(const PackedTypedArray &p_array);
	
	bool validate_type_name(const StringName &p_type_name) const;
	bool validate_object_type_name(const StringName &p_type_name) const;
	bool can_take_variant(const Variant &p_value) const;

	bool is_shared() const;

	PackedTypedArray();
	PackedTypedArray(const PackedTypedArray &other);
	PackedTypedArray(const StringName &p_type_name, const Variant &p_from);
	PackedTypedArray(const StringName &p_type_name, const Variant &p_from, const IntType p_int_type);

	PackedTypedArray(const PoolByteArray &a);
	PackedTypedArray(const PoolIntArray &a);
	PackedTypedArray(const PoolRealArray &a);
	PackedTypedArray(const PoolStringArray &a);
	PackedTypedArray(const PoolVector2Array &a);
	PackedTypedArray(const PoolVector2iArray &a);
	PackedTypedArray(const PoolVector3Array &a);
	PackedTypedArray(const PoolVector3iArray &a);
	PackedTypedArray(const PoolVector4Array &a);
	PackedTypedArray(const PoolVector4iArray &a);
	PackedTypedArray(const PoolColorArray &a);

	~PackedTypedArray();
};

#endif // ARRAY_H
