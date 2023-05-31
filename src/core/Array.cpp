/*************************************************************************/
/*  Array.cpp                                                            */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
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

#include "Array.hpp"
#include "GodotGlobal.hpp"
#include "Variant.hpp"
#include "String.hpp"

#include <cstdlib>

namespace godot {

class Object;

Array::Array() {
	godot::api->pandemonium_array_new(&_pandemonium_array);
}

Array::Array(const Array &other) {
	godot::api->pandemonium_array_new_copy(&_pandemonium_array, &other._pandemonium_array);
}

Array &Array::operator=(const Array &other) {
	godot::api->pandemonium_array_destroy(&_pandemonium_array);
	godot::api->pandemonium_array_new_copy(&_pandemonium_array, &other._pandemonium_array);
	return *this;
}

Array::Array(const PoolByteArray &a) {
	godot::api->pandemonium_array_new_pool_byte_array(&_pandemonium_array, (pandemonium_pool_byte_array *)&a);
}

Array::Array(const PoolIntArray &a) {
	godot::api->pandemonium_array_new_pool_int_array(&_pandemonium_array, (pandemonium_pool_int_array *)&a);
}

Array::Array(const PoolRealArray &a) {
	godot::api->pandemonium_array_new_pool_real_array(&_pandemonium_array, (pandemonium_pool_real_array *)&a);
}

Array::Array(const PoolStringArray &a) {
	godot::api->pandemonium_array_new_pool_string_array(&_pandemonium_array, (pandemonium_pool_string_array *)&a);
}

Array::Array(const PoolVector2Array &a) {
	godot::api->pandemonium_array_new_pool_vector2_array(&_pandemonium_array, (pandemonium_pool_vector2_array *)&a);
}

Array::Array(const PoolVector3Array &a) {
	godot::api->pandemonium_array_new_pool_vector3_array(&_pandemonium_array, (pandemonium_pool_vector3_array *)&a);
}

Array::Array(const PoolColorArray &a) {
	godot::api->pandemonium_array_new_pool_color_array(&_pandemonium_array, (pandemonium_pool_color_array *)&a);
}

Variant &Array::operator[](const int idx) {
	pandemonium_variant *v = godot::api->pandemonium_array_operator_index(&_pandemonium_array, idx);
	// We assume it's ok to reinterpret because the value is a pointer whose data is already owned by the array,
	// so can return a reference without constructing a Variant
	return *reinterpret_cast<Variant *>(v);
}

const Variant &Array::operator[](const int idx) const {
	// Yes, I'm casting away the const... you can hate me now.
	// since the result is
	pandemonium_variant *v = godot::api->pandemonium_array_operator_index((pandemonium_array *)&_pandemonium_array, idx);
	return *reinterpret_cast<const Variant *>(v);
}

void Array::append(const Variant &v) {
	godot::api->pandemonium_array_append(&_pandemonium_array, (pandemonium_variant *)&v);
}

void Array::clear() {
	godot::api->pandemonium_array_clear(&_pandemonium_array);
}

int Array::count(const Variant &v) {
	return godot::api->pandemonium_array_count(&_pandemonium_array, (pandemonium_variant *)&v);
}

bool Array::empty() const {
	return godot::api->pandemonium_array_empty(&_pandemonium_array);
}

void Array::erase(const Variant &v) {
	godot::api->pandemonium_array_erase(&_pandemonium_array, (pandemonium_variant *)&v);
}

Variant Array::front() const {
	pandemonium_variant v = godot::api->pandemonium_array_front(&_pandemonium_array);
	return Variant(v);
}

Variant Array::back() const {
	pandemonium_variant v = godot::api->pandemonium_array_back(&_pandemonium_array);
	return Variant(v);
}

int Array::find(const Variant &what, const int from) const {
	return godot::api->pandemonium_array_find_from(&_pandemonium_array, (pandemonium_variant *)&what, from);
}

int Array::find_last(const Variant &what) const {
	return godot::api->pandemonium_array_find_last(&_pandemonium_array, (pandemonium_variant *)&what);
}

bool Array::has(const Variant &what) const {
	return godot::api->pandemonium_array_has(&_pandemonium_array, (pandemonium_variant *)&what);
}

uint32_t Array::hash() const {
	return godot::api->pandemonium_array_hash(&_pandemonium_array);
}

void Array::insert(const int pos, const Variant &value) {
	godot::api->pandemonium_array_insert(&_pandemonium_array, pos, (pandemonium_variant *)&value);
}

void Array::invert() {
	godot::api->pandemonium_array_invert(&_pandemonium_array);
}

Variant Array::pop_back() {
	pandemonium_variant v = godot::api->pandemonium_array_pop_back(&_pandemonium_array);
	return Variant(v);
}

Variant Array::pop_front() {
	pandemonium_variant v = godot::api->pandemonium_array_pop_front(&_pandemonium_array);
	return Variant(v);
}

void Array::push_back(const Variant &v) {
	godot::api->pandemonium_array_push_back(&_pandemonium_array, (pandemonium_variant *)&v);
}

void Array::push_front(const Variant &v) {
	godot::api->pandemonium_array_push_front(&_pandemonium_array, (pandemonium_variant *)&v);
}

void Array::remove(const int idx) {
	godot::api->pandemonium_array_remove(&_pandemonium_array, idx);
}

int Array::size() const {
	return godot::api->pandemonium_array_size(&_pandemonium_array);
}

void Array::resize(const int size) {
	godot::api->pandemonium_array_resize(&_pandemonium_array, size);
}

int Array::rfind(const Variant &what, const int from) const {
	return godot::api->pandemonium_array_rfind_from(&_pandemonium_array, (pandemonium_variant *)&what, from);
}

void Array::sort() {
	godot::api->pandemonium_array_sort(&_pandemonium_array);
}

void Array::sort_custom(Object *obj, const String &func) {
	godot::api->pandemonium_array_sort_custom(&_pandemonium_array, (pandemonium_object *)obj, (pandemonium_string *)&func);
}

int Array::bsearch(const Variant &value, const bool before) {
	return godot::api->pandemonium_array_bsearch(&_pandemonium_array, (pandemonium_variant *)&value, before);
}

int Array::bsearch_custom(const Variant &value, const Object *obj,
		const String &func, const bool before) {
	return godot::api->pandemonium_array_bsearch_custom(&_pandemonium_array, (pandemonium_variant *)&value,
			(pandemonium_object *)obj, (pandemonium_string *)&func, before);
}

Array Array::duplicate(const bool deep) const {
	pandemonium_array arr = godot::api->pandemonium_array_duplicate_deep(&_pandemonium_array, deep);
	return Array(arr);
}

Variant Array::max() const {
	pandemonium_variant v = godot::api->pandemonium_array_max(&_pandemonium_array);
	return Variant(v);
}

Variant Array::min() const {
	pandemonium_variant v = godot::api->pandemonium_array_min(&_pandemonium_array);
	return Variant(v);
}

void Array::shuffle() {
	godot::api->pandemonium_array_shuffle(&_pandemonium_array);
}

Array::~Array() {
	godot::api->pandemonium_array_destroy(&_pandemonium_array);
}

} // namespace godot
