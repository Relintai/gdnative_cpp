/*************************************************************************/
/*  PoolArrays.cpp                                                       */
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

#include "pool_arrays.h"
#include "color.h"
#include "defs.h"
#include "pandemonium_global.h"
#include "ustring.h"
#include "vector2.h"
#include "vector2i.h"
#include "vector3.h"

#include <gdn/pool_arrays.h>



PoolByteArray::PoolByteArray() {
	Pandemonium::api->pandemonium_pool_byte_array_new(&_pandemonium_array);
}

PoolByteArray::PoolByteArray(const PoolByteArray &p_other) {
	Pandemonium::api->pandemonium_pool_byte_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolByteArray &PoolByteArray::operator=(const PoolByteArray &p_other) {
	Pandemonium::api->pandemonium_pool_byte_array_destroy(&_pandemonium_array);
	Pandemonium::api->pandemonium_pool_byte_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolByteArray::PoolByteArray(const Array &array) {
	Pandemonium::api->pandemonium_pool_byte_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolByteArray::Read PoolByteArray::read() const {
	Read read;
	read._read_access = Pandemonium::api->pandemonium_pool_byte_array_read(&_pandemonium_array);
	return read;
}

PoolByteArray::Write PoolByteArray::write() {
	Write write;
	write._write_access = Pandemonium::api->pandemonium_pool_byte_array_write(&_pandemonium_array);
	return write;
}

void PoolByteArray::append(const uint8_t data) {
	Pandemonium::api->pandemonium_pool_byte_array_append(&_pandemonium_array, data);
}

void PoolByteArray::append_array(const PoolByteArray &array) {
	Pandemonium::api->pandemonium_pool_byte_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolByteArray::insert(const int idx, const uint8_t data) {
	return Pandemonium::api->pandemonium_pool_byte_array_insert(&_pandemonium_array, idx, data);
}

void PoolByteArray::invert() {
	Pandemonium::api->pandemonium_pool_byte_array_invert(&_pandemonium_array);
}

void PoolByteArray::push_back(const uint8_t data) {
	Pandemonium::api->pandemonium_pool_byte_array_push_back(&_pandemonium_array, data);
}

void PoolByteArray::remove(const int idx) {
	Pandemonium::api->pandemonium_pool_byte_array_remove(&_pandemonium_array, idx);
}

void PoolByteArray::resize(const int size) {
	Pandemonium::api->pandemonium_pool_byte_array_resize(&_pandemonium_array, size);
}

void PoolByteArray::set(const int idx, const uint8_t data) {
	Pandemonium::api->pandemonium_pool_byte_array_set(&_pandemonium_array, idx, data);
}

uint8_t PoolByteArray::operator[](const int idx) {
	return Pandemonium::api->pandemonium_pool_byte_array_get(&_pandemonium_array, idx);
}

int PoolByteArray::size() const {
	return Pandemonium::api->pandemonium_pool_byte_array_size(&_pandemonium_array);
}

PoolByteArray::~PoolByteArray() {
	Pandemonium::api->pandemonium_pool_byte_array_destroy(&_pandemonium_array);
}

PoolIntArray::PoolIntArray() {
	Pandemonium::api->pandemonium_pool_int_array_new(&_pandemonium_array);
}

PoolIntArray::PoolIntArray(const PoolIntArray &p_other) {
	Pandemonium::api->pandemonium_pool_int_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolIntArray &PoolIntArray::operator=(const PoolIntArray &p_other) {
	Pandemonium::api->pandemonium_pool_int_array_destroy(&_pandemonium_array);
	Pandemonium::api->pandemonium_pool_int_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolIntArray::PoolIntArray(const Array &array) {
	Pandemonium::api->pandemonium_pool_int_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolIntArray::Read PoolIntArray::read() const {
	Read read;
	read._read_access = Pandemonium::api->pandemonium_pool_int_array_read(&_pandemonium_array);
	return read;
}

PoolIntArray::Write PoolIntArray::write() {
	Write write;
	write._write_access = Pandemonium::api->pandemonium_pool_int_array_write(&_pandemonium_array);
	return write;
}

void PoolIntArray::append(const int data) {
	Pandemonium::api->pandemonium_pool_int_array_append(&_pandemonium_array, data);
}

void PoolIntArray::append_array(const PoolIntArray &array) {
	Pandemonium::api->pandemonium_pool_int_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolIntArray::insert(const int idx, const int data) {
	return Pandemonium::api->pandemonium_pool_int_array_insert(&_pandemonium_array, idx, data);
}

void PoolIntArray::invert() {
	Pandemonium::api->pandemonium_pool_int_array_invert(&_pandemonium_array);
}

void PoolIntArray::push_back(const int data) {
	Pandemonium::api->pandemonium_pool_int_array_push_back(&_pandemonium_array, data);
}

void PoolIntArray::remove(const int idx) {
	Pandemonium::api->pandemonium_pool_int_array_remove(&_pandemonium_array, idx);
}

void PoolIntArray::resize(const int size) {
	Pandemonium::api->pandemonium_pool_int_array_resize(&_pandemonium_array, size);
}

void PoolIntArray::set(const int idx, const int data) {
	Pandemonium::api->pandemonium_pool_int_array_set(&_pandemonium_array, idx, data);
}

int PoolIntArray::operator[](const int idx) {
	return Pandemonium::api->pandemonium_pool_int_array_get(&_pandemonium_array, idx);
}

int PoolIntArray::size() const {
	return Pandemonium::api->pandemonium_pool_int_array_size(&_pandemonium_array);
}

PoolIntArray::~PoolIntArray() {
	Pandemonium::api->pandemonium_pool_int_array_destroy(&_pandemonium_array);
}

PoolRealArray::PoolRealArray() {
	Pandemonium::api->pandemonium_pool_real_array_new(&_pandemonium_array);
}

PoolRealArray::PoolRealArray(const PoolRealArray &p_other) {
	Pandemonium::api->pandemonium_pool_real_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolRealArray &PoolRealArray::operator=(const PoolRealArray &p_other) {
	Pandemonium::api->pandemonium_pool_real_array_destroy(&_pandemonium_array);
	Pandemonium::api->pandemonium_pool_real_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolRealArray::Read PoolRealArray::read() const {
	Read read;
	read._read_access = Pandemonium::api->pandemonium_pool_real_array_read(&_pandemonium_array);
	return read;
}

PoolRealArray::Write PoolRealArray::write() {
	Write write;
	write._write_access = Pandemonium::api->pandemonium_pool_real_array_write(&_pandemonium_array);
	return write;
}

PoolRealArray::PoolRealArray(const Array &array) {
	Pandemonium::api->pandemonium_pool_real_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

void PoolRealArray::append(const real_t data) {
	Pandemonium::api->pandemonium_pool_real_array_append(&_pandemonium_array, data);
}

void PoolRealArray::append_array(const PoolRealArray &array) {
	Pandemonium::api->pandemonium_pool_real_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolRealArray::insert(const int idx, const real_t data) {
	return Pandemonium::api->pandemonium_pool_real_array_insert(&_pandemonium_array, idx, data);
}

void PoolRealArray::invert() {
	Pandemonium::api->pandemonium_pool_real_array_invert(&_pandemonium_array);
}

void PoolRealArray::push_back(const real_t data) {
	Pandemonium::api->pandemonium_pool_real_array_push_back(&_pandemonium_array, data);
}

void PoolRealArray::remove(const int idx) {
	Pandemonium::api->pandemonium_pool_real_array_remove(&_pandemonium_array, idx);
}

void PoolRealArray::resize(const int size) {
	Pandemonium::api->pandemonium_pool_real_array_resize(&_pandemonium_array, size);
}

void PoolRealArray::set(const int idx, const real_t data) {
	Pandemonium::api->pandemonium_pool_real_array_set(&_pandemonium_array, idx, data);
}

real_t PoolRealArray::operator[](const int idx) {
	return Pandemonium::api->pandemonium_pool_real_array_get(&_pandemonium_array, idx);
}

int PoolRealArray::size() const {
	return Pandemonium::api->pandemonium_pool_real_array_size(&_pandemonium_array);
}

PoolRealArray::~PoolRealArray() {
	Pandemonium::api->pandemonium_pool_real_array_destroy(&_pandemonium_array);
}

PoolStringArray::PoolStringArray() {
	Pandemonium::api->pandemonium_pool_string_array_new(&_pandemonium_array);
}

PoolStringArray::PoolStringArray(const PoolStringArray &p_other) {
	Pandemonium::api->pandemonium_pool_string_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolStringArray &PoolStringArray::operator=(const PoolStringArray &p_other) {
	Pandemonium::api->pandemonium_pool_string_array_destroy(&_pandemonium_array);
	Pandemonium::api->pandemonium_pool_string_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolStringArray::PoolStringArray(const Array &array) {
	Pandemonium::api->pandemonium_pool_string_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolStringArray::Read PoolStringArray::read() const {
	Read read;
	read._read_access = Pandemonium::api->pandemonium_pool_string_array_read(&_pandemonium_array);
	return read;
}

PoolStringArray::Write PoolStringArray::write() {
	Write write;
	write._write_access = Pandemonium::api->pandemonium_pool_string_array_write(&_pandemonium_array);
	return write;
}

void PoolStringArray::append(const String &data) {
	Pandemonium::api->pandemonium_pool_string_array_append(&_pandemonium_array, (pandemonium_string *)&data);
}

void PoolStringArray::append_array(const PoolStringArray &array) {
	Pandemonium::api->pandemonium_pool_string_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolStringArray::insert(const int idx, const String &data) {
	return Pandemonium::api->pandemonium_pool_string_array_insert(&_pandemonium_array, idx, (pandemonium_string *)&data);
}

void PoolStringArray::invert() {
	Pandemonium::api->pandemonium_pool_string_array_invert(&_pandemonium_array);
}

void PoolStringArray::push_back(const String &data) {
	Pandemonium::api->pandemonium_pool_string_array_push_back(&_pandemonium_array, (pandemonium_string *)&data);
}

void PoolStringArray::remove(const int idx) {
	Pandemonium::api->pandemonium_pool_string_array_remove(&_pandemonium_array, idx);
}

void PoolStringArray::resize(const int size) {
	Pandemonium::api->pandemonium_pool_string_array_resize(&_pandemonium_array, size);
}

void PoolStringArray::set(const int idx, const String &data) {
	Pandemonium::api->pandemonium_pool_string_array_set(&_pandemonium_array, idx, (pandemonium_string *)&data);
}

const String PoolStringArray::operator[](const int idx) {
	String s;
	pandemonium_string str = Pandemonium::api->pandemonium_pool_string_array_get(&_pandemonium_array, idx);
	Pandemonium::api->pandemonium_string_new_copy((pandemonium_string *)&s, &str);
	Pandemonium::api->pandemonium_string_destroy(&str);
	return s;
}

int PoolStringArray::size() const {
	return Pandemonium::api->pandemonium_pool_string_array_size(&_pandemonium_array);
}

PoolStringArray::~PoolStringArray() {
	Pandemonium::api->pandemonium_pool_string_array_destroy(&_pandemonium_array);
}

PoolVector2Array::PoolVector2Array() {
	Pandemonium::api->pandemonium_pool_vector2_array_new(&_pandemonium_array);
}

PoolVector2Array::PoolVector2Array(const PoolVector2Array &p_other) {
	Pandemonium::api->pandemonium_pool_vector2_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolVector2Array &PoolVector2Array::operator=(const PoolVector2Array &p_other) {
	Pandemonium::api->pandemonium_pool_vector2_array_destroy(&_pandemonium_array);
	Pandemonium::api->pandemonium_pool_vector2_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolVector2Array::PoolVector2Array(const Array &array) {
	Pandemonium::api->pandemonium_pool_vector2_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolVector2Array::Read PoolVector2Array::read() const {
	Read read;
	read._read_access = Pandemonium::api->pandemonium_pool_vector2_array_read(&_pandemonium_array);
	return read;
}

PoolVector2Array::Write PoolVector2Array::write() {
	Write write;
	write._write_access = Pandemonium::api->pandemonium_pool_vector2_array_write(&_pandemonium_array);
	return write;
}

void PoolVector2Array::append(const Vector2 &data) {
	Pandemonium::api->pandemonium_pool_vector2_array_append(&_pandemonium_array, (pandemonium_vector2 *)&data);
}

void PoolVector2Array::append_array(const PoolVector2Array &array) {
	Pandemonium::api->pandemonium_pool_vector2_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolVector2Array::insert(const int idx, const Vector2 &data) {
	return Pandemonium::api->pandemonium_pool_vector2_array_insert(&_pandemonium_array, idx, (pandemonium_vector2 *)&data);
}

void PoolVector2Array::invert() {
	Pandemonium::api->pandemonium_pool_vector2_array_invert(&_pandemonium_array);
}

void PoolVector2Array::push_back(const Vector2 &data) {
	Pandemonium::api->pandemonium_pool_vector2_array_push_back(&_pandemonium_array, (pandemonium_vector2 *)&data);
}

void PoolVector2Array::remove(const int idx) {
	Pandemonium::api->pandemonium_pool_vector2_array_remove(&_pandemonium_array, idx);
}

void PoolVector2Array::resize(const int size) {
	Pandemonium::api->pandemonium_pool_vector2_array_resize(&_pandemonium_array, size);
}

void PoolVector2Array::set(const int idx, const Vector2 &data) {
	Pandemonium::api->pandemonium_pool_vector2_array_set(&_pandemonium_array, idx, (pandemonium_vector2 *)&data);
}

const Vector2 PoolVector2Array::operator[](const int idx) {
	Vector2 v;
	*(pandemonium_vector2 *)&v = Pandemonium::api->pandemonium_pool_vector2_array_get(&_pandemonium_array, idx);
	return v;
}

int PoolVector2Array::size() const {
	return Pandemonium::api->pandemonium_pool_vector2_array_size(&_pandemonium_array);
}

PoolVector2Array::~PoolVector2Array() {
	Pandemonium::api->pandemonium_pool_vector2_array_destroy(&_pandemonium_array);
}

PoolVector2iArray::PoolVector2iArray() {
	Pandemonium::api->pandemonium_pool_vector2i_array_new(&_pandemonium_array);
}

PoolVector2iArray::PoolVector2iArray(const PoolVector2iArray &p_other) {
	Pandemonium::api->pandemonium_pool_vector2i_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolVector2iArray &PoolVector2iArray::operator=(const PoolVector2iArray &p_other) {
	Pandemonium::api->pandemonium_pool_vector2i_array_destroy(&_pandemonium_array);
	Pandemonium::api->pandemonium_pool_vector2i_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolVector2iArray::PoolVector2iArray(const Array &array) {
	Pandemonium::api->pandemonium_pool_vector2i_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolVector2iArray::Read PoolVector2iArray::read() const {
	Read read;
	read._read_access = Pandemonium::api->pandemonium_pool_vector2i_array_read(&_pandemonium_array);
	return read;
}

PoolVector2iArray::Write PoolVector2iArray::write() {
	Write write;
	write._write_access = Pandemonium::api->pandemonium_pool_vector2i_array_write(&_pandemonium_array);
	return write;
}

void PoolVector2iArray::append(const Vector2i &data) {
	Pandemonium::api->pandemonium_pool_vector2i_array_append(&_pandemonium_array, (pandemonium_vector2i *)&data);
}

void PoolVector2iArray::append_array(const PoolVector2iArray &array) {
	Pandemonium::api->pandemonium_pool_vector2i_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolVector2iArray::insert(const int idx, const Vector2i &data) {
	return Pandemonium::api->pandemonium_pool_vector2i_array_insert(&_pandemonium_array, idx, (pandemonium_vector2i *)&data);
}

void PoolVector2iArray::invert() {
	Pandemonium::api->pandemonium_pool_vector2i_array_invert(&_pandemonium_array);
}

void PoolVector2iArray::push_back(const Vector2i &data) {
	Pandemonium::api->pandemonium_pool_vector2i_array_push_back(&_pandemonium_array, (pandemonium_vector2i *)&data);
}

void PoolVector2iArray::remove(const int idx) {
	Pandemonium::api->pandemonium_pool_vector2i_array_remove(&_pandemonium_array, idx);
}

void PoolVector2iArray::resize(const int size) {
	Pandemonium::api->pandemonium_pool_vector2i_array_resize(&_pandemonium_array, size);
}

void PoolVector2iArray::set(const int idx, const Vector2i &data) {
	Pandemonium::api->pandemonium_pool_vector2i_array_set(&_pandemonium_array, idx, (pandemonium_vector2i *)&data);
}

const Vector2i PoolVector2iArray::operator[](const int idx) {
	Vector2i v;
	*(pandemonium_vector2i *)&v = Pandemonium::api->pandemonium_pool_vector2i_array_get(&_pandemonium_array, idx);
	return v;
}

int PoolVector2iArray::size() const {
	return Pandemonium::api->pandemonium_pool_vector2i_array_size(&_pandemonium_array);
}

PoolVector2iArray::~PoolVector2iArray() {
	Pandemonium::api->pandemonium_pool_vector2i_array_destroy(&_pandemonium_array);
}

PoolVector3Array::PoolVector3Array() {
	Pandemonium::api->pandemonium_pool_vector3_array_new(&_pandemonium_array);
}

PoolVector3Array::PoolVector3Array(const PoolVector3Array &p_other) {
	Pandemonium::api->pandemonium_pool_vector3_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolVector3Array &PoolVector3Array::operator=(const PoolVector3Array &p_other) {
	Pandemonium::api->pandemonium_pool_vector3_array_destroy(&_pandemonium_array);
	Pandemonium::api->pandemonium_pool_vector3_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolVector3Array::PoolVector3Array(const Array &array) {
	Pandemonium::api->pandemonium_pool_vector3_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolVector3Array::Read PoolVector3Array::read() const {
	Read read;
	read._read_access = Pandemonium::api->pandemonium_pool_vector3_array_read(&_pandemonium_array);
	return read;
}

PoolVector3Array::Write PoolVector3Array::write() {
	Write write;
	write._write_access = Pandemonium::api->pandemonium_pool_vector3_array_write(&_pandemonium_array);
	return write;
}

void PoolVector3Array::append(const Vector3 &data) {
	Pandemonium::api->pandemonium_pool_vector3_array_append(&_pandemonium_array, (pandemonium_vector3 *)&data);
}

void PoolVector3Array::append_array(const PoolVector3Array &array) {
	Pandemonium::api->pandemonium_pool_vector3_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolVector3Array::insert(const int idx, const Vector3 &data) {
	return Pandemonium::api->pandemonium_pool_vector3_array_insert(&_pandemonium_array, idx, (pandemonium_vector3 *)&data);
}

void PoolVector3Array::invert() {
	Pandemonium::api->pandemonium_pool_vector3_array_invert(&_pandemonium_array);
}

void PoolVector3Array::push_back(const Vector3 &data) {
	Pandemonium::api->pandemonium_pool_vector3_array_push_back(&_pandemonium_array, (pandemonium_vector3 *)&data);
}

void PoolVector3Array::remove(const int idx) {
	Pandemonium::api->pandemonium_pool_vector3_array_remove(&_pandemonium_array, idx);
}

void PoolVector3Array::resize(const int size) {
	Pandemonium::api->pandemonium_pool_vector3_array_resize(&_pandemonium_array, size);
}

void PoolVector3Array::set(const int idx, const Vector3 &data) {
	Pandemonium::api->pandemonium_pool_vector3_array_set(&_pandemonium_array, idx, (pandemonium_vector3 *)&data);
}

const Vector3 PoolVector3Array::operator[](const int idx) {
	Vector3 v;
	*(pandemonium_vector3 *)&v = Pandemonium::api->pandemonium_pool_vector3_array_get(&_pandemonium_array, idx);
	return v;
}

int PoolVector3Array::size() const {
	return Pandemonium::api->pandemonium_pool_vector3_array_size(&_pandemonium_array);
}

PoolVector3Array::~PoolVector3Array() {
	Pandemonium::api->pandemonium_pool_vector3_array_destroy(&_pandemonium_array);
}

PoolColorArray::PoolColorArray() {
	Pandemonium::api->pandemonium_pool_color_array_new(&_pandemonium_array);
}

PoolColorArray::PoolColorArray(const PoolColorArray &p_other) {
	Pandemonium::api->pandemonium_pool_color_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
}

PoolColorArray &PoolColorArray::operator=(const PoolColorArray &p_other) {
	Pandemonium::api->pandemonium_pool_color_array_destroy(&_pandemonium_array);
	Pandemonium::api->pandemonium_pool_color_array_new_copy(&_pandemonium_array, &p_other._pandemonium_array);
	return *this;
}

PoolColorArray::PoolColorArray(const Array &array) {
	Pandemonium::api->pandemonium_pool_color_array_new_with_array(&_pandemonium_array, (pandemonium_array *)&array);
}

PoolColorArray::Read PoolColorArray::read() const {
	Read read;
	read._read_access = Pandemonium::api->pandemonium_pool_color_array_read(&_pandemonium_array);
	return read;
}

PoolColorArray::Write PoolColorArray::write() {
	Write write;
	write._write_access = Pandemonium::api->pandemonium_pool_color_array_write(&_pandemonium_array);
	return write;
}

void PoolColorArray::append(const Color &data) {
	Pandemonium::api->pandemonium_pool_color_array_append(&_pandemonium_array, (pandemonium_color *)&data);
}

void PoolColorArray::append_array(const PoolColorArray &array) {
	Pandemonium::api->pandemonium_pool_color_array_append_array(&_pandemonium_array, &array._pandemonium_array);
}

int PoolColorArray::insert(const int idx, const Color &data) {
	return Pandemonium::api->pandemonium_pool_color_array_insert(&_pandemonium_array, idx, (pandemonium_color *)&data);
}

void PoolColorArray::invert() {
	Pandemonium::api->pandemonium_pool_color_array_invert(&_pandemonium_array);
}

void PoolColorArray::push_back(const Color &data) {
	Pandemonium::api->pandemonium_pool_color_array_push_back(&_pandemonium_array, (pandemonium_color *)&data);
}

void PoolColorArray::remove(const int idx) {
	Pandemonium::api->pandemonium_pool_color_array_remove(&_pandemonium_array, idx);
}

void PoolColorArray::resize(const int size) {
	Pandemonium::api->pandemonium_pool_color_array_resize(&_pandemonium_array, size);
}

void PoolColorArray::set(const int idx, const Color &data) {
	Pandemonium::api->pandemonium_pool_color_array_set(&_pandemonium_array, idx, (pandemonium_color *)&data);
}

const Color PoolColorArray::operator[](const int idx) {
	Color v;
	*(pandemonium_color *)&v = Pandemonium::api->pandemonium_pool_color_array_get(&_pandemonium_array, idx);
	return v;
}

int PoolColorArray::size() const {
	return Pandemonium::api->pandemonium_pool_color_array_size(&_pandemonium_array);
}

PoolColorArray::~PoolColorArray() {
	Pandemonium::api->pandemonium_pool_color_array_destroy(&_pandemonium_array);
}


