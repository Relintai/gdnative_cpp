/*************************************************************************/
/*  Array.cpp                                                            */
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

#include "array.h"
#include "pandemonium_global.h"
#include "ustring.h"
#include "variant.h"

#include <cstdlib>

class Object;

Variant &Array::operator[](const int idx) {
	pandemonium_variant *v = Pandemonium::api->pandemonium_array_operator_index(&_pandemonium_array, idx);
	// We assume it's ok to reinterpret because the value is a pointer whose data is already owned by the array,
	// so can return a reference without constructing a Variant
	return *reinterpret_cast<Variant *>(v);
}

const Variant &Array::operator[](const int idx) const {
	// Yes, I'm casting away the const... you can hate me now.
	// since the result is
	pandemonium_variant *v = Pandemonium::api->pandemonium_array_operator_index((pandemonium_array *)&_pandemonium_array, idx);
	return *reinterpret_cast<const Variant *>(v);
}

void Array::set(int p_idx, const Variant &p_value) {
	operator[](p_idx) = p_value;
}
const Variant &Array::get(int p_idx) const {
	return operator[](p_idx);
}

int Array::size() const {
	return Pandemonium::api->pandemonium_array_size(&_pandemonium_array);
}
bool Array::empty() const {
	return Pandemonium::api->pandemonium_array_empty(&_pandemonium_array);
}
void Array::clear() {
	Pandemonium::api->pandemonium_array_clear(&_pandemonium_array);
}

bool Array::deep_equal(const Array &p_array) const {
	return Pandemonium::api->pandemonium_array_deep_equal(&_pandemonium_array, &p_array._pandemonium_array);
}
bool Array::deep_equal(const Array &p_array, const int p_recursion_count) const {
	return Pandemonium::api->pandemonium_array_deep_equal_recursion_count(&_pandemonium_array, &p_array._pandemonium_array, p_recursion_count);
}
bool Array::deep_equal_approx(const Array &p_array) const {
	return Pandemonium::api->pandemonium_array_deep_equal_approx(&_pandemonium_array, &p_array._pandemonium_array);
}
bool Array::deep_equal_approx(const Array &p_array, const int p_recursion_count) const {
	return Pandemonium::api->pandemonium_array_deep_equal_approx_recursion_count(&_pandemonium_array, &p_array._pandemonium_array, p_recursion_count);
}
bool Array::operator==(const Array &p_array) {
	return Pandemonium::api->pandemonium_array_operator_equals(&_pandemonium_array, &p_array._pandemonium_array);
}

uint32_t Array::hash() const {
	return Pandemonium::api->pandemonium_array_hash(&_pandemonium_array);
}

Array &Array::operator=(const Array &other) {
	Pandemonium::api->pandemonium_array_destroy(&_pandemonium_array);
	Pandemonium::api->pandemonium_array_new_copy(&_pandemonium_array, &other._pandemonium_array);
	return *this;
}

void Array::push_back(const Variant &v) {
	Pandemonium::api->pandemonium_array_push_back(&_pandemonium_array, (pandemonium_variant *)&v);
}
void Array::append(const Variant &v) {
	Pandemonium::api->pandemonium_array_append(&_pandemonium_array, (pandemonium_variant *)&v);
}
void Array::append_array(const Array& p_array) {
	Pandemonium::api->pandemonium_array_append_array(&_pandemonium_array, &p_array._pandemonium_array);
}
void Array::resize(const int size) {
	Pandemonium::api->pandemonium_array_resize(&_pandemonium_array, size);
}

void Array::insert(const int pos, const Variant &value) {
	Pandemonium::api->pandemonium_array_insert(&_pandemonium_array, pos, (pandemonium_variant *)&value);
}
void Array::remove(const int idx) {
	Pandemonium::api->pandemonium_array_remove(&_pandemonium_array, idx);
}
void Array::fill(const Variant &p_value) {
	Pandemonium::api->pandemonium_array_fill(&_pandemonium_array, (pandemonium_variant *)&p_value);
}

Variant Array::front() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_array_front(&_pandemonium_array);
	return Variant(v);
}
Variant Array::back() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_array_back(&_pandemonium_array);
	return Variant(v);
}

void Array::sort() {
	Pandemonium::api->pandemonium_array_sort(&_pandemonium_array);
}
void Array::sort_custom(Object *obj, const String &func) {
	Pandemonium::api->pandemonium_array_sort_custom(&_pandemonium_array, (pandemonium_object *)obj, (pandemonium_string *)&func);
}
void Array::shuffle() {
	Pandemonium::api->pandemonium_array_shuffle(&_pandemonium_array);
}

int Array::bsearch(const Variant &value, const bool before) {
	return Pandemonium::api->pandemonium_array_bsearch(&_pandemonium_array, (pandemonium_variant *)&value, before);
}
int Array::bsearch_custom(const Variant &value, const Object *obj, const String &func, const bool before) {
	return Pandemonium::api->pandemonium_array_bsearch_custom(&_pandemonium_array, (pandemonium_variant *)&value,
			(pandemonium_object *)obj, (pandemonium_string *)&func, before);
}

