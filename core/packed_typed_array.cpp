/*************************************************************************/
/*  typed_array.cpp                                                            */
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

#include "packed_typed_array.h"
#include "pandemonium_global.h"
#include "string_name.h"
#include "ustring.h"
#include "variant.h"

#include <cstdlib>

class Object;

const Variant PackedTypedArray::operator[](const int idx) const {
	const pandemonium_variant v = Pandemonium::api->pandemonium_packed_typed_array_operator_index_const((const pandemonium_packed_typed_array *)&_pandemonium_packed_typed_array, idx);
	return Variant(v);
}

// bool PackedTypedArray::set(int p_idx, const Variant &p_value) {
//	return Pandemonium::api->pandemonium_packed_typed_array_set(&_pandemonium_packed_typed_array, p_idx, (const pandemonium_variant *)&p_value);
// }
void PackedTypedArray::set(int p_idx, const Variant &p_value) {
	Pandemonium::api->pandemonium_packed_typed_array_set(&_pandemonium_packed_typed_array, p_idx, (const pandemonium_variant *)&p_value);
}
const Variant PackedTypedArray::get(int p_idx) const {
	pandemonium_variant v = Pandemonium::api->pandemonium_packed_typed_array_get(&_pandemonium_packed_typed_array, p_idx);
	return Variant(v);
}

int PackedTypedArray::size() const {
	return Pandemonium::api->pandemonium_packed_typed_array_size(&_pandemonium_packed_typed_array);
}
bool PackedTypedArray::empty() const {
	return Pandemonium::api->pandemonium_packed_typed_array_empty(&_pandemonium_packed_typed_array);
}
void PackedTypedArray::clear() {
	Pandemonium::api->pandemonium_packed_typed_array_clear(&_pandemonium_packed_typed_array);
}

bool PackedTypedArray::deep_equal(const PackedTypedArray &p_array, const int p_recursion_count) const {
	return Pandemonium::api->pandemonium_packed_typed_array_deep_equal_recursion_count(&_pandemonium_packed_typed_array, &p_array._pandemonium_packed_typed_array, p_recursion_count);
}
bool PackedTypedArray::deep_equal_approx(const PackedTypedArray &p_array, const int p_recursion_count) const {
	return Pandemonium::api->pandemonium_packed_typed_array_deep_equal_approx_recursion_count(&_pandemonium_packed_typed_array, &p_array._pandemonium_packed_typed_array, p_recursion_count);
}
bool PackedTypedArray::operator==(const PackedTypedArray &p_array) {
	return Pandemonium::api->pandemonium_packed_typed_array_operator_equals(&_pandemonium_packed_typed_array, &p_array._pandemonium_packed_typed_array);
}

uint32_t PackedTypedArray::hash() const {
	return Pandemonium::api->pandemonium_packed_typed_array_hash(&_pandemonium_packed_typed_array);
}

PackedTypedArray &PackedTypedArray::operator=(const PackedTypedArray &other) {
	Pandemonium::api->pandemonium_packed_typed_array_destroy(&_pandemonium_packed_typed_array);
	Pandemonium::api->pandemonium_packed_typed_array_new_copy(&_pandemonium_packed_typed_array, &other._pandemonium_packed_typed_array);
	return *this;
}

void PackedTypedArray::push_back(const Variant &v) {
	Pandemonium::api->pandemonium_packed_typed_array_push_back(&_pandemonium_packed_typed_array, (pandemonium_variant *)&v);
}
void PackedTypedArray::append(const Variant &v) {
	Pandemonium::api->pandemonium_packed_typed_array_append(&_pandemonium_packed_typed_array, (pandemonium_variant *)&v);
}
void PackedTypedArray::append_array(const PackedTypedArray &p_array) {
	Pandemonium::api->pandemonium_packed_typed_array_append_array(&_pandemonium_packed_typed_array, &p_array._pandemonium_packed_typed_array);
}
void PackedTypedArray::append_from(const Variant &p_array) {
	Pandemonium::api->pandemonium_packed_typed_array_append_from(&_pandemonium_packed_typed_array, (const pandemonium_variant *)&p_array);
}
void PackedTypedArray::resize(const int size) {
	Pandemonium::api->pandemonium_packed_typed_array_resize(&_pandemonium_packed_typed_array, size);
}

