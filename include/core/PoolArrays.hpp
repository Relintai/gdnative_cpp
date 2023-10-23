/*************************************************************************/
/*  PoolArrays.hpp                                                       */
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

#ifndef POOLARRAYS_H
#define POOLARRAYS_H

#include "Defs.hpp"

#include "Color.hpp"
#include "PandemoniumGlobal.hpp"
#include "String.hpp"
#include "Vector2.hpp"
#include "Vector2i.hpp"
#include "Vector3.hpp"

#include <gdn/pool_arrays.h>

namespace pandemonium {

class Array;

class PoolByteArray {
	pandemonium_pool_byte_array _pandemonium_array;

	friend class String;
	friend class Variant;
	inline explicit PoolByteArray(pandemonium_pool_byte_array a) {
		_pandemonium_array = a;
	}

public:
	class Read {
		friend class PoolByteArray;
		pandemonium_pool_byte_array_read_access *_read_access;

	public:
		inline Read() {
			_read_access = nullptr;
		}

		inline Read(const Read &p_other) {
			_read_access = pandemonium::api->pandemonium_pool_byte_array_read_access_copy(p_other._read_access);
		}

		inline ~Read() {
			pandemonium::api->pandemonium_pool_byte_array_read_access_destroy(_read_access);
		}

		inline const uint8_t *ptr() const {
			return pandemonium::api->pandemonium_pool_byte_array_read_access_ptr(_read_access);
		}

		inline const uint8_t &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Read &p_other) {
			pandemonium::api->pandemonium_pool_byte_array_read_access_operator_assign(_read_access, p_other._read_access);
		}
	};

	class Write {
		friend class PoolByteArray;
		pandemonium_pool_byte_array_write_access *_write_access;

	public:
		inline Write() {
			_write_access = nullptr;
		}

		inline Write(const Write &p_other) {
			_write_access = pandemonium::api->pandemonium_pool_byte_array_write_access_copy(p_other._write_access);
		}

		inline ~Write() {
			pandemonium::api->pandemonium_pool_byte_array_write_access_destroy(_write_access);
		}

		inline uint8_t *ptr() const {
			return pandemonium::api->pandemonium_pool_byte_array_write_access_ptr(_write_access);
		}

		inline uint8_t &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Write &p_other) {
			pandemonium::api->pandemonium_pool_byte_array_write_access_operator_assign(_write_access, p_other._write_access);
		}
	};

	PoolByteArray();
	PoolByteArray(const PoolByteArray &p_other);
	PoolByteArray &operator=(const PoolByteArray &p_other);

	PoolByteArray(const Array &array);

	Read read() const;

	Write write();

	void append(const uint8_t data);

	void append_array(const PoolByteArray &array);

	int insert(const int idx, const uint8_t data);

	void invert();

	void push_back(const uint8_t data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const uint8_t data);

	uint8_t operator[](const int idx);

	int size() const;

	~PoolByteArray();
};

class PoolIntArray {
	pandemonium_pool_int_array _pandemonium_array;

	friend class Variant;
	explicit inline PoolIntArray(pandemonium_pool_int_array a) {
		_pandemonium_array = a;
	}

public:
	class Read {
		friend class PoolIntArray;
		pandemonium_pool_int_array_read_access *_read_access;

	public:
		inline Read() {
			_read_access = nullptr;
		}

		inline Read(const Read &p_other) {
			_read_access = pandemonium::api->pandemonium_pool_int_array_read_access_copy(p_other._read_access);
		}

		inline ~Read() {
			pandemonium::api->pandemonium_pool_int_array_read_access_destroy(_read_access);
		}

		inline const int *ptr() const {
			return pandemonium::api->pandemonium_pool_int_array_read_access_ptr(_read_access);
		}

