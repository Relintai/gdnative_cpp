/*************************************************************************/
/*  String.hpp                                                           */
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

#ifndef STRING_NAME_H
#define STRING_NAME_H

#include <gdn/string_name.h>

namespace pandemonium {

class String;

class StringName {
	pandemonium_string_name _pandemonium_string_name;

	friend class Dictionary;
	friend class NodePath;
	friend class Variant;
	explicit inline StringName(pandemonium_string_name contents) :
			_pandemonium_string_name(contents) {}

public:
	StringName();
	StringName(const char *contents);
	StringName(const String &other);

	~StringName();

	operator String();

	uint32_t get_hash();
	const void *get_data_unique_pointer();

	bool operator==(const StringName &s) const;
	bool operator!=(const StringName &s) const;

	bool operator<(const StringName &s) const;
	bool operator<=(const StringName &s) const;
	bool operator>(const StringName &s) const;
	bool operator>=(const StringName &s) const;
};

} // namespace pandemonium

#endif // STRING_H
