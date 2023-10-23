/*************************************************************************/
/*  String.cpp                                                           */
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

#include "string_name.h"

#include "array.h"
#include "node_path.h"
#include "pandemonium_global.h"
#include "pool_arrays.h"
#include "variant.h"

#include <gdn/string.h>

#include <string.h>

StringName::StringName() {
	Pandemonium::api->pandemonium_string_name_new(&_pandemonium_string_name);
}

StringName::StringName(const char *contents) {
	Pandemonium::api->pandemonium_string_name_new_data_char(&_pandemonium_string_name, contents);
}

StringName::StringName(const String &other) {
	Pandemonium::api->pandemonium_string_name_new_data_string(&_pandemonium_string_name, &other._pandemonium_string);
}

StringName::~StringName() {
	Pandemonium::api->pandemonium_string_name_destroy(&_pandemonium_string_name);
}

StringName::operator String() {
	return String(Pandemonium::api->pandemonium_string_name_get_name(&_pandemonium_string_name));
}

uint32_t StringName::get_hash() {
	return Pandemonium::api->pandemonium_string_name_get_hash(&_pandemonium_string_name);
}
uint32_t StringName::hash() const {
	return Pandemonium::api->pandemonium_string_name_get_hash(&_pandemonium_string_name);
}
const void *StringName::get_data_unique_pointer() {
	return &_pandemonium_string_name;
}

bool StringName::operator==(const StringName &s) const {
	return Pandemonium::api->pandemonium_string_name_operator_equal(&_pandemonium_string_name, &s._pandemonium_string_name);
}

bool StringName::operator!=(const StringName &s) const {
	return !(*this == s);
}

bool StringName::operator<(const StringName &s) const {
	return Pandemonium::api->pandemonium_string_name_operator_less(&_pandemonium_string_name, &s._pandemonium_string_name);
}

bool StringName::operator<=(const StringName &s) const {
	return Pandemonium::api->pandemonium_string_name_operator_less(&_pandemonium_string_name, &s._pandemonium_string_name) ||
		   (*this == s);
}

bool StringName::operator>(const StringName &s) const {
	return !(*this <= s);
}

bool StringName::operator>=(const StringName &s) const {
	return !(*this < s);
}
