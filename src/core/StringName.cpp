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

#include "StringName.h"

#include "Array.h"
#include "PandemoniumGlobal.h"
#include "NodePath.h"
#include "PoolArrays.h"
#include "Variant.h"

#include <gdn/string.h>

#include <string.h>

namespace pandemonium {

pandemonium::StringName::StringName() {
	pandemonium::api->pandemonium_string_name_new(&_pandemonium_string_name);
}

StringName::StringName(const char *contents) {
	pandemonium::api->pandemonium_string_name_new_data_char(&_pandemonium_string_name, contents);
}

StringName::StringName(const String &other) {
	pandemonium::api->pandemonium_string_name_new_data_string(&_pandemonium_string_name, &other._pandemonium_string);
}

StringName::~StringName() {
	pandemonium::api->pandemonium_string_name_destroy(&_pandemonium_string_name);
}


bool StringName::operator==(const StringName &s) const {
	return pandemonium::api->pandemonium_string_name_operator_equal(&_pandemonium_string_name, &s._pandemonium_string_name);
}

bool StringName::operator!=(const StringName &s) const {
	return !(*this == s);
}

bool StringName::operator<(const StringName &s) const {
	return pandemonium::api->pandemonium_string_name_operator_less(&_pandemonium_string_name, &s._pandemonium_string_name);
}

bool StringName::operator<=(const StringName &s) const {
	return pandemonium::api->pandemonium_string_name_operator_less(&_pandemonium_string_name, &s._pandemonium_string_name) ||
		   (*this == s);
}

bool StringName::operator>(const StringName &s) const {
	return !(*this <= s);
}

bool StringName::operator>=(const StringName &s) const {
	return !(*this < s);
}

} // namespace pandemonium