		inline const int &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Read &p_other) {
			pandemonium::api->pandemonium_pool_int_array_read_access_operator_assign(_read_access, p_other._read_access);
		}
	};

	class Write {
		friend class PoolIntArray;
		pandemonium_pool_int_array_write_access *_write_access;

	public:
		inline Write() {
			_write_access = nullptr;
		}

		inline Write(const Write &p_other) {
			_write_access = pandemonium::api->pandemonium_pool_int_array_write_access_copy(p_other._write_access);
		}

		inline ~Write() {
			pandemonium::api->pandemonium_pool_int_array_write_access_destroy(_write_access);
		}

		inline int *ptr() const {
			return pandemonium::api->pandemonium_pool_int_array_write_access_ptr(_write_access);
		}

		inline int &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Write &p_other) {
			pandemonium::api->pandemonium_pool_int_array_write_access_operator_assign(_write_access, p_other._write_access);
		}
	};

	PoolIntArray();
	PoolIntArray(const PoolIntArray &p_other);
	PoolIntArray &operator=(const PoolIntArray &p_other);

	PoolIntArray(const Array &array);

	Read read() const;

	Write write();

	void append(const int data);

	void append_array(const PoolIntArray &array);

	int insert(const int idx, const int data);

	void invert();

	void push_back(const int data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const int data);

	int operator[](const int idx);

	int size() const;

	~PoolIntArray();
};

class PoolRealArray {
	pandemonium_pool_real_array _pandemonium_array;

	friend class Variant;
	explicit inline PoolRealArray(pandemonium_pool_real_array a) {
		_pandemonium_array = a;
	}

public:
	class Read {
		friend class PoolRealArray;
		pandemonium_pool_real_array_read_access *_read_access;

	public:
		inline Read() {
			_read_access = nullptr;
		}

		inline Read(const Read &p_other) {
			_read_access = pandemonium::api->pandemonium_pool_real_array_read_access_copy(p_other._read_access);
		}

		inline ~Read() {
			pandemonium::api->pandemonium_pool_real_array_read_access_destroy(_read_access);
		}

		inline const real_t *ptr() const {
			return pandemonium::api->pandemonium_pool_real_array_read_access_ptr(_read_access);
		}

		inline const real_t &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Read &p_other) {
			pandemonium::api->pandemonium_pool_real_array_read_access_operator_assign(_read_access, p_other._read_access);
		}
	};

	class Write {
		friend class PoolRealArray;
		pandemonium_pool_real_array_write_access *_write_access;

	public:
		inline Write() {
			_write_access = nullptr;
		}

		inline Write(const Write &p_other) {
			_write_access = pandemonium::api->pandemonium_pool_real_array_write_access_copy(p_other._write_access);
		}

		inline ~Write() {
			pandemonium::api->pandemonium_pool_real_array_write_access_destroy(_write_access);
		}

		inline real_t *ptr() const {
			return pandemonium::api->pandemonium_pool_real_array_write_access_ptr(_write_access);
		}

		inline real_t &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Write &p_other) {
			pandemonium::api->pandemonium_pool_real_array_write_access_operator_assign(_write_access, p_other._write_access);
		}
	};

	PoolRealArray();
	PoolRealArray(const PoolRealArray &p_other);
	PoolRealArray &operator=(const PoolRealArray &p_other);

	PoolRealArray(const Array &array);

	Read read() const;

	Write write();

	void append(const real_t data);

	void append_array(const PoolRealArray &array);

	int insert(const int idx, const real_t data);

	void invert();

	void push_back(const real_t data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const real_t data);

	real_t operator[](const int idx);

	int size() const;

	~PoolRealArray();
};

class PoolStringArray {
	pandemonium_pool_string_array _pandemonium_array;

	friend class String;
	friend class Variant;
	explicit inline PoolStringArray(pandemonium_pool_string_array a) {
		_pandemonium_array = a;
	}

public:
	class Read {
		friend class PoolStringArray;
		pandemonium_pool_string_array_read_access *_read_access;

	public:
		inline Read() {
			_read_access = nullptr;
		}

