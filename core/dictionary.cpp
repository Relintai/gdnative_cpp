/*************************************************************************/
/*  Dictionary.cpp                                                       */
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

#include "dictionary.h"
#include "array.h"
#include "pandemonium_global.h"
#include "variant.h"

Dictionary::Dictionary() {
	Pandemonium::api->pandemonium_dictionary_new(&_pandemonium_dictionary);
}

Dictionary::Dictionary(const Dictionary &other) {
	Pandemonium::api->pandemonium_dictionary_new_copy(&_pandemonium_dictionary, &other._pandemonium_dictionary);
}

Dictionary &Dictionary::operator=(const Dictionary &other) {
	Pandemonium::api->pandemonium_dictionary_destroy(&_pandemonium_dictionary);
	Pandemonium::api->pandemonium_dictionary_new_copy(&_pandemonium_dictionary, &other._pandemonium_dictionary);
	return *this;
}

void Dictionary::clear() {
	Pandemonium::api->pandemonium_dictionary_clear(&_pandemonium_dictionary);
}

bool Dictionary::empty() const {
	return Pandemonium::api->pandemonium_dictionary_empty(&_pandemonium_dictionary);
}

void Dictionary::erase(const Variant &key) {
	Pandemonium::api->pandemonium_dictionary_erase(&_pandemonium_dictionary, (pandemonium_variant *)&key);
}

bool Dictionary::has(const Variant &key) const {
	return Pandemonium::api->pandemonium_dictionary_has(&_pandemonium_dictionary, (pandemonium_variant *)&key);
}

bool Dictionary::has_all(const Array &keys) const {
	return Pandemonium::api->pandemonium_dictionary_has_all(&_pandemonium_dictionary, (pandemonium_array *)&keys);
}

uint32_t Dictionary::hash() const {
	return Pandemonium::api->pandemonium_dictionary_hash(&_pandemonium_dictionary);
}

Array Dictionary::keys() const {
	pandemonium_array a = Pandemonium::api->pandemonium_dictionary_keys(&_pandemonium_dictionary);
	return Array(a);
}

Variant &Dictionary::operator[](const Variant &key) {
	pandemonium_variant *v = Pandemonium::api->pandemonium_dictionary_operator_index(&_pandemonium_dictionary, (pandemonium_variant *)&key);
	return *reinterpret_cast<Variant *>(v);
}

const Variant &Dictionary::operator[](const Variant &key) const {
	// oops I did it again
	pandemonium_variant *v = Pandemonium::api->pandemonium_dictionary_operator_index((pandemonium_dictionary *)&_pandemonium_dictionary, (pandemonium_variant *)&key);
	return *reinterpret_cast<Variant *>(v);
}

int Dictionary::size() const {
	return Pandemonium::api->pandemonium_dictionary_size(&_pandemonium_dictionary);
}

String Dictionary::to_json() const {
	pandemonium_string s = Pandemonium::api->pandemonium_dictionary_to_json(&_pandemonium_dictionary);
	return String(s);
}

Array Dictionary::values() const {
	pandemonium_array a = Pandemonium::api->pandemonium_dictionary_values(&_pandemonium_dictionary);
	return Array(a);
}

Dictionary::~Dictionary() {
	Pandemonium::api->pandemonium_dictionary_destroy(&_pandemonium_dictionary);
}
