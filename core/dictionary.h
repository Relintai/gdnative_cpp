#ifndef DICTIONARY_H
#define DICTIONARY_H

/*************************************************************************/
/*  dictionary.h                                                       */
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
#include "variant.h"

#include <gdn/dictionary.h>

class Variant;

class Dictionary {
	pandemonium_dictionary _pandemonium_dictionary;

	friend Variant::operator Dictionary() const;
	inline explicit Dictionary(const pandemonium_dictionary &other) {
		_pandemonium_dictionary = other;
	}

public:
	Dictionary();
	Dictionary(const Dictionary &other);
	Dictionary &operator=(const Dictionary &other);

	template <class... Args>
	static Dictionary make(Args... args) {
		return helpers::add_all(Dictionary(), args...);
	}

	void clear();

	bool empty() const;

	void erase(const Variant &key);

	bool has(const Variant &key) const;

	bool has_all(const Array &keys) const;

	uint32_t hash() const;

	Array keys() const;

	Variant &operator[](const Variant &key);

	const Variant &operator[](const Variant &key) const;

	int size() const;

	String to_json() const;

	Array values() const;

	~Dictionary();
};

#endif // DICTIONARY_H