		inline Read(const Read &p_other) {
			_read_access = pandemonium::api->pandemonium_pool_string_array_read_access_copy(p_other._read_access);
		}

		inline ~Read() {
			pandemonium::api->pandemonium_pool_string_array_read_access_destroy(_read_access);
		}

		inline const String *ptr() const {
			return (const String *)pandemonium::api->pandemonium_pool_string_array_read_access_ptr(_read_access);
		}

		inline const String &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Read &p_other) {
			pandemonium::api->pandemonium_pool_string_array_read_access_operator_assign(_read_access, p_other._read_access);
		}
	};

	class Write {
		friend class PoolStringArray;
		pandemonium_pool_string_array_write_access *_write_access;

	public:
		inline Write() {
			_write_access = nullptr;
		}

		inline Write(const Write &p_other) {
			_write_access = pandemonium::api->pandemonium_pool_string_array_write_access_copy(p_other._write_access);
		}

		inline ~Write() {
			pandemonium::api->pandemonium_pool_string_array_write_access_destroy(_write_access);
		}

		inline String *ptr() const {
			return (String *)pandemonium::api->pandemonium_pool_string_array_write_access_ptr(_write_access);
		}

		inline String &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Write &p_other) {
			pandemonium::api->pandemonium_pool_string_array_write_access_operator_assign(_write_access, p_other._write_access);
		}
	};

	PoolStringArray();
	PoolStringArray(const PoolStringArray &p_other);
	PoolStringArray &operator=(const PoolStringArray &p_other);

	PoolStringArray(const Array &array);

	Read read() const;

	Write write();

	void append(const String &data);

	void append_array(const PoolStringArray &array);

	int insert(const int idx, const String &data);

	void invert();

	void push_back(const String &data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const String &data);

	const String operator[](const int idx);

	int size() const;

	~PoolStringArray();
};

class PoolVector2Array {
	pandemonium_pool_vector2_array _pandemonium_array;

	friend class Variant;
	explicit inline PoolVector2Array(pandemonium_pool_vector2_array a) {
		_pandemonium_array = a;
	}

public:
	class Read {
		friend class PoolVector2Array;
		pandemonium_pool_vector2_array_read_access *_read_access;

	public:
		inline Read() {
			_read_access = nullptr;
		}

		inline Read(const Read &p_other) {
			_read_access = pandemonium::api->pandemonium_pool_vector2_array_read_access_copy(p_other._read_access);
		}

		inline ~Read() {
			pandemonium::api->pandemonium_pool_vector2_array_read_access_destroy(_read_access);
		}

		inline const Vector2 *ptr() const {
			return (const Vector2 *)pandemonium::api->pandemonium_pool_vector2_array_read_access_ptr(_read_access);
		}

		inline const Vector2 &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Read &p_other) {
			pandemonium::api->pandemonium_pool_vector2_array_read_access_operator_assign(_read_access, p_other._read_access);
		}
	};

	class Write {
		friend class PoolVector2Array;
		pandemonium_pool_vector2_array_write_access *_write_access;

	public:
		inline Write() {
			_write_access = nullptr;
		}

		inline Write(const Write &p_other) {
			_write_access = pandemonium::api->pandemonium_pool_vector2_array_write_access_copy(p_other._write_access);
		}

		inline ~Write() {
			pandemonium::api->pandemonium_pool_vector2_array_write_access_destroy(_write_access);
		}

		inline Vector2 *ptr() const {
			return (Vector2 *)pandemonium::api->pandemonium_pool_vector2_array_write_access_ptr(_write_access);
		}

		inline Vector2 &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Write &p_other) {
			pandemonium::api->pandemonium_pool_vector2_array_write_access_operator_assign(_write_access, p_other._write_access);
		}
	};

	PoolVector2Array();
	PoolVector2Array(const PoolVector2Array &p_other);
	PoolVector2Array &operator=(const PoolVector2Array &p_other);

	PoolVector2Array(const Array &array);

	Read read() const;

	Write write();

	void append(const Vector2 &data);

	void append_array(const PoolVector2Array &array);

	int insert(const int idx, const Vector2 &data);

	void invert();

	void push_back(const Vector2 &data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const Vector2 &data);

	const Vector2 operator[](const int idx);

	int size() const;

	~PoolVector2Array();
};

