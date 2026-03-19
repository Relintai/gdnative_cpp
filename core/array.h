#ifndef ARRAY_H
#define ARRAY_H

#include <gdn/array.h>

/*************************************************************************/
/*  array.h                                                            */
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

namespace helpers {
template <typename T, typename ValueT>
T append_all(T appendable, ValueT value) {
	appendable.append(value);
	return appendable;
}

template <typename T, typename ValueT, typename... Args>
T append_all(T appendable, ValueT value, Args... args) {
	appendable.append(value);
	return append_all(appendable, args...);
}

template <typename T>
T append_all(T appendable) {
	return appendable;
}

template <typename KV, typename KeyT, typename ValueT>
KV add_all(KV kv, KeyT key, ValueT value) {
	kv[key] = value;
	return kv;
}

template <typename KV, typename KeyT, typename ValueT, typename... Args>
KV add_all(KV kv, KeyT key, ValueT value, Args... args) {
	kv[key] = value;
	return add_all(kv, args...);
}

template <typename KV>
KV add_all(KV kv) {
	return kv;
}
} // namespace helpers

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

class Array {
	pandemonium_array _pandemonium_array;

	friend class Variant;
	friend class Dictionary;
	friend class String;
	inline explicit Array(const pandemonium_array &other) {
		_pandemonium_array = other;
	}

public:
	Variant &operator[](const int idx);
	const Variant &operator[](const int idx) const;
	
	void set(int p_idx, const Variant &p_value);
	const Variant &get(int p_idx) const;

	int size() const;
	bool empty() const;
	void clear();
	
	bool deep_equal(const Array& p_array, const int p_recursion_count = 0) const;
	bool deep_equal_approx(const Array& p_array, const int p_recursion_count = 0) const;
	bool operator==(const Array &p_array);
	
	uint32_t hash() const;
	Array &operator=(const Array &other);
	
	void push_back(const Variant &v);
	void append(const Variant &v);
	void append_array(const Array& p_array);
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

	Array duplicate(const bool deep = false) const;

	Array slice(int p_begin, int p_end, int p_step = 1, bool p_deep = false) const;

	Variant min() const;
	Variant max() const;
	
	// Not exposed in gdnative
	//bool operator<(const Array &p_array) const;
	//bool operator<=(const Array &p_array) const;
	//bool operator>(const Array &p_array) const;
	//bool operator>=(const Array &p_array) const;

	bool is_shared() const;

	template <class... Args>
	static Array make(Args... args) {
		return helpers::append_all(Array(), args...);
	}

	Array();
	Array(const Array &other);

	Array(const PoolByteArray &a);
	Array(const PoolIntArray &a);
	Array(const PoolRealArray &a);
	Array(const PoolStringArray &a);
	Array(const PoolVector2Array &a);
	Array(const PoolVector2iArray &a);
	Array(const PoolVector3Array &a);
	Array(const PoolVector3iArray &a);
	Array(const PoolVector4Array &a);
	Array(const PoolVector4iArray &a);
	Array(const PoolColorArray &a);

	~Array();
};

#endif // ARRAY_H
