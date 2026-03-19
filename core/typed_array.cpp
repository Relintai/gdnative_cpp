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

#include "typed_array.h"
#include "pandemonium_global.h"
#include "ustring.h"
#include "variant.h"
#include "string_name.h"

#include <cstdlib>

class Object;

const Variant &TypedArray::operator[](const int idx) const {
	const pandemonium_variant *v = Pandemonium::api->pandemonium_typed_array_operator_index_const((const pandemonium_typed_array *)&_pandemonium_typed_array, idx);
	return *reinterpret_cast<const Variant *>(v);
}

bool TypedArray::set(int p_idx, const Variant &p_value) {
	return Pandemonium::api->pandemonium_typed_array_set(&_pandemonium_typed_array, p_idx, (const pandemonium_variant *)&p_value);
}
const Variant TypedArray::get(int p_idx) const {
	pandemonium_variant v = Pandemonium::api->pandemonium_typed_array_get(&_pandemonium_typed_array, p_idx);
	return Variant(v);
}

int TypedArray::size() const {
	return Pandemonium::api->pandemonium_typed_array_size(&_pandemonium_typed_array);
}
bool TypedArray::empty() const {
	return Pandemonium::api->pandemonium_typed_array_empty(&_pandemonium_typed_array);
}
void TypedArray::clear() {
	Pandemonium::api->pandemonium_typed_array_clear(&_pandemonium_typed_array);
}

bool TypedArray::deep_equal(const TypedArray &p_array, const int p_recursion_count) const {
	return Pandemonium::api->pandemonium_typed_array_deep_equal_recursion_count(&_pandemonium_typed_array, &p_array._pandemonium_typed_array, p_recursion_count);
}
bool TypedArray::deep_equal_approx(const TypedArray &p_array, const int p_recursion_count) const {
	return Pandemonium::api->pandemonium_typed_array_deep_equal_approx_recursion_count(&_pandemonium_typed_array, &p_array._pandemonium_typed_array, p_recursion_count);
}
bool TypedArray::operator==(const TypedArray &p_array) {
	return Pandemonium::api->pandemonium_typed_array_operator_equals(&_pandemonium_typed_array, &p_array._pandemonium_typed_array);
}

uint32_t TypedArray::hash() const {
	return Pandemonium::api->pandemonium_typed_array_hash(&_pandemonium_typed_array);
}

TypedArray &TypedArray::operator=(const TypedArray &other) {
	Pandemonium::api->pandemonium_typed_array_destroy(&_pandemonium_typed_array);
	Pandemonium::api->pandemonium_typed_array_new_copy(&_pandemonium_typed_array, &other._pandemonium_typed_array);
	return *this;
}

void TypedArray::push_back(const Variant &v) {
	Pandemonium::api->pandemonium_typed_array_push_back(&_pandemonium_typed_array, (pandemonium_variant *)&v);
}
void TypedArray::append(const Variant &v) {
	Pandemonium::api->pandemonium_typed_array_append(&_pandemonium_typed_array, (pandemonium_variant *)&v);
}
void TypedArray::append_array(const TypedArray &p_array) {
	Pandemonium::api->pandemonium_typed_array_append_array(&_pandemonium_typed_array, &p_array._pandemonium_typed_array);
}
void TypedArray::append_from(const Variant &p_array) {
	Pandemonium::api->pandemonium_typed_array_append_from(&_pandemonium_typed_array, (const pandemonium_variant *)&p_array);
}
void TypedArray::resize(const int size) {
	Pandemonium::api->pandemonium_typed_array_resize(&_pandemonium_typed_array, size);
}

void TypedArray::insert(const int pos, const Variant &value) {
	Pandemonium::api->pandemonium_typed_array_insert(&_pandemonium_typed_array, pos, (pandemonium_variant *)&value);
}
void TypedArray::remove(const int idx) {
	Pandemonium::api->pandemonium_typed_array_remove(&_pandemonium_typed_array, idx);
}
void TypedArray::fill(const Variant &p_value) {
	Pandemonium::api->pandemonium_typed_array_fill(&_pandemonium_typed_array, (pandemonium_variant *)&p_value);
}

Variant TypedArray::front() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_typed_array_front(&_pandemonium_typed_array);
	return Variant(v);
}
Variant TypedArray::back() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_typed_array_back(&_pandemonium_typed_array);
	return Variant(v);
}