class PoolVector2iArray {
	pandemonium_pool_vector2i_array _pandemonium_array;

	friend class Variant;
	explicit inline PoolVector2iArray(pandemonium_pool_vector2i_array a) {
		_pandemonium_array = a;
	}

public:
	class Read {
		friend class PoolVector2iArray;
		pandemonium_pool_vector2i_array_read_access *_read_access;

	public:
		inline Read() {
			_read_access = nullptr;
		}

		inline Read(const Read &p_other) {
			_read_access = pandemonium::api->pandemonium_pool_vector2i_array_read_access_copy(p_other._read_access);
		}

		inline ~Read() {
			pandemonium::api->pandemonium_pool_vector2i_array_read_access_destroy(_read_access);
		}

		inline const Vector2i *ptr() const {
			return (const Vector2i *)pandemonium::api->pandemonium_pool_vector2i_array_read_access_ptr(_read_access);
		}

		inline const Vector2i &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Read &p_other) {
			pandemonium::api->pandemonium_pool_vector2i_array_read_access_operator_assign(_read_access, p_other._read_access);
		}
	};

	class Write {
		friend class PoolVector2iArray;
		pandemonium_pool_vector2i_array_write_access *_write_access;

	public:
		inline Write() {
			_write_access = nullptr;
		}

		inline Write(const Write &p_other) {
			_write_access = pandemonium::api->pandemonium_pool_vector2i_array_write_access_copy(p_other._write_access);
		}

		inline ~Write() {
			pandemonium::api->pandemonium_pool_vector2i_array_write_access_destroy(_write_access);
		}

		inline Vector2i *ptr() const {
			return (Vector2i *)pandemonium::api->pandemonium_pool_vector2i_array_write_access_ptr(_write_access);
		}

		inline Vector2i &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Write &p_other) {
			pandemonium::api->pandemonium_pool_vector2i_array_write_access_operator_assign(_write_access, p_other._write_access);
		}
	};

	PoolVector2iArray();
	PoolVector2iArray(const PoolVector2iArray &p_other);
	PoolVector2iArray &operator=(const PoolVector2iArray &p_other);

	PoolVector2iArray(const Array &array);

	Read read() const;

	Write write();

	void append(const Vector2i &data);

	void append_array(const PoolVector2iArray &array);

	int insert(const int idx, const Vector2i &data);

	void invert();

	void push_back(const Vector2i &data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const Vector2i &data);

	const Vector2i operator[](const int idx);

	int size() const;

	~PoolVector2iArray();
};

class PoolVector3Array {
	pandemonium_pool_vector3_array _pandemonium_array;

	friend class Variant;
	explicit inline PoolVector3Array(pandemonium_pool_vector3_array a) {
		_pandemonium_array = a;
	}

public:
	class Read {
		friend class PoolVector3Array;
		pandemonium_pool_vector3_array_read_access *_read_access;

	public:
		inline Read() {
			_read_access = nullptr;
		}

		inline Read(const Read &p_other) {
			_read_access = pandemonium::api->pandemonium_pool_vector3_array_read_access_copy(p_other._read_access);
		}

		inline ~Read() {
			pandemonium::api->pandemonium_pool_vector3_array_read_access_destroy(_read_access);
		}

		inline const Vector3 *ptr() const {
			return (const Vector3 *)pandemonium::api->pandemonium_pool_vector3_array_read_access_ptr(_read_access);
		}

