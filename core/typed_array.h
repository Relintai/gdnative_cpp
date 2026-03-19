#ifndef TYPED_ARRAY_H
#define TYPED_ARRAY_H

#include <gdn/typed_array.h>

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

class TypedArray {
	pandemonium_typed_array _pandemonium_typed_array;

	friend class Variant;
	friend class Dictionary;
	friend class String;
	inline explicit TypedArray(const pandemonium_typed_array &other) {
		_pandemonium_typed_array = other;
	}

public:
	const Variant &operator[](const int idx) const;
	
	bool set(int p_idx, const Variant &p_value);
	const Variant get(int p_idx) const;

	int size() const;
	bool empty() const;
	void clear();
	
	bool deep_equal(const TypedArray& p_array, const int p_recursion_count = 0) const;
	bool deep_equal_approx(const TypedArray& p_array, const int p_recursion_count = 0) const;
	bool operator==(const TypedArray &p_array);
	
	uint32_t hash() const;
	TypedArray &operator=(const TypedArray &other);
	
	void push_back(const Variant &v);
	void append(const Variant &v);
	void append_array(const TypedArray& p_array);
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

	TypedArray duplicate(const bool deep = false) const;

	TypedArray slice(int p_begin, int p_end, int p_step = 1, bool p_deep = false) const;

	Variant min() const;
	Variant max() const;
	
	// Not exposed in gdnative
	//bool operator<(const TypedArray &p_array) const;
	//bool operator<=(const TypedArray &p_array) const;
	//bool operator>(const TypedArray &p_array) const;
	//bool operator>=(const TypedArray &p_array) const;

	String get_typename_string() const;
	
	int get_variant_type() const;
	void set_variant_type(const int p_variant_type);
	
	StringName get_object_class_name() const;
	void set_object_class_name(const StringName &p_object_type_name);
	
	void set_type_from_name(const StringName &p_type_name);
	void set_type_from_variant(const Variant &p_variant);
	void set_type_from_array_element(const Variant &p_array);
	void set_type_from(const TypedArray &p_array);
	
	bool validate_type_name(const StringName &p_type_name) const;
	bool validate_object_type_name(const StringName &p_type_name) const;
	bool can_take_variant(const Variant &p_value) const;

	bool is_shared() const;

	TypedArray();
	TypedArray(const TypedArray &other);
	TypedArray(const StringName &p_type_name, const Variant &p_from);

	TypedArray(const PoolByteArray &a);
	TypedArray(const PoolIntArray &a);
	TypedArray(const PoolRealArray &a);
	TypedArray(const PoolStringArray &a);
	TypedArray(const PoolVector2Array &a);
	TypedArray(const PoolVector2iArray &a);
	TypedArray(const PoolVector3Array &a);
	TypedArray(const PoolVector3iArray &a);
	TypedArray(const PoolVector4Array &a);
	TypedArray(const PoolVector4iArray &a);
	TypedArray(const PoolColorArray &a);

	~TypedArray();
};

#endif // ARRAY_H