void TypedArray::sort() {
	Pandemonium::api->pandemonium_typed_array_sort(&_pandemonium_typed_array);
}
void TypedArray::sort_custom(Object *obj, const String &func) {
	Pandemonium::api->pandemonium_typed_array_sort_custom(&_pandemonium_typed_array, (pandemonium_object *)obj, (pandemonium_string *)&func);
}
void TypedArray::shuffle() {
	Pandemonium::api->pandemonium_typed_array_shuffle(&_pandemonium_typed_array);
}

int TypedArray::bsearch(const Variant &value, const bool before) {
	return Pandemonium::api->pandemonium_typed_array_bsearch(&_pandemonium_typed_array, (pandemonium_variant *)&value, before);
}
int TypedArray::bsearch_custom(const Variant &value, const Object *obj, const String &func, const bool before) {
	return Pandemonium::api->pandemonium_typed_array_bsearch_custom(&_pandemonium_typed_array, (pandemonium_variant *)&value,
			(pandemonium_object *)obj, (pandemonium_string *)&func, before);
}

void TypedArray::invert() {
	Pandemonium::api->pandemonium_typed_array_invert(&_pandemonium_typed_array);
}

int TypedArray::find(const Variant &what, const int from) const {
	return Pandemonium::api->pandemonium_typed_array_find_from(&_pandemonium_typed_array, (pandemonium_variant *)&what, from);
}
int TypedArray::rfind(const Variant &what, const int from) const {
	return Pandemonium::api->pandemonium_typed_array_rfind_from(&_pandemonium_typed_array, (pandemonium_variant *)&what, from);
}
int TypedArray::find_last(const Variant &what) const {
	return Pandemonium::api->pandemonium_typed_array_find_last(&_pandemonium_typed_array, (pandemonium_variant *)&what);
}
int TypedArray::count(const Variant &v) {
	return Pandemonium::api->pandemonium_typed_array_count(&_pandemonium_typed_array, (pandemonium_variant *)&v);
}
bool TypedArray::has(const Variant &what) const {
	return Pandemonium::api->pandemonium_typed_array_has(&_pandemonium_typed_array, (pandemonium_variant *)&what);
}

void TypedArray::erase(const Variant &v) {
	Pandemonium::api->pandemonium_typed_array_erase(&_pandemonium_typed_array, (pandemonium_variant *)&v);
}

void TypedArray::push_front(const Variant &v) {
	Pandemonium::api->pandemonium_typed_array_push_front(&_pandemonium_typed_array, (pandemonium_variant *)&v);
}

Variant TypedArray::pop_back() {
	pandemonium_variant v = Pandemonium::api->pandemonium_typed_array_pop_back(&_pandemonium_typed_array);
	return Variant(v);
}

Variant TypedArray::pop_front() {
	pandemonium_variant v = Pandemonium::api->pandemonium_typed_array_pop_front(&_pandemonium_typed_array);
	return Variant(v);
}
Variant TypedArray::pop_at(int p_pos) {
	pandemonium_variant v = Pandemonium::api->pandemonium_typed_array_pop_at(&_pandemonium_typed_array, p_pos);
	return Variant(v);
}

TypedArray TypedArray::duplicate(const bool deep) const {
	pandemonium_typed_array arr = Pandemonium::api->pandemonium_typed_array_duplicate_deep(&_pandemonium_typed_array, deep);
	return TypedArray(arr);
}

TypedArray TypedArray::slice(int p_begin, int p_end, int p_step, bool p_deep) const {
	pandemonium_typed_array arr = Pandemonium::api->pandemonium_typed_array_slice_step_deep(&_pandemonium_typed_array, p_begin, p_end, p_step, p_deep);
	return TypedArray(arr);
}

Variant TypedArray::max() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_typed_array_max(&_pandemonium_typed_array);
	return Variant(v);
}

Variant TypedArray::min() const {
	pandemonium_variant v = Pandemonium::api->pandemonium_typed_array_min(&_pandemonium_typed_array);
	return Variant(v);
}

String TypedArray::get_typename_string() const {
	pandemonium_string s = Pandemonium::api->pandemonium_typed_array_get_typename_string(&_pandemonium_typed_array);
	return String(s);
}

int TypedArray::get_variant_type() const {
	return Pandemonium::api->pandemonium_typed_array_get_variant_type(&_pandemonium_typed_array);
}
void TypedArray::set_variant_type(const int p_variant_type) {
	Pandemonium::api->pandemonium_typed_array_set_variant_type(&_pandemonium_typed_array, p_variant_type);
}