void PackedTypedArray::insert(const int pos, const Variant &value) {
	Pandemonium::api->pandemonium_packed_typed_array_insert(&_pandemonium_packed_typed_array, pos, (pandemonium_variant *)&value);
}
void PackedTypedArray::remove(const int idx) {
	Pandemonium::api->pandemonium_packed_typed_array_remove(&_pandemonium_packed_typed_array, idx);
}
void PackedTypedArray::fill(const Variant &p_value) {
	Pandemonium::api->pandemonium_packed_typed_array_fill(&_pandemonium_packed_typed_array, (pandemonium_variant *)&p_value);
}

Variant PackedTypedArray::front() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_packed_typed_array_front(&_pandemonium_packed_typed_array);
	return Variant(v);
}
Variant PackedTypedArray::back() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_packed_typed_array_back(&_pandemonium_packed_typed_array);
	return Variant(v);
}

void PackedTypedArray::sort() {
	Pandemonium::api->pandemonium_packed_typed_array_sort(&_pandemonium_packed_typed_array);
}
void PackedTypedArray::sort_custom(Object *obj, const String &func) {
	Pandemonium::api->pandemonium_packed_typed_array_sort_custom(&_pandemonium_packed_typed_array, (pandemonium_object *)obj, (pandemonium_string *)&func);
}
void PackedTypedArray::shuffle() {
	Pandemonium::api->pandemonium_packed_typed_array_shuffle(&_pandemonium_packed_typed_array);
}

int PackedTypedArray::bsearch(const Variant &value, const bool before) {
	return Pandemonium::api->pandemonium_packed_typed_array_bsearch(&_pandemonium_packed_typed_array, (pandemonium_variant *)&value, before);
}
int PackedTypedArray::bsearch_custom(const Variant &value, const Object *obj, const String &func, const bool before) {
	return Pandemonium::api->pandemonium_packed_typed_array_bsearch_custom(&_pandemonium_packed_typed_array, (pandemonium_variant *)&value,
			(pandemonium_object *)obj, (pandemonium_string *)&func, before);
}

void PackedTypedArray::invert() {
	Pandemonium::api->pandemonium_packed_typed_array_invert(&_pandemonium_packed_typed_array);
}

int PackedTypedArray::find(const Variant &what, const int from) const {
	return Pandemonium::api->pandemonium_packed_typed_array_find_from(&_pandemonium_packed_typed_array, (pandemonium_variant *)&what, from);
}
int PackedTypedArray::rfind(const Variant &what, const int from) const {
	return Pandemonium::api->pandemonium_packed_typed_array_rfind_from(&_pandemonium_packed_typed_array, (pandemonium_variant *)&what, from);
}
int PackedTypedArray::find_last(const Variant &what) const {
	return Pandemonium::api->pandemonium_packed_typed_array_find_last(&_pandemonium_packed_typed_array, (pandemonium_variant *)&what);
}
int PackedTypedArray::count(const Variant &v) {
	return Pandemonium::api->pandemonium_packed_typed_array_count(&_pandemonium_packed_typed_array, (pandemonium_variant *)&v);
}
bool PackedTypedArray::has(const Variant &what) const {
	return Pandemonium::api->pandemonium_packed_typed_array_has(&_pandemonium_packed_typed_array, (pandemonium_variant *)&what);
}

void PackedTypedArray::erase(const Variant &v) {
	Pandemonium::api->pandemonium_packed_typed_array_erase(&_pandemonium_packed_typed_array, (pandemonium_variant *)&v);
}

void PackedTypedArray::push_front(const Variant &v) {
	Pandemonium::api->pandemonium_packed_typed_array_push_front(&_pandemonium_packed_typed_array, (pandemonium_variant *)&v);
}

Variant PackedTypedArray::pop_back() {
	pandemonium_variant v = Pandemonium::api->pandemonium_packed_typed_array_pop_back(&_pandemonium_packed_typed_array);
	return Variant(v);
}

