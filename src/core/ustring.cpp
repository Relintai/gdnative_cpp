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

#include "ustring.h"

#include "array.h"
#include "pandemonium_global.h"
#include "node_path.h"
#include "pool_arrays.h"
#include "variant.h"

#include <gdn/string.h>

#include <string.h>

namespace pandemonium {

pandemonium::CharString::~CharString() {
	pandemonium::api->pandemonium_char_string_destroy(&_char_string);
}

int pandemonium::CharString::length() const {
	return pandemonium::api->pandemonium_char_string_length(&_char_string);
}

const char *pandemonium::CharString::get_data() const {
	return pandemonium::api->pandemonium_char_string_get_data(&_char_string);
}

pandemonium::Char16String::~Char16String() {
	pandemonium::api->pandemonium_char_16_string_destroy(&_char_string);
}

int pandemonium::Char16String::length() const {
	return pandemonium::api->pandemonium_char_16_string_length(&_char_string);
}

const char16_t *pandemonium::Char16String::get_data() const {
	return pandemonium::api->pandemonium_char_16_string_get_data(&_char_string);
}

String String::num(double p_num, int p_decimals) {
	return String(pandemonium::api->pandemonium_string_num_with_decimals(p_num, p_decimals));
}

String String::num_scientific(double p_num) {
	return String(pandemonium::api->pandemonium_string_num_scientific(p_num));
}

String String::num_real(double p_num) {
	return String(pandemonium::api->pandemonium_string_num_real(p_num));
}

String String::num_int64(int64_t p_num, int base, bool capitalize_hex) {
	return String(pandemonium::api->pandemonium_string_num_int64_capitalized(p_num, base, capitalize_hex));
}

String String::chr(pandemonium_char_type p_char) {
	return String(pandemonium::api->pandemonium_string_chr(p_char));
}

String String::md5(const uint8_t *p_md5) {
	return String(pandemonium::api->pandemonium_string_md5(p_md5));
}

String String::hex_encode_buffer(const uint8_t *p_buffer, int p_len) {
	return String(pandemonium::api->pandemonium_string_hex_encode_buffer(p_buffer, p_len));
}

pandemonium::String::String() {
	pandemonium::api->pandemonium_string_new(&_pandemonium_string);
}

String::String(const char *contents) {
	pandemonium::api->pandemonium_string_new(&_pandemonium_string);
	pandemonium::api->pandemonium_string_parse_utf8(&_pandemonium_string, contents);
}

String::String(const wchar_t *contents) {
	pandemonium::api->pandemonium_string_new_wchar_clip_to_len(&_pandemonium_string, contents, wcslen(contents));
}

String::String(const wchar_t c) {
	pandemonium::api->pandemonium_string_new_wchar_clip_to_len(&_pandemonium_string, &c, 1);
}

String::String(const String &other) {
	pandemonium::api->pandemonium_string_new_copy(&_pandemonium_string, &other._pandemonium_string);
}

String::String(String &&other) {
	pandemonium::api->pandemonium_string_new_copy(&_pandemonium_string, &other._pandemonium_string);
}

String::~String() {
	pandemonium::api->pandemonium_string_destroy(&_pandemonium_string);
}

char32_t &String::operator[](const int idx) {
	return *const_cast<char32_t *>(pandemonium::api->pandemonium_string_operator_index(&_pandemonium_string, idx));
}

char32_t String::operator[](const int idx) const {
	return *pandemonium::api->pandemonium_string_operator_index((pandemonium_string *)&_pandemonium_string, idx);
}

int String::length() const {
	return pandemonium::api->pandemonium_string_length(&_pandemonium_string);
}

void String::operator=(const String &s) {
	pandemonium::api->pandemonium_string_destroy(&_pandemonium_string);
	pandemonium::api->pandemonium_string_new_copy(&_pandemonium_string, &s._pandemonium_string);
}

void String::operator=(String &&s) {
	pandemonium::api->pandemonium_string_destroy(&_pandemonium_string);
	pandemonium::api->pandemonium_string_new_copy(&_pandemonium_string, &s._pandemonium_string);
}

bool String::operator==(const String &s) const {
	return pandemonium::api->pandemonium_string_operator_equal(&_pandemonium_string, &s._pandemonium_string);
}

bool String::operator!=(const String &s) const {
	return !(*this == s);
}

String String::operator+(const String &s) const {
	return String(pandemonium::api->pandemonium_string_operator_plus(&_pandemonium_string, &s._pandemonium_string));
}

void String::operator+=(const String &s) {
	*this = String(pandemonium::api->pandemonium_string_operator_plus(&_pandemonium_string, &s._pandemonium_string));
}

void String::operator+=(const char32_t c) {
	String _to_be_added = String(c);
	*this = String(pandemonium::api->pandemonium_string_operator_plus(&_pandemonium_string, &_to_be_added._pandemonium_string));
}

bool String::operator<(const String &s) const {
	return pandemonium::api->pandemonium_string_operator_less(&_pandemonium_string, &s._pandemonium_string);
}

bool String::operator<=(const String &s) const {
	return pandemonium::api->pandemonium_string_operator_less(&_pandemonium_string, &s._pandemonium_string) ||
		   (*this == s);
}

bool String::operator>(const String &s) const {
	return !(*this <= s);
}

bool String::operator>=(const String &s) const {
	return !(*this < s);
}

String::operator NodePath() const {
	return NodePath(*this);
}

const char32_t *String::unicode_str() const {
	return pandemonium::api->pandemonium_string_get_data(&_pandemonium_string);
}

char *String::alloc_c_string() const {
	pandemonium_char_string contents = pandemonium::api->pandemonium_string_utf8(&_pandemonium_string);

	int length = pandemonium::api->pandemonium_char_string_length(&contents);

	char *result = (char *)pandemonium::api->pandemonium_alloc(length + 1);

	if (result) {
		memcpy(result, pandemonium::api->pandemonium_char_string_get_data(&contents), length + 1);
	}

	pandemonium::api->pandemonium_char_string_destroy(&contents);

	return result;
}

CharString String::utf8() const {
	CharString ret;

	ret._char_string = pandemonium::api->pandemonium_string_utf8(&_pandemonium_string);

	return ret;
}

CharString String::ascii(bool p_extended) const {
	CharString ret;

	if (p_extended)
		ret._char_string = pandemonium::api->pandemonium_string_ascii_extended(&_pandemonium_string);
	else
		ret._char_string = pandemonium::api->pandemonium_string_ascii(&_pandemonium_string);

	return ret;
}

String operator+(const char *a, const String &b) {
	return String(a) + b;
}

String operator+(const wchar_t *a, const String &b) {
	return String(a) + b;
}

bool String::begins_with(const String &p_string) const {
	return pandemonium::api->pandemonium_string_begins_with(&_pandemonium_string, &p_string._pandemonium_string);
}

bool String::begins_with_char_array(const char *p_char_array) const {
	return pandemonium::api->pandemonium_string_begins_with_char_array(&_pandemonium_string, p_char_array);
}

PoolStringArray String::bigrams() const {
	pandemonium_array arr = pandemonium::api->pandemonium_string_bigrams(&_pandemonium_string);
	return Array(arr);
}

String String::c_escape() const {
	return String(pandemonium::api->pandemonium_string_c_escape(&_pandemonium_string));
}

String String::c_unescape() const {
	return String(pandemonium::api->pandemonium_string_c_unescape(&_pandemonium_string));
}

String String::capitalize() const {
	return String(pandemonium::api->pandemonium_string_capitalize(&_pandemonium_string));
}

bool String::empty() const {
	return pandemonium::api->pandemonium_string_empty(&_pandemonium_string);
}

bool String::ends_with(const String &p_string) const {
	return pandemonium::api->pandemonium_string_ends_with(&_pandemonium_string, &p_string._pandemonium_string);
}

void String::erase(int position, int chars) {
	pandemonium::api->pandemonium_string_erase(&_pandemonium_string, position, chars);
}

int String::find(String p_what, int p_from) const {
	return pandemonium::api->pandemonium_string_find_from(&_pandemonium_string, p_what._pandemonium_string, p_from);
}

int String::find_last(String p_what) const {
	return pandemonium::api->pandemonium_string_find_last(&_pandemonium_string, p_what._pandemonium_string);
}

int String::findn(String p_what, int p_from) const {
	return pandemonium::api->pandemonium_string_findn_from(&_pandemonium_string, p_what._pandemonium_string, p_from);
}

String String::format(Variant values) const {
	return String(pandemonium::api->pandemonium_string_format(&_pandemonium_string, (pandemonium_variant *)&values));
}

String String::format(Variant values, String placeholder) const {
	pandemonium_char_string contents = pandemonium::api->pandemonium_string_utf8(&placeholder._pandemonium_string);
	String new_string(pandemonium::api->pandemonium_string_format_with_custom_placeholder(&_pandemonium_string, (pandemonium_variant *)&values, pandemonium::api->pandemonium_char_string_get_data(&contents)));
	pandemonium::api->pandemonium_char_string_destroy(&contents);

	return new_string;
}

String String::get_base_dir() const {
	return String(pandemonium::api->pandemonium_string_get_base_dir(&_pandemonium_string));
}

String String::get_basename() const {
	return String(pandemonium::api->pandemonium_string_get_basename(&_pandemonium_string));
}

String String::get_extension() const {
	return String(pandemonium::api->pandemonium_string_get_extension(&_pandemonium_string));
}

String String::get_file() const {
	return String(pandemonium::api->pandemonium_string_get_file(&_pandemonium_string));
}

int String::hash() const {
	return pandemonium::api->pandemonium_string_hash(&_pandemonium_string);
}

int String::hex_to_int() const {
	return pandemonium::api->pandemonium_string_hex_to_int(&_pandemonium_string);
}

String String::insert(int position, String what) const {
	return String(pandemonium::api->pandemonium_string_insert(&_pandemonium_string, position, what._pandemonium_string));
}

bool String::is_abs_path() const {
	return pandemonium::api->pandemonium_string_is_abs_path(&_pandemonium_string);
}

bool String::is_rel_path() const {
	return pandemonium::api->pandemonium_string_is_rel_path(&_pandemonium_string);
}

bool String::is_subsequence_of(String text) const {
	return pandemonium::api->pandemonium_string_is_subsequence_of(&_pandemonium_string, &text._pandemonium_string);
}

bool String::is_subsequence_ofi(String text) const {
	return pandemonium::api->pandemonium_string_is_subsequence_ofi(&_pandemonium_string, &text._pandemonium_string);
}

bool String::is_valid_float() const {
	return pandemonium::api->pandemonium_string_is_valid_float(&_pandemonium_string);
}

bool String::is_valid_html_color() const {
	return pandemonium::api->pandemonium_string_is_valid_html_color(&_pandemonium_string);
}

bool String::is_valid_identifier() const {
	return pandemonium::api->pandemonium_string_is_valid_identifier(&_pandemonium_string);
}

bool String::is_valid_integer() const {
	return pandemonium::api->pandemonium_string_is_numeric(&_pandemonium_string);
}

bool String::is_valid_ip_address() const {
	return pandemonium::api->pandemonium_string_is_valid_ip_address(&_pandemonium_string);
}

String String::json_escape() const {
	return String(pandemonium::api->pandemonium_string_json_escape(&_pandemonium_string));
}

String String::left(int position) const {
	return String(pandemonium::api->pandemonium_string_left(&_pandemonium_string, position));
}

bool String::match(String expr) const {
	return pandemonium::api->pandemonium_string_match(&_pandemonium_string, &expr._pandemonium_string);
}

bool String::matchn(String expr) const {
	return pandemonium::api->pandemonium_string_match(&_pandemonium_string, &expr._pandemonium_string);
}

PoolByteArray String::md5_buffer() const {
	pandemonium_pool_byte_array arr = pandemonium::api->pandemonium_string_md5_buffer(&_pandemonium_string);
	return PoolByteArray(arr);
}

String String::md5_text() const {
	return String(pandemonium::api->pandemonium_string_md5_text(&_pandemonium_string));
}

int String::ord_at(int at) const {
	return pandemonium::api->pandemonium_string_ord_at(&_pandemonium_string, at);
}

String String::pad_decimals(int digits) const {
	return String(pandemonium::api->pandemonium_string_pad_decimals(&_pandemonium_string, digits));
}

String String::pad_zeros(int digits) const {
	return String(pandemonium::api->pandemonium_string_pad_zeros(&_pandemonium_string, digits));
}

String String::percent_decode() const {
	return String(pandemonium::api->pandemonium_string_percent_decode(&_pandemonium_string));
}

String String::percent_encode() const {
	return String(pandemonium::api->pandemonium_string_percent_encode(&_pandemonium_string));
}

String String::plus_file(String file) const {
	return String(pandemonium::api->pandemonium_string_plus_file(&_pandemonium_string, &file._pandemonium_string));
}

String String::replace(String p_key, String p_with) const {
	return String(pandemonium::api->pandemonium_string_replace(&_pandemonium_string, p_key._pandemonium_string, p_with._pandemonium_string));
}

String String::replacen(String what, String forwhat) const {
	return String(pandemonium::api->pandemonium_string_replacen(&_pandemonium_string, what._pandemonium_string, forwhat._pandemonium_string));
}

int String::rfind(String p_what, int p_from) const {
	return pandemonium::api->pandemonium_string_rfind_from(&_pandemonium_string, p_what._pandemonium_string, p_from);
}

int String::rfindn(String p_what, int p_from) const {
	return pandemonium::api->pandemonium_string_rfindn_from(&_pandemonium_string, p_what._pandemonium_string, p_from);
}

String String::right(int position) const {
	return String(pandemonium::api->pandemonium_string_right(&_pandemonium_string, position));
}

PoolByteArray String::sha256_buffer() const {
	pandemonium_pool_byte_array arr = pandemonium::api->pandemonium_string_sha256_buffer(&_pandemonium_string);
	return PoolByteArray(arr);
}

String String::sha256_text() const {
	return String(pandemonium::api->pandemonium_string_sha256_text(&_pandemonium_string));
}

float String::similarity(String text) const {
	return pandemonium::api->pandemonium_string_similarity(&_pandemonium_string, &text._pandemonium_string);
}

// TODO Suport allow_empty
PoolStringArray String::split(String divisor, bool /*allow_empty*/) const {
	pandemonium_pool_string_array arr = pandemonium::api->pandemonium_string_split(&_pandemonium_string, &divisor._pandemonium_string);
	return PoolStringArray(arr);
}

// TODO Suport allow_empty
PoolIntArray String::split_ints(String divisor, bool /*allow_empty*/) const {
	pandemonium_array arr = pandemonium::api->pandemonium_string_split_floats(&_pandemonium_string, &divisor._pandemonium_string);
	return Array(arr);
}

// TODO Suport allow_empty
PoolRealArray String::split_floats(String divisor, bool /*allow_empty*/) const {
	// TODO The GDNative API returns pandemonium_array, when according to the doc, it should have been pandemonium_pool_real_array
	pandemonium_array arr = pandemonium::api->pandemonium_string_split_floats(&_pandemonium_string, &divisor._pandemonium_string);
	Array wrapped_array(arr);
	return PoolRealArray(wrapped_array);
}

String String::strip_edges(bool left, bool right) const {
	return String(pandemonium::api->pandemonium_string_strip_edges(&_pandemonium_string, left, right));
}

String String::substr(int from, int len) const {
	return String(pandemonium::api->pandemonium_string_substr(&_pandemonium_string, from, len));
}

float String::to_float() const {
	return pandemonium::api->pandemonium_string_to_float(&_pandemonium_string);
}

int64_t String::to_int() const {
	return pandemonium::api->pandemonium_string_to_int(&_pandemonium_string);
}

String String::to_lower() const {
	return String(pandemonium::api->pandemonium_string_to_lower(&_pandemonium_string));
}

String String::to_upper() const {
	return String(pandemonium::api->pandemonium_string_to_upper(&_pandemonium_string));
}

String String::xml_escape() const {
	return String(pandemonium::api->pandemonium_string_xml_escape(&_pandemonium_string));
}

String String::xml_unescape() const {
	return String(pandemonium::api->pandemonium_string_xml_unescape(&_pandemonium_string));
}

signed char String::casecmp_to(String p_str) const {
	return pandemonium::api->pandemonium_string_casecmp_to(&_pandemonium_string, &p_str._pandemonium_string);
}

signed char String::nocasecmp_to(String p_str) const {
	return pandemonium::api->pandemonium_string_nocasecmp_to(&_pandemonium_string, &p_str._pandemonium_string);
}

signed char String::naturalnocasecmp_to(String p_str) const {
	return pandemonium::api->pandemonium_string_naturalnocasecmp_to(&_pandemonium_string, &p_str._pandemonium_string);
}

String String::dedent() const {
	pandemonium_string s = pandemonium::api->pandemonium_string_dedent(&_pandemonium_string);
	return String(s);
}

PoolStringArray String::rsplit(const String &divisor, const bool allow_empty, const int maxsplit) const {
	pandemonium_pool_string_array arr =
			pandemonium::api->pandemonium_string_rsplit_maxsplit(&_pandemonium_string, &divisor._pandemonium_string, allow_empty, maxsplit);
	return PoolStringArray(arr);
}

String String::rstrip(const String &chars) const {
	pandemonium_string s = pandemonium::api->pandemonium_string_rstrip(&_pandemonium_string, &chars._pandemonium_string);
	return String(s);
}

String String::trim_prefix(const String &prefix) const {
	pandemonium_string s = pandemonium::api->pandemonium_string_trim_prefix(&_pandemonium_string, &prefix._pandemonium_string);
	return String(s);
}

String String::trim_suffix(const String &suffix) const {
	pandemonium_string s = pandemonium::api->pandemonium_string_trim_suffix(&_pandemonium_string, &suffix._pandemonium_string);
	return String(s);
}

} // namespace pandemonium
