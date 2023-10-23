/*************************************************************************/
/*  Variant.cpp                                                          */
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

#include "Variant.h"

#include <gdn/variant.h>

#include "CoreTypes.h"
#include "Defs.h"
#include "PandemoniumGlobal.h"
#include "Object.h"

namespace pandemonium {

Variant::Variant() {
	pandemonium::api->pandemonium_variant_new_nil(&_pandemonium_variant);
}

Variant::Variant(const Variant &v) {
	pandemonium::api->pandemonium_variant_new_copy(&_pandemonium_variant, &v._pandemonium_variant);
}

Variant::Variant(bool p_bool) {
	pandemonium::api->pandemonium_variant_new_bool(&_pandemonium_variant, p_bool);
}

Variant::Variant(signed int p_int) // real one
{
	pandemonium::api->pandemonium_variant_new_int(&_pandemonium_variant, p_int);
}

Variant::Variant(unsigned int p_int) {
	pandemonium::api->pandemonium_variant_new_uint(&_pandemonium_variant, p_int);
}

Variant::Variant(signed short p_short) // real one
{
	pandemonium::api->pandemonium_variant_new_int(&_pandemonium_variant, (int)p_short);
}

Variant::Variant(int64_t p_char) // real one
{
	pandemonium::api->pandemonium_variant_new_int(&_pandemonium_variant, p_char);
}

Variant::Variant(uint64_t p_char) {
	pandemonium::api->pandemonium_variant_new_uint(&_pandemonium_variant, p_char);
}

Variant::Variant(float p_float) {
	pandemonium::api->pandemonium_variant_new_real(&_pandemonium_variant, p_float);
}

Variant::Variant(double p_double) {
	pandemonium::api->pandemonium_variant_new_real(&_pandemonium_variant, p_double);
}

Variant::Variant(const String &p_string) {
	pandemonium::api->pandemonium_variant_new_string(&_pandemonium_variant, (pandemonium_string *)&p_string);
}

Variant::Variant(const StringName &p_string) {
	pandemonium::api->pandemonium_variant_new_string_name(&_pandemonium_variant, (pandemonium_string_name *)&p_string);
}

Variant::Variant(const char *const p_cstring) {
	String s = String(p_cstring);
	pandemonium::api->pandemonium_variant_new_string(&_pandemonium_variant, (pandemonium_string *)&s);
}

Variant::Variant(const wchar_t *p_wstring) {
	String s = p_wstring;
	pandemonium::api->pandemonium_variant_new_string(&_pandemonium_variant, (pandemonium_string *)&s);
}

Variant::Variant(const Vector2 &p_vector2) {
	pandemonium::api->pandemonium_variant_new_vector2(&_pandemonium_variant, (pandemonium_vector2 *)&p_vector2);
}

Variant::Variant(const Vector2i &p_vector2i) {
	pandemonium::api->pandemonium_variant_new_vector2i(&_pandemonium_variant, (pandemonium_vector2i *)&p_vector2i);
}

Variant::Variant(const Rect2 &p_rect2) {
	pandemonium::api->pandemonium_variant_new_rect2(&_pandemonium_variant, (pandemonium_rect2 *)&p_rect2);
}

Variant::Variant(const Rect2i &p_rect2i) {
	pandemonium::api->pandemonium_variant_new_rect2i(&_pandemonium_variant, (pandemonium_rect2i *)&p_rect2i);
}

Variant::Variant(const Vector3 &p_vector3) {
	pandemonium::api->pandemonium_variant_new_vector3(&_pandemonium_variant, (pandemonium_vector3 *)&p_vector3);
}

Variant::Variant(const Vector3i &p_vector3i) {
	pandemonium::api->pandemonium_variant_new_vector3i(&_pandemonium_variant, (pandemonium_vector3i *)&p_vector3i);
}

Variant::Variant(const Vector4 &p_vector4) {
	pandemonium::api->pandemonium_variant_new_vector4(&_pandemonium_variant, (pandemonium_vector4 *)&p_vector4);
}

Variant::Variant(const Vector4i &p_vector4i) {
	pandemonium::api->pandemonium_variant_new_vector4i(&_pandemonium_variant, (pandemonium_vector4i *)&p_vector4i);
}

Variant::Variant(const Plane &p_plane) {
	pandemonium::api->pandemonium_variant_new_plane(&_pandemonium_variant, (pandemonium_plane *)&p_plane);
}

Variant::Variant(const pandemonium::AABB &p_aabb) {
	pandemonium::api->pandemonium_variant_new_aabb(&_pandemonium_variant, (pandemonium_aabb *)&p_aabb);
}

Variant::Variant(const Quaternion &p_quaternion) {
	pandemonium::api->pandemonium_variant_new_quaternion(&_pandemonium_variant, (pandemonium_quaternion *)&p_quaternion);
}

Variant::Variant(const Basis &p_transform) {
	pandemonium::api->pandemonium_variant_new_basis(&_pandemonium_variant, (pandemonium_basis *)&p_transform);
}

Variant::Variant(const Transform2D &p_transform) {
	pandemonium::api->pandemonium_variant_new_transform2d(&_pandemonium_variant, (pandemonium_transform2d *)&p_transform);
}

Variant::Variant(const Transform &p_transform) {
	pandemonium::api->pandemonium_variant_new_transform(&_pandemonium_variant, (pandemonium_transform *)&p_transform);
}

Variant::Variant(const Projection &p_projection) {
	pandemonium::api->pandemonium_variant_new_projection(&_pandemonium_variant, (pandemonium_projection *)&p_projection);
}

Variant::Variant(const Color &p_color) {
	pandemonium::api->pandemonium_variant_new_color(&_pandemonium_variant, (pandemonium_color *)&p_color);
}

Variant::Variant(const NodePath &p_path) {
	pandemonium::api->pandemonium_variant_new_node_path(&_pandemonium_variant, (pandemonium_node_path *)&p_path);
}

Variant::Variant(const pandemonium::RID &p_rid) {
	pandemonium::api->pandemonium_variant_new_rid(&_pandemonium_variant, (pandemonium_rid *)&p_rid);
}

Variant::Variant(const Object *p_object) {
	if (p_object)
		pandemonium::api->pandemonium_variant_new_object(&_pandemonium_variant, p_object->_owner);
	else
		pandemonium::api->pandemonium_variant_new_nil(&_pandemonium_variant);
}

Variant::Variant(const Dictionary &p_dictionary) {
	pandemonium::api->pandemonium_variant_new_dictionary(&_pandemonium_variant, (pandemonium_dictionary *)&p_dictionary);
}

Variant::Variant(const Array &p_array) {
	pandemonium::api->pandemonium_variant_new_array(&_pandemonium_variant, (pandemonium_array *)&p_array);
}

Variant::Variant(const PoolByteArray &p_raw_array) {
	pandemonium::api->pandemonium_variant_new_pool_byte_array(&_pandemonium_variant, (pandemonium_pool_byte_array *)&p_raw_array);
}

Variant::Variant(const PoolIntArray &p_int_array) {
	pandemonium::api->pandemonium_variant_new_pool_int_array(&_pandemonium_variant, (pandemonium_pool_int_array *)&p_int_array);
}

Variant::Variant(const PoolRealArray &p_real_array) {
	pandemonium::api->pandemonium_variant_new_pool_real_array(&_pandemonium_variant, (pandemonium_pool_real_array *)&p_real_array);
}

Variant::Variant(const PoolStringArray &p_string_array) {
	pandemonium::api->pandemonium_variant_new_pool_string_array(&_pandemonium_variant, (pandemonium_pool_string_array *)&p_string_array);
}

Variant::Variant(const PoolVector2Array &p_vector2_array) {
	pandemonium::api->pandemonium_variant_new_pool_vector2_array(&_pandemonium_variant, (pandemonium_pool_vector2_array *)&p_vector2_array);
}

Variant::Variant(const PoolVector3Array &p_vector3_array) {
	pandemonium::api->pandemonium_variant_new_pool_vector3_array(&_pandemonium_variant, (pandemonium_pool_vector3_array *)&p_vector3_array);
}

Variant::Variant(const PoolColorArray &p_color_array) {
	pandemonium::api->pandemonium_variant_new_pool_color_array(&_pandemonium_variant, (pandemonium_pool_color_array *)&p_color_array);
}

Variant &Variant::operator=(const Variant &v) {
	pandemonium::api->pandemonium_variant_destroy(&_pandemonium_variant);
	pandemonium::api->pandemonium_variant_new_copy(&_pandemonium_variant, &v._pandemonium_variant);
	return *this;
}

Variant::operator bool() const {
	return booleanize();
}
Variant::operator signed int() const {
	return pandemonium::api->pandemonium_variant_as_int(&_pandemonium_variant);
}
Variant::operator unsigned int() const // this is the real one
{
	return pandemonium::api->pandemonium_variant_as_uint(&_pandemonium_variant);
}
Variant::operator signed short() const {
	return pandemonium::api->pandemonium_variant_as_int(&_pandemonium_variant);
}
Variant::operator unsigned short() const {
	return pandemonium::api->pandemonium_variant_as_uint(&_pandemonium_variant);
}
Variant::operator signed char() const {
	return pandemonium::api->pandemonium_variant_as_int(&_pandemonium_variant);
}
Variant::operator unsigned char() const {
	return pandemonium::api->pandemonium_variant_as_uint(&_pandemonium_variant);
}
Variant::operator int64_t() const {
	return pandemonium::api->pandemonium_variant_as_int(&_pandemonium_variant);
}
Variant::operator uint64_t() const {
	return pandemonium::api->pandemonium_variant_as_uint(&_pandemonium_variant);
}

Variant::operator wchar_t() const {
	return pandemonium::api->pandemonium_variant_as_int(&_pandemonium_variant);
}

Variant::operator float() const {
	return pandemonium::api->pandemonium_variant_as_real(&_pandemonium_variant);
}

Variant::operator double() const {
	return pandemonium::api->pandemonium_variant_as_real(&_pandemonium_variant);
}
Variant::operator String() const {
	pandemonium_string s = pandemonium::api->pandemonium_variant_as_string(&_pandemonium_variant);
	return String(s);
}
Variant::operator StringName() const {
	pandemonium_string_name s = pandemonium::api->pandemonium_variant_as_string_name(&_pandemonium_variant);
	return StringName(s);
}
Variant::operator Vector2() const {
	pandemonium_vector2 s = pandemonium::api->pandemonium_variant_as_vector2(&_pandemonium_variant);
	return *(Vector2 *)&s;
}
Variant::operator Vector2i() const {
	pandemonium_vector2i s = pandemonium::api->pandemonium_variant_as_vector2i(&_pandemonium_variant);
	return *(Vector2i *)&s;
}
Variant::operator Rect2() const {
	pandemonium_rect2 s = pandemonium::api->pandemonium_variant_as_rect2(&_pandemonium_variant);
	return *(Rect2 *)&s;
}
Variant::operator Rect2i() const {
	pandemonium_rect2i s = pandemonium::api->pandemonium_variant_as_rect2i(&_pandemonium_variant);
	return *(Rect2i *)&s;
}
Variant::operator Vector3() const {
	pandemonium_vector3 s = pandemonium::api->pandemonium_variant_as_vector3(&_pandemonium_variant);
	return *(Vector3 *)&s;
}
Variant::operator Vector3i() const {
	pandemonium_vector3i s = pandemonium::api->pandemonium_variant_as_vector3i(&_pandemonium_variant);
	return *(Vector3i *)&s;
}
Variant::operator Vector4() const {
	pandemonium_vector4 s = pandemonium::api->pandemonium_variant_as_vector4(&_pandemonium_variant);
	return *(Vector4 *)&s;
}
Variant::operator Vector4i() const {
	pandemonium_vector4i s = pandemonium::api->pandemonium_variant_as_vector4i(&_pandemonium_variant);
	return *(Vector4i *)&s;
}
Variant::operator Plane() const {
	pandemonium_plane s = pandemonium::api->pandemonium_variant_as_plane(&_pandemonium_variant);
	return *(Plane *)&s;
}
Variant::operator pandemonium::AABB() const {
	pandemonium_aabb s = pandemonium::api->pandemonium_variant_as_aabb(&_pandemonium_variant);
	return *(pandemonium::AABB *)&s;
}
Variant::operator Quaternion() const {
	pandemonium_quaternion s = pandemonium::api->pandemonium_variant_as_quaternion(&_pandemonium_variant);
	return *(Quaternion *)&s;
}
Variant::operator Basis() const {
	pandemonium_basis s = pandemonium::api->pandemonium_variant_as_basis(&_pandemonium_variant);
	return *(Basis *)&s;
}
Variant::operator Transform() const {
	pandemonium_transform s = pandemonium::api->pandemonium_variant_as_transform(&_pandemonium_variant);
	return *(Transform *)&s;
}
Variant::operator Transform2D() const {
	pandemonium_transform2d s = pandemonium::api->pandemonium_variant_as_transform2d(&_pandemonium_variant);
	return *(Transform2D *)&s;
}
Variant::operator Projection() const {
	pandemonium_projection s = pandemonium::api->pandemonium_variant_as_projection(&_pandemonium_variant);
	return *(Projection *)&s;
}

Variant::operator Color() const {
	pandemonium_color s = pandemonium::api->pandemonium_variant_as_color(&_pandemonium_variant);
	return *(Color *)&s;
}
Variant::operator NodePath() const {
	pandemonium_node_path ret = pandemonium::api->pandemonium_variant_as_node_path(&_pandemonium_variant);
	return NodePath(ret);
}
Variant::operator pandemonium::RID() const {
	pandemonium_rid s = pandemonium::api->pandemonium_variant_as_rid(&_pandemonium_variant);
	return *(pandemonium::RID *)&s;
}

Variant::operator Dictionary() const {
	Dictionary ret(pandemonium::api->pandemonium_variant_as_dictionary(&_pandemonium_variant));
	return ret;
}

Variant::operator Array() const {
	Array ret(pandemonium::api->pandemonium_variant_as_array(&_pandemonium_variant));
	return ret;
}

Variant::operator PoolByteArray() const {
	pandemonium_pool_byte_array ret = pandemonium::api->pandemonium_variant_as_pool_byte_array(&_pandemonium_variant);
	return PoolByteArray(ret);
}
Variant::operator PoolIntArray() const {
	pandemonium_pool_int_array ret = pandemonium::api->pandemonium_variant_as_pool_int_array(&_pandemonium_variant);
	return PoolIntArray(ret);
}
Variant::operator PoolRealArray() const {
	pandemonium_pool_real_array ret = pandemonium::api->pandemonium_variant_as_pool_real_array(&_pandemonium_variant);
	return PoolRealArray(ret);
}
Variant::operator PoolStringArray() const {
	pandemonium_pool_string_array ret = pandemonium::api->pandemonium_variant_as_pool_string_array(&_pandemonium_variant);
	return PoolStringArray(ret);
}
Variant::operator PoolVector2Array() const {
	pandemonium_pool_vector2_array ret = pandemonium::api->pandemonium_variant_as_pool_vector2_array(&_pandemonium_variant);
	return PoolVector2Array(ret);
}
Variant::operator PoolVector3Array() const {
	pandemonium_pool_vector3_array ret = pandemonium::api->pandemonium_variant_as_pool_vector3_array(&_pandemonium_variant);
	return PoolVector3Array(ret);
}
Variant::operator PoolColorArray() const {
	pandemonium_pool_color_array ret = pandemonium::api->pandemonium_variant_as_pool_color_array(&_pandemonium_variant);
	return PoolColorArray(ret);
}
Variant::operator pandemonium_object *() const {
	return pandemonium::api->pandemonium_variant_as_object(&_pandemonium_variant);
}

Variant::Type Variant::get_type() const {
	return static_cast<Type>(pandemonium::api->pandemonium_variant_get_type(&_pandemonium_variant));
}

Variant Variant::call(const String &method, const Variant **args, const int arg_count) {
	pandemonium_variant v = pandemonium::api->pandemonium_variant_call(
			&_pandemonium_variant, (pandemonium_string *)&method, (const pandemonium_variant **)args, arg_count, nullptr);
	return Variant(v);
}

bool Variant::has_method(const String &method) {
	return pandemonium::api->pandemonium_variant_has_method(&_pandemonium_variant, (pandemonium_string *)&method);
}

bool Variant::operator==(const Variant &b) const {
	return pandemonium::api->pandemonium_variant_operator_equal(&_pandemonium_variant, &b._pandemonium_variant);
}

bool Variant::operator!=(const Variant &b) const {
	return !(*this == b);
}

bool Variant::operator<(const Variant &b) const {
	return pandemonium::api->pandemonium_variant_operator_less(&_pandemonium_variant, &b._pandemonium_variant);
}

bool Variant::operator<=(const Variant &b) const {
	return (*this < b) || (*this == b);
}

bool Variant::operator>(const Variant &b) const {
	return !(*this <= b);
}

bool Variant::operator>=(const Variant &b) const {
	return !(*this < b);
}

bool Variant::hash_compare(const Variant &b) const {
	return pandemonium::api->pandemonium_variant_hash_compare(&_pandemonium_variant, &b._pandemonium_variant);
}

bool Variant::booleanize() const {
	return pandemonium::api->pandemonium_variant_booleanize(&_pandemonium_variant);
}

Variant::~Variant() {
	pandemonium::api->pandemonium_variant_destroy(&_pandemonium_variant);
}

} // namespace pandemonium