Variant PackedTypedArray::pop_front() {
	pandemonium_variant v = Pandemonium::api->pandemonium_packed_typed_array_pop_front(&_pandemonium_packed_typed_array);
	return Variant(v);
}
Variant PackedTypedArray::pop_at(int p_pos) {
	pandemonium_variant v = Pandemonium::api->pandemonium_packed_typed_array_pop_at(&_pandemonium_packed_typed_array, p_pos);
	return Variant(v);
}

PackedTypedArray PackedTypedArray::duplicate(const bool deep) const {
	pandemonium_packed_typed_array arr = Pandemonium::api->pandemonium_packed_typed_array_duplicate_deep(&_pandemonium_packed_typed_array, deep);
	return PackedTypedArray(arr);
}

PackedTypedArray PackedTypedArray::slice(int p_begin, int p_end, int p_step, bool p_deep) const {
	pandemonium_packed_typed_array arr = Pandemonium::api->pandemonium_packed_typed_array_slice_step_deep(&_pandemonium_packed_typed_array, p_begin, p_end, p_step, p_deep);
	return PackedTypedArray(arr);
}

Variant PackedTypedArray::max() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_packed_typed_array_max(&_pandemonium_packed_typed_array);
	return Variant(v);
}

Variant PackedTypedArray::min() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_packed_typed_array_min(&_pandemonium_packed_typed_array);
	return Variant(v);
}

String PackedTypedArray::get_typename_string() const {
	pandemonium_string s = Pandemonium::api->pandemonium_packed_typed_array_get_typename_string(&_pandemonium_packed_typed_array);
	return String(s);
}

int PackedTypedArray::get_variant_type() const {
	return Pandemonium::api->pandemonium_packed_typed_array_get_variant_type(&_pandemonium_packed_typed_array);
}
void PackedTypedArray::set_variant_type(const int p_variant_type) {
	Pandemonium::api->pandemonium_packed_typed_array_set_variant_type(&_pandemonium_packed_typed_array, p_variant_type);
}

PackedTypedArray::IntType PackedTypedArray::get_int_type() const {
	pandemonium_packed_typed_array_int_type int_type = pandemonium_packed_typed_array_get_int_type(&_pandemonium_packed_typed_array);
	return static_cast<IntType>(int_type);
}
void PackedTypedArray::set_int_type(const IntType p_int_type) {
	pandemonium_packed_typed_array_set_int_type(&_pandemonium_packed_typed_array, static_cast<pandemonium_packed_typed_array_int_type>(p_int_type));
}

StringName PackedTypedArray::get_object_class_name() const {
	pandemonium_string_name s = Pandemonium::api->pandemonium_packed_typed_array_get_object_class_name(&_pandemonium_packed_typed_array);
	return StringName(s);
}
void PackedTypedArray::set_object_class_name(const StringName &p_object_type_name) {
	Pandemonium::api->pandemonium_packed_typed_array_set_object_class_name(&_pandemonium_packed_typed_array, (const pandemonium_string_name *)&p_object_type_name);
}

void PackedTypedArray::set_type_from_name(const StringName &p_type_name) {
	Pandemonium::api->pandemonium_packed_typed_array_set_type_from_name(&_pandemonium_packed_typed_array, (const pandemonium_string_name *)&p_type_name);
}
void PackedTypedArray::set_type_from_variant(const Variant &p_variant) {
	Pandemonium::api->pandemonium_packed_typed_array_set_type_from_variant(&_pandemonium_packed_typed_array, (const pandemonium_variant *)&p_variant);
}
void PackedTypedArray::set_type_from_array_element(const Variant &p_array) {
	Pandemonium::api->pandemonium_packed_typed_array_set_type_from_array_element(&_pandemonium_packed_typed_array, (const pandemonium_variant *)&p_array);
}
void PackedTypedArray::set_type_from(const PackedTypedArray &p_array) {
	Pandemonium::api->pandemonium_packed_typed_array_set_type_from(&_pandemonium_packed_typed_array, (const pandemonium_packed_typed_array *)&p_array);
}

