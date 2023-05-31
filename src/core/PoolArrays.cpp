/*************************************************************************/
/*  PoolArrays.cpp                                                       */
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

#include "PoolArrays.hpp"
#include "Color.hpp"
#include "Defs.hpp"
#include "GodotGlobal.hpp"
#include "String.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

#include <gdn/pool_arrays.h>

namespace godot {

PoolByteArray::PoolByteArray() {
	godot::api->pandemonium_pool_byte_array_new(&_pandemonium_array);
}

PoolByteArray::PoolByteArray(const PoolByteArray &p_other) {
	godot::api->pandemonium_pool_byte_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolByteArray &PoolByteArray::operator=(const PoolByteArray &p_other) {
	godot::api->pandemonium_pool_byte_array_destroy(&_pandemonium_array);
	godot::api->pandemonium_pool_byte_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolByteArray::PoolByteArray(const Array &array) {
	godot::api->pandemonium_pool_byte_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolByteArray::Read PoolByteArray::read() const {
	Read read;
	read._read_access = godot::api->pandemonium_pool_byte_array_read(&_pandemonium_array);
	return read;
}

PoolByteArray::Write PoolByteArray::write() {
	Write write;
	write._write_access = godot::api->pandemonium_pool_byte_array_write(&_pandemonium_array);
	return write;
}

void PoolByteArray::append(const uint8_t data) {
	godot::api->pandemonium_pool_byte_array_append(&_pandemonium_array, data);
}

void PoolByteArray::append_array(const PoolByteArray &array) {
	godot::api->pandemonium_pool_byte_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolByteArray::insert(const int idx, const uint8_t data) {
	return godot::api->pandemonium_pool_byte_array_insert(&_pandemonium_array, idx, data);
}

void PoolByteArray::invert() {
	godot::api->pandemonium_pool_byte_array_invert(&_pandemonium_array);
}

void PoolByteArray::push_back(const uint8_t data) {
	godot::api->pandemonium_pool_byte_array_push_back(&_pandemonium_array, data);
}

void PoolByteArray::remove(const int idx) {
	godot::api->pandemonium_pool_byte_array_remove(&_pandemonium_array, idx);
}

void PoolByteArray::resize(const int size) {
	godot::api->pandemonium_pool_byte_array_resize(&_pandemonium_array, size);
}

void PoolByteArray::set(const int idx, const uint8_t data) {
	godot::api->pandemonium_pool_byte_array_set(&_pandemonium_array, idx, data);
}

uint8_t PoolByteArray::operator[](const int idx) {
	return godot::api->pandemonium_pool_byte_array_get(&_pandemonium_array, idx);
}

int PoolByteArray::size() const {
	return godot::api->pandemonium_pool_byte_array_size(&_pandemonium_array);
}

PoolByteArray::~PoolByteArray() {
	godot::api->pandemonium_pool_byte_array_destroy(&_pandemonium_array);
}

PoolIntArray::PoolIntArray() {
	godot::api->pandemonium_pool_int_array_new(&_pandemonium_array);
}

PoolIntArray::PoolIntArray(const PoolIntArray &p_other) {
	godot::api->pandemonium_pool_int_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolIntArray &PoolIntArray::operator=(const PoolIntArray &p_other) {
	godot::api->pandemonium_pool_int_array_destroy(&_pandemonium_array);
	godot::api->pandemonium_pool_int_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolIntArray::PoolIntArray(const Array &array) {
	godot::api->pandemonium_pool_int_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolIntArray::Read PoolIntArray::read() const {
	Read read;
	read._read_access = godot::api->pandemonium_pool_int_array_read(&_pandemonium_array);
	return read;
}

PoolIntArray::Write PoolIntArray::write() {
	Write write;
	write._write_access = godot::api->pandemonium_pool_int_array_write(&_pandemonium_array);
	return write;
}

void PoolIntArray::append(const int data) {
	godot::api->pandemonium_pool_int_array_append(&_pandemonium_array, data);
}

void PoolIntArray::append_array(const PoolIntArray &array) {
	godot::api->pandemonium_pool_int_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolIntArray::insert(const int idx, const int data) {
	return godot::api->pandemonium_pool_int_array_insert(&_pandemonium_array, idx, data);
}

void PoolIntArray::invert() {
	godot::api->pandemonium_pool_int_array_invert(&_pandemonium_array);
}

void PoolIntArray::push_back(const int data) {
	godot::api->pandemonium_pool_int_array_push_back(&_pandemonium_array, data);
}

void PoolIntArray::remove(const int idx) {
	godot::api->pandemonium_pool_int_array_remove(&_pandemonium_array, idx);
}

void PoolIntArray::resize(const int size) {
	godot::api->pandemonium_pool_int_array_resize(&_pandemonium_array, size);
}

void PoolIntArray::set(const int idx, const int data) {
	godot::api->pandemonium_pool_int_array_set(&_pandemonium_array, idx, data);
}

int PoolIntArray::operator[](const int idx) {
	return godot::api->pandemonium_pool_int_array_get(&_pandemonium_array, idx);
}

int PoolIntArray::size() const {
	return godot::api->pandemonium_pool_int_array_size(&_pandemonium_array);
}

PoolIntArray::~PoolIntArray() {
	godot::api->pandemonium_pool_int_array_destroy(&_pandemonium_array);
}

PoolRealArray::PoolRealArray() {
	godot::api->pandemonium_pool_real_array_new(&_pandemonium_array);
}

PoolRealArray::PoolRealArray(const PoolRealArray &p_other) {
	godot::api->pandemonium_pool_real_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolRealArray &PoolRealArray::operator=(const PoolRealArray &p_other) {
	godot::api->pandemonium_pool_real_array_destroy(&_pandemonium_array);
	godot::api->pandemonium_pool_real_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolRealArray::Read PoolRealArray::read() const {
	Read read;
	read._read_access = godot::api->pandemonium_pool_real_array_read(&_pandemonium_array);
	return read;
}

PoolRealArray::Write PoolRealArray::write() {
	Write write;
	write._write_access = godot::api->pandemonium_pool_real_array_write(&_pandemonium_array);
	return write;
}

PoolRealArray::PoolRealArray(const Array &array) {
	godot::api->pandemonium_pool_real_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

void PoolRealArray::append(const real_t data) {
	godot::api->pandemonium_pool_real_array_append(&_pandemonium_array, data);
}

void PoolRealArray::append_array(const PoolRealArray &array) {
	godot::api->pandemonium_pool_real_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolRealArray::insert(const int idx, const real_t data) {
	return godot::api->pandemonium_pool_real_array_insert(&_pandemonium_array, idx, data);
}

void PoolRealArray::invert() {
	godot::api->pandemonium_pool_real_array_invert(&_pandemonium_array);
}

void PoolRealArray::push_back(const real_t data) {
	godot::api->pandemonium_pool_real_array_push_back(&_pandemonium_array, data);
}

void PoolRealArray::remove(const int idx) {
	godot::api->pandemonium_pool_real_array_remove(&_pandemonium_array, idx);
}

void PoolRealArray::resize(const int size) {
	godot::api->pandemonium_pool_real_array_resize(&_pandemonium_array, size);
}

void PoolRealArray::set(const int idx, const real_t data) {
	godot::api->pandemonium_pool_real_array_set(&_pandemonium_array, idx, data);
}

real_t PoolRealArray::operator[](const int idx) {
	return godot::api->pandemonium_pool_real_array_get(&_pandemonium_array, idx);
}

int PoolRealArray::size() const {
	return godot::api->pandemonium_pool_real_array_size(&_pandemonium_array);
}

PoolRealArray::~PoolRealArray() {
	godot::api->pandemonium_pool_real_array_destroy(&_pandemonium_array);
}

PoolStringArray::PoolStringArray() {
	godot::api->pandemonium_pool_string_array_new(&_pandemonium_array);
}

PoolStringArray::PoolStringArray(const PoolStringArray &p_other) {
	godot::api->pandemonium_pool_string_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolStringArray &PoolStringArray::operator=(const PoolStringArray &p_other) {
	godot::api->pandemonium_pool_string_array_destroy(&_pandemonium_array);
	godot::api->pandemonium_pool_string_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolStringArray::PoolStringArray(const Array &array) {
	godot::api->pandemonium_pool_string_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolStringArray::Read PoolStringArray::read() const {
	Read read;
	read._read_access = godot::api->pandemonium_pool_string_array_read(&_pandemonium_array);
	return read;
}

PoolStringArray::Write PoolStringArray::write() {
	Write write;
	write._write_access = godot::api->pandemonium_pool_string_array_write(&_pandemonium_array);
	return write;
}

void PoolStringArray::append(const String &data) {
	godot::api->pandemonium_pool_string_array_append(&_pandemonium_array, (pandemonium_string *)&data);
}

void PoolStringArray::append_array(const PoolStringArray &array) {
	godot::api->pandemonium_pool_string_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolStringArray::insert(const int idx, const String &data) {
	return godot::api->pandemonium_pool_string_array_insert(&_pandemonium_array, idx, (pandemonium_string *)&data);
}

void PoolStringArray::invert() {
	godot::api->pandemonium_pool_string_array_invert(&_pandemonium_array);
}

void PoolStringArray::push_back(const String &data) {
	godot::api->pandemonium_pool_string_array_push_back(&_pandemonium_array, (pandemonium_string *)&data);
}

void PoolStringArray::remove(const int idx) {
	godot::api->pandemonium_pool_string_array_remove(&_pandemonium_array, idx);
}

void PoolStringArray::resize(const int size) {
	godot::api->pandemonium_pool_string_array_resize(&_pandemonium_array, size);
}

void PoolStringArray::set(const int idx, const String &data) {
	godot::api->pandemonium_pool_string_array_set(&_pandemonium_array, idx, (pandemonium_string *)&data);
}

const String PoolStringArray::operator[](const int idx) {
	String s;
	pandemonium_string str = godot::api->pandemonium_pool_string_array_get(&_pandemonium_array, idx);
	godot::api->pandemonium_string_new_copy((pandemonium_string *)&s, &str);
	godot::api->pandemonium_string_destroy(&str);
	return s;
}

int PoolStringArray::size() const {
	return godot::api->pandemonium_pool_string_array_size(&_pandemonium_array);
}

PoolStringArray::~PoolStringArray() {
	godot::api->pandemonium_pool_string_array_destroy(&_pandemonium_array);
}

PoolVector2Array::PoolVector2Array() {
	godot::api->pandemonium_pool_vector2_array_new(&_pandemonium_array);
}

PoolVector2Array::PoolVector2Array(const PoolVector2Array &p_other) {
	godot::api->pandemonium_pool_vector2_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolVector2Array &PoolVector2Array::operator=(const PoolVector2Array &p_other) {
	godot::api->pandemonium_pool_vector2_array_destroy(&_pandemonium_array);
	godot::api->pandemonium_pool_vector2_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolVector2Array::PoolVector2Array(const Array &array) {
	godot::api->pandemonium_pool_vector2_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolVector2Array::Read PoolVector2Array::read() const {
	Read read;
	read._read_access = godot::api->pandemonium_pool_vector2_array_read(&_pandemonium_array);
	return read;
}

PoolVector2Array::Write PoolVector2Array::write() {
	Write write;
	write._write_access = godot::api->pandemonium_pool_vector2_array_write(&_pandemonium_array);
	return write;
}

void PoolVector2Array::append(const Vector2 &data) {
	godot::api->pandemonium_pool_vector2_array_append(&_pandemonium_array, (pandemonium_vector2 *)&data);
}

void PoolVector2Array::append_array(const PoolVector2Array &array) {
	godot::api->pandemonium_pool_vector2_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolVector2Array::insert(const int idx, const Vector2 &data) {
	return godot::api->pandemonium_pool_vector2_array_insert(&_pandemonium_array, idx, (pandemonium_vector2 *)&data);
}

void PoolVector2Array::invert() {
	godot::api->pandemonium_pool_vector2_array_invert(&_pandemonium_array);
}

void PoolVector2Array::push_back(const Vector2 &data) {
	godot::api->pandemonium_pool_vector2_array_push_back(&_pandemonium_array, (pandemonium_vector2 *)&data);
}

void PoolVector2Array::remove(const int idx) {
	godot::api->pandemonium_pool_vector2_array_remove(&_pandemonium_array, idx);
}

void PoolVector2Array::resize(const int size) {
	godot::api->pandemonium_pool_vector2_array_resize(&_pandemonium_array, size);
}

void PoolVector2Array::set(const int idx, const Vector2 &data) {
	godot::api->pandemonium_pool_vector2_array_set(&_pandemonium_array, idx, (pandemonium_vector2 *)&data);
}

const Vector2 PoolVector2Array::operator[](const int idx) {
	Vector2 v;
	*(pandemonium_vector2 *)&v = godot::api->pandemonium_pool_vector2_array_get(&_pandemonium_array, idx);
	return v;
}

int PoolVector2Array::size() const {
	return godot::api->pandemonium_pool_vector2_array_size(&_pandemonium_array);
}

PoolVector2Array::~PoolVector2Array() {
	godot::api->pandemonium_pool_vector2_array_destroy(&_pandemonium_array);
}

PoolVector3Array::PoolVector3Array() {
	godot::api->pandemonium_pool_vector3_array_new(&_pandemonium_array);
}

PoolVector3Array::PoolVector3Array(const PoolVector3Array &p_other) {
	godot::api->pandemonium_pool_vector3_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolVector3Array &PoolVector3Array::operator=(const PoolVector3Array &p_other) {
	godot::api->pandemonium_pool_vector3_array_destroy(&_pandemonium_array);
	godot::api->pandemonium_pool_vector3_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolVector3Array::PoolVector3Array(const Array &array) {
	godot::api->pandemonium_pool_vector3_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolVector3Array::Read PoolVector3Array::read() const {
	Read read;
	read._read_access = godot::api->pandemonium_pool_vector3_array_read(&_pandemonium_array);
	return read;
}

PoolVector3Array::Write PoolVector3Array::write() {
	Write write;
	write._write_access = godot::api->pandemonium_pool_vector3_array_write(&_pandemonium_array);
	return write;
}

void PoolVector3Array::append(const Vector3 &data) {
	godot::api->pandemonium_pool_vector3_array_append(&_pandemonium_array, (pandemonium_vector3 *)&data);
}

void PoolVector3Array::append_array(const PoolVector3Array &array) {
	godot::api->pandemonium_pool_vector3_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolVector3Array::insert(const int idx, const Vector3 &data) {
	return godot::api->pandemonium_pool_vector3_array_insert(&_pandemonium_array, idx, (pandemonium_vector3 *)&data);
}

void PoolVector3Array::invert() {
	godot::api->pandemonium_pool_vector3_array_invert(&_pandemonium_array);
}

void PoolVector3Array::push_back(const Vector3 &data) {
	godot::api->pandemonium_pool_vector3_array_push_back(&_pandemonium_array, (pandemonium_vector3 *)&data);
}

void PoolVector3Array::remove(const int idx) {
	godot::api->pandemonium_pool_vector3_array_remove(&_pandemonium_array, idx);
}

void PoolVector3Array::resize(const int size) {
	godot::api->pandemonium_pool_vector3_array_resize(&_pandemonium_array, size);
}

void PoolVector3Array::set(const int idx, const Vector3 &data) {
	godot::api->pandemonium_pool_vector3_array_set(&_pandemonium_array, idx, (pandemonium_vector3 *)&data);
}

const Vector3 PoolVector3Array::operator[](const int idx) {
	Vector3 v;
	*(pandemonium_vector3 *)&v = godot::api->pandemonium_pool_vector3_array_get(&_pandemonium_array, idx);
	return v;
}

int PoolVector3Array::size() const {
	return godot::api->pandemonium_pool_vector3_array_size(&_pandemonium_array);
}

PoolVector3Array::~PoolVector3Array() {
	godot::api->pandemonium_pool_vector3_array_destroy(&_pandemonium_array);
}

PoolColorArray::PoolColorArray() {
	godot::api->pandemonium_pool_color_array_new(&_pandemonium_array);
}

PoolColorArray::PoolColorArray(const PoolColorArray &p_other) {
	godot::api->pandemonium_pool_color_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolColorArray &PoolColorArray::operator=(const PoolColorArray &p_other) {
	godot::api->pandemonium_pool_color_array_destroy(&_pandemonium_array);
	godot::api->pandemonium_pool_color_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolColorArray::PoolColorArray(const Array &array) {
	godot::api->pandemonium_pool_color_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolColorArray::Read PoolColorArray::read() const {
	Read read;
	read._read_access = godot::api->pandemonium_pool_color_array_read(&_pandemonium_array);
	return read;
}

PoolColorArray::Write PoolColorArray::write() {
	Write write;
	write._write_access = godot::api->pandemonium_pool_color_array_write(&_pandemonium_array);
	return write;
}

void PoolColorArray::append(const Color &data) {
	godot::api->pandemonium_pool_color_array_append(&_pandemonium_array, (pandemonium_color *)&data);
}

void PoolColorArray::append_array(const PoolColorArray &array) {
	godot::api->pandemonium_pool_color_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolColorArray::insert(const int idx, const Color &data) {
	return godot::api->pandemonium_pool_color_array_insert(&_pandemonium_array, idx, (pandemonium_color *)&data);
}

void PoolColorArray::invert() {
	godot::api->pandemonium_pool_color_array_invert(&_pandemonium_array);
}

void PoolColorArray::push_back(const Color &data) {
	godot::api->pandemonium_pool_color_array_push_back(&_pandemonium_array, (pandemonium_color *)&data);
}

void PoolColorArray::remove(const int idx) {
	godot::api->pandemonium_pool_color_array_remove(&_pandemonium_array, idx);
}

void PoolColorArray::resize(const int size) {
	godot::api->pandemonium_pool_color_array_resize(&_pandemonium_array, size);
}

void PoolColorArray::set(const int idx, const Color &data) {
	godot::api->pandemonium_pool_color_array_set(&_pandemonium_array, idx, (pandemonium_color *)&data);
}

const Color PoolColorArray::operator[](const int idx) {
	Color v;
	*(pandemonium_color *)&v = godot::api->pandemonium_pool_color_array_get(&_pandemonium_array, idx);
	return v;
}

int PoolColorArray::size() const {
	return godot::api->pandemonium_pool_color_array_size(&_pandemonium_array);
}

PoolColorArray::~PoolColorArray() {
	godot::api->pandemonium_pool_color_array_destroy(&_pandemonium_array);
}

} // namespace godot