void Array::invert() {
	Pandemonium::api->pandemonium_array_invert(&_pandemonium_array);
}


int Array::find(const Variant &what, const int from) const {
	return Pandemonium::api->pandemonium_array_find_from(&_pandemonium_array, (pandemonium_variant *)&what, from);
}
int Array::rfind(const Variant &what, const int from) const {
	return Pandemonium::api->pandemonium_array_rfind_from(&_pandemonium_array, (pandemonium_variant *)&what, from);
}
int Array::find_last(const Variant &what) const {
	return Pandemonium::api->pandemonium_array_find_last(&_pandemonium_array, (pandemonium_variant *)&what);
}
int Array::count(const Variant &v) {
	return Pandemonium::api->pandemonium_array_count(&_pandemonium_array, (pandemonium_variant *)&v);
}
bool Array::has(const Variant &what) const {
	return Pandemonium::api->pandemonium_array_has(&_pandemonium_array, (pandemonium_variant *)&what);
}

void Array::erase(const Variant &v) {
	Pandemonium::api->pandemonium_array_erase(&_pandemonium_array, (pandemonium_variant *)&v);
}

void Array::push_front(const Variant &v) {
	Pandemonium::api->pandemonium_array_push_front(&_pandemonium_array, (pandemonium_variant *)&v);
}

Variant Array::pop_back() {
	pandemonium_variant v = Pandemonium::api->pandemonium_array_pop_back(&_pandemonium_array);
	return Variant(v);
}

Variant Array::pop_front() {
	pandemonium_variant v = Pandemonium::api->pandemonium_array_pop_front(&_pandemonium_array);
	return Variant(v);
}
Variant Array::pop_at(int p_pos) {
	pandemonium_variant v = Pandemonium::api->pandemonium_array_pop_at(&_pandemonium_array, p_pos);
	return Variant(v);
}

Array Array::duplicate(const bool deep) const {
	pandemonium_array arr = Pandemonium::api->pandemonium_array_duplicate_deep(&_pandemonium_array, deep);
	return Array(arr);
}

Array Array::slice(int p_begin, int p_end, int p_step, bool p_deep) const {
	pandemonium_array arr = Pandemonium::api->pandemonium_array_slice_step_deep(&_pandemonium_array, p_begin, p_end, p_step, p_deep);
	return Array(arr);
}

Variant Array::max() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_array_max(&_pandemonium_array);
	return Variant(v);
}

Variant Array::min() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_array_min(&_pandemonium_array);
	return Variant(v);
}

Array::Array() {
	Pandemonium::api->pandemonium_array_new(&_pandemonium_array);
}

Array::Array(const Array &other) {
	Pandemonium::api->pandemonium_array_new_copy(&_pandemonium_array, &other._pandemonium_array);
}

Array::Array(const PoolByteArray &a) {
	Pandemonium::api->pandemonium_array_new_pool_byte_array(&_pandemonium_array, (pandemonium_pool_byte_array *)&a);
}
Array::Array(const PoolIntArray &a) {
	Pandemonium::api->pandemonium_array_new_pool_int_array(&_pandemonium_array, (pandemonium_pool_int_array *)&a);
}
Array::Array(const PoolRealArray &a) {
	Pandemonium::api->pandemonium_array_new_pool_real_array(&_pandemonium_array, (pandemonium_pool_real_array *)&a);
}
Array::Array(const PoolStringArray &a) {
	Pandemonium::api->pandemonium_array_new_pool_string_array(&_pandemonium_array, (pandemonium_pool_string_array *)&a);
}
Array::Array(const PoolVector2Array &a) {
	Pandemonium::api->pandemonium_array_new_pool_vector2_array(&_pandemonium_array, (pandemonium_pool_vector2_array *)&a);
}
Array::Array(const PoolVector2iArray &a) {
	Pandemonium::api->pandemonium_array_new_pool_vector2i_array(&_pandemonium_array, (pandemonium_pool_vector2i_array *)&a);
}
Array::Array(const PoolVector3Array &a) {
	Pandemonium::api->pandemonium_array_new_pool_vector3_array(&_pandemonium_array, (pandemonium_pool_vector3_array *)&a);
}
Array::Array(const PoolVector3iArray &a) {
	Pandemonium::api->pandemonium_array_new_pool_vector3i_array(&_pandemonium_array, (pandemonium_pool_vector3i_array *)&a);
}
Array::Array(const PoolVector4Array &a) {
	Pandemonium::api->pandemonium_array_new_pool_vector4_array(&_pandemonium_array, (pandemonium_pool_vector4_array *)&a);
}
Array::Array(const PoolVector4iArray &a) {
	Pandemonium::api->pandemonium_array_new_pool_vector4i_array(&_pandemonium_array, (pandemonium_pool_vector4i_array *)&a);
}
Array::Array(const PoolColorArray &a) {
	Pandemonium::api->pandemonium_array_new_pool_color_array(&_pandemonium_array, (pandemonium_pool_color_array *)&a);
}

Array::~Array() {
	Pandemonium::api->pandemonium_array_destroy(&_pandemonium_array);
}