bool PackedTypedArray::validate_type_name(const StringName &p_type_name) const {
	return Pandemonium::api->pandemonium_packed_typed_array_validate_type_name(&_pandemonium_packed_typed_array, (const pandemonium_string_name *)&p_type_name);
}
bool PackedTypedArray::validate_object_type_name(const StringName &p_type_name) const {
	return Pandemonium::api->pandemonium_packed_typed_array_validate_object_type_name(&_pandemonium_packed_typed_array, (const pandemonium_string_name *)&p_type_name);
}
bool PackedTypedArray::can_take_variant(const Variant &p_value) const {
	return Pandemonium::api->pandemonium_packed_typed_array_can_take_variant(&_pandemonium_packed_typed_array, (const pandemonium_variant *)&p_value);
}

PackedTypedArray::PackedTypedArray() {
	Pandemonium::api->pandemonium_packed_typed_array_new(&_pandemonium_packed_typed_array);
}
PackedTypedArray::PackedTypedArray(const PackedTypedArray &other) {
	Pandemonium::api->pandemonium_packed_typed_array_new_copy(&_pandemonium_packed_typed_array, &other._pandemonium_packed_typed_array);
}
PackedTypedArray::PackedTypedArray(const StringName &p_type_name, const Variant &p_from) {
	// Constructor is not exposed directly
	Pandemonium::api->pandemonium_packed_typed_array_new(&_pandemonium_packed_typed_array);
	set_type_from_name(p_type_name);
	append_from(p_from);
}
PackedTypedArray::PackedTypedArray(const StringName &p_type_name, const Variant &p_from, const IntType p_int_type) {
	// Constructor is not exposed directly
	Pandemonium::api->pandemonium_packed_typed_array_new(&_pandemonium_packed_typed_array);
	set_type_from_name(p_type_name);
	set_int_type(p_int_type);
	append_from(p_from);
}

PackedTypedArray::PackedTypedArray(const PoolByteArray &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_byte_array(&_pandemonium_packed_typed_array, (pandemonium_pool_byte_array *)&a);
}
PackedTypedArray::PackedTypedArray(const PoolIntArray &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_int_array(&_pandemonium_packed_typed_array, (pandemonium_pool_int_array *)&a);
}
PackedTypedArray::PackedTypedArray(const PoolRealArray &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_real_array(&_pandemonium_packed_typed_array, (pandemonium_pool_real_array *)&a);
}
PackedTypedArray::PackedTypedArray(const PoolStringArray &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_string_array(&_pandemonium_packed_typed_array, (pandemonium_pool_string_array *)&a);
}
PackedTypedArray::PackedTypedArray(const PoolVector2Array &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_vector2_array(&_pandemonium_packed_typed_array, (pandemonium_pool_vector2_array *)&a);
}
PackedTypedArray::PackedTypedArray(const PoolVector2iArray &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_vector2i_array(&_pandemonium_packed_typed_array, (pandemonium_pool_vector2i_array *)&a);
}
PackedTypedArray::PackedTypedArray(const PoolVector3Array &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_vector3_array(&_pandemonium_packed_typed_array, (pandemonium_pool_vector3_array *)&a);
}
PackedTypedArray::PackedTypedArray(const PoolVector3iArray &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_vector3i_array(&_pandemonium_packed_typed_array, (pandemonium_pool_vector3i_array *)&a);
}
PackedTypedArray::PackedTypedArray(const PoolVector4Array &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_vector4_array(&_pandemonium_packed_typed_array, (pandemonium_pool_vector4_array *)&a);
}
PackedTypedArray::PackedTypedArray(const PoolVector4iArray &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_vector4i_array(&_pandemonium_packed_typed_array, (pandemonium_pool_vector4i_array *)&a);
}
PackedTypedArray::PackedTypedArray(const PoolColorArray &a) {
	Pandemonium::api->pandemonium_packed_typed_array_new_pool_color_array(&_pandemonium_packed_typed_array, (pandemonium_pool_color_array *)&a);
}

PackedTypedArray::~PackedTypedArray() {
	Pandemonium::api->pandemonium_packed_typed_array_destroy(&_pandemonium_packed_typed_array);
}