StringName TypedArray::get_object_class_name() const {
	pandemonium_string_name s = Pandemonium::api->pandemonium_typed_array_get_object_class_name(&_pandemonium_typed_array);
	return StringName(s);
}
void TypedArray::set_object_class_name(const StringName &p_object_type_name) {
	Pandemonium::api->pandemonium_typed_array_set_object_class_name(&_pandemonium_typed_array, (const pandemonium_string_name *)&p_object_type_name);
}

void TypedArray::set_type_from_name(const StringName &p_type_name) {
	Pandemonium::api->pandemonium_typed_array_set_type_from_name(&_pandemonium_typed_array, (const pandemonium_string_name *)&p_type_name);
}
void TypedArray::set_type_from_variant(const Variant &p_variant) {
	Pandemonium::api->pandemonium_typed_array_set_type_from_variant(&_pandemonium_typed_array, (const pandemonium_variant *)&p_variant);
}
void TypedArray::set_type_from_array_element(const Variant &p_array) {
	Pandemonium::api->pandemonium_typed_array_set_type_from_array_element(&_pandemonium_typed_array, (const pandemonium_variant *)&p_array);
}
void TypedArray::set_type_from(const TypedArray &p_array) {
	Pandemonium::api->pandemonium_typed_array_set_type_from(&_pandemonium_typed_array, (const pandemonium_typed_array *)&p_array);
}

bool TypedArray::validate_type_name(const StringName &p_type_name) const {
	return Pandemonium::api->pandemonium_typed_array_validate_type_name(&_pandemonium_typed_array, (const pandemonium_string_name *)&p_type_name);
}
bool TypedArray::validate_object_type_name(const StringName &p_type_name) const {
	return Pandemonium::api->pandemonium_typed_array_validate_object_type_name(&_pandemonium_typed_array, (const pandemonium_string_name *)&p_type_name);
}
bool TypedArray::can_take_variant(const Variant &p_value) const {
	return Pandemonium::api->pandemonium_typed_array_can_take_variant(&_pandemonium_typed_array, (const pandemonium_variant *)&p_value);
}

TypedArray::TypedArray() {
	Pandemonium::api->pandemonium_typed_array_new(&_pandemonium_typed_array);
}
TypedArray::TypedArray(const TypedArray &other) {
	Pandemonium::api->pandemonium_typed_array_new_copy(&_pandemonium_typed_array, &other._pandemonium_typed_array);
}
TypedArray::TypedArray(const StringName &p_type_name, const Variant &p_from) {
	// Constructor is not exposed directly
	Pandemonium::api->pandemonium_typed_array_new(&_pandemonium_typed_array);
	set_type_from_name(p_type_name);
	append_from(p_from);
}

TypedArray::TypedArray(const PoolByteArray &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_byte_array(&_pandemonium_typed_array, (pandemonium_pool_byte_array *)&a);
}
TypedArray::TypedArray(const PoolIntArray &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_int_array(&_pandemonium_typed_array, (pandemonium_pool_int_array *)&a);
}
TypedArray::TypedArray(const PoolRealArray &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_real_array(&_pandemonium_typed_array, (pandemonium_pool_real_array *)&a);
}
TypedArray::TypedArray(const PoolStringArray &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_string_array(&_pandemonium_typed_array, (pandemonium_pool_string_array *)&a);
}
TypedArray::TypedArray(const PoolVector2Array &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_vector2_array(&_pandemonium_typed_array, (pandemonium_pool_vector2_array *)&a);
}
TypedArray::TypedArray(const PoolVector2iArray &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_vector2i_array(&_pandemonium_typed_array, (pandemonium_pool_vector2i_array *)&a);
}
TypedArray::TypedArray(const PoolVector3Array &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_vector3_array(&_pandemonium_typed_array, (pandemonium_pool_vector3_array *)&a);
}
TypedArray::TypedArray(const PoolVector3iArray &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_vector3i_array(&_pandemonium_typed_array, (pandemonium_pool_vector3i_array *)&a);
}
TypedArray::TypedArray(const PoolVector4Array &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_vector4_array(&_pandemonium_typed_array, (pandemonium_pool_vector4_array *)&a);
}
TypedArray::TypedArray(const PoolVector4iArray &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_vector4i_array(&_pandemonium_typed_array, (pandemonium_pool_vector4i_array *)&a);
}
TypedArray::TypedArray(const PoolColorArray &a) {
	Pandemonium::api->pandemonium_typed_array_new_pool_color_array(&_pandemonium_typed_array, (pandemonium_pool_color_array *)&a);
}

TypedArray::~TypedArray() {
	Pandemonium::api->pandemonium_typed_array_destroy(&_pandemonium_typed_array);
}