		inline const Vector3 &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Read &p_other) {
			pandemonium::api->pandemonium_pool_vector3_array_read_access_operator_assign(_read_access, p_other._read_access);
		}
	};

	class Write {
		friend class PoolVector3Array;
		pandemonium_pool_vector3_array_write_access *_write_access;

	public:
		inline Write() {
			_write_access = nullptr;
		}

		inline Write(const Write &p_other) {
			_write_access = pandemonium::api->pandemonium_pool_vector3_array_write_access_copy(p_other._write_access);
		}

		inline ~Write() {
			pandemonium::api->pandemonium_pool_vector3_array_write_access_destroy(_write_access);
		}

		inline Vector3 *ptr() const {
			return (Vector3 *)pandemonium::api->pandemonium_pool_vector3_array_write_access_ptr(_write_access);
		}

		inline Vector3 &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Write &p_other) {
			pandemonium::api->pandemonium_pool_vector3_array_write_access_operator_assign(_write_access, p_other._write_access);
		}
	};

	PoolVector3Array();
	PoolVector3Array(const PoolVector3Array &p_other);
	PoolVector3Array &operator=(const PoolVector3Array &p_other);

	PoolVector3Array(const Array &array);

	Read read() const;

	Write write();

	void append(const Vector3 &data);

	void append_array(const PoolVector3Array &array);

	int insert(const int idx, const Vector3 &data);

	void invert();

	void push_back(const Vector3 &data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const Vector3 &data);

	const Vector3 operator[](const int idx);

	int size() const;

	~PoolVector3Array();
};

class PoolColorArray {
	pandemonium_pool_color_array _pandemonium_array;

	friend class Variant;
	explicit inline PoolColorArray(pandemonium_pool_color_array a) {
		_pandemonium_array = a;
	}

public:
	class Read {
		friend class PoolColorArray;
		pandemonium_pool_color_array_read_access *_read_access;

	public:
		inline Read() {
			_read_access = nullptr;
		}

		inline Read(const Read &p_other) {
			_read_access = pandemonium::api->pandemonium_pool_color_array_read_access_copy(p_other._read_access);
		}

		inline ~Read() {
			pandemonium::api->pandemonium_pool_color_array_read_access_destroy(_read_access);
		}

		inline const Color *ptr() const {
			return (const Color *)pandemonium::api->pandemonium_pool_color_array_read_access_ptr(_read_access);
		}

		inline const Color &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Read &p_other) {
			pandemonium::api->pandemonium_pool_color_array_read_access_operator_assign(_read_access, p_other._read_access);
		}
	};

	class Write {
		friend class PoolColorArray;
		pandemonium_pool_color_array_write_access *_write_access;

	public:
		inline Write() {
			_write_access = nullptr;
		}

		inline Write(const Write &p_other) {
			_write_access = pandemonium::api->pandemonium_pool_color_array_write_access_copy(p_other._write_access);
		}

		inline ~Write() {
			pandemonium::api->pandemonium_pool_color_array_write_access_destroy(_write_access);
		}

		inline Color *ptr() const {
			return (Color *)pandemonium::api->pandemonium_pool_color_array_write_access_ptr(_write_access);
		}

		inline Color &operator[](int p_idx) const {
			return ptr()[p_idx];
		}

		inline void operator=(const Write &p_other) {
			pandemonium::api->pandemonium_pool_color_array_write_access_operator_assign(_write_access, p_other._write_access);
		}
	};

	PoolColorArray();
	PoolColorArray(const PoolColorArray &p_other);
	PoolColorArray &operator=(const PoolColorArray &p_other);

	PoolColorArray(const Array &array);

	Read read() const;

	Write write();

	void append(const Color &data);

	void append_array(const PoolColorArray &array);

	int insert(const int idx, const Color &data);

	void invert();

	void push_back(const Color &data);

	void remove(const int idx);

	void resize(const int size);

	void set(const int idx, const Color &data);

	const Color operator[](const int idx);

	int size() const;

	~PoolColorArray();
};

} // namespace pandemonium

#endif // POOLARRAYS_H
