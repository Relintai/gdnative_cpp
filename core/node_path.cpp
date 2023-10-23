/*************************************************************************/
/*  NodePath.cpp                                                         */
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

#include "node_path.h"
#include "pandemonium_global.h"
#include "ustring.h"

#include <gdn/node_path.h>

NodePath::NodePath() {
	String from = "";
	Pandemonium::api->pandemonium_node_path_new(&_node_path, (pandemonium_string *)&from);
}

NodePath::NodePath(const NodePath &other) {
	String from = other;
	Pandemonium::api->pandemonium_node_path_new(&_node_path, (pandemonium_string *)&from);
}

NodePath::NodePath(const String &from) {
	Pandemonium::api->pandemonium_node_path_new(&_node_path, (pandemonium_string *)&from);
}

NodePath::NodePath(const char *contents) {
	String from = contents;
	Pandemonium::api->pandemonium_node_path_new(&_node_path, (pandemonium_string *)&from);
}

String NodePath::get_name(const int idx) const {
	pandemonium_string str = Pandemonium::api->pandemonium_node_path_get_name(&_node_path, idx);
	return String(str);
}

int NodePath::get_name_count() const {
	return Pandemonium::api->pandemonium_node_path_get_name_count(&_node_path);
}

String NodePath::get_subname(const int idx) const {
	pandemonium_string str = Pandemonium::api->pandemonium_node_path_get_subname(&_node_path, idx);
	return String(str);
}

int NodePath::get_subname_count() const {
	return Pandemonium::api->pandemonium_node_path_get_subname_count(&_node_path);
}

bool NodePath::is_absolute() const {
	return Pandemonium::api->pandemonium_node_path_is_absolute(&_node_path);
}

bool NodePath::is_empty() const {
	return Pandemonium::api->pandemonium_node_path_is_empty(&_node_path);
}

NodePath NodePath::get_as_property_path() const {
	pandemonium_node_path path = Pandemonium::api->pandemonium_node_path_get_as_property_path(&_node_path);
	return NodePath(path);
}
String NodePath::get_concatenated_subnames() const {
	pandemonium_string str = Pandemonium::api->pandemonium_node_path_get_concatenated_subnames(&_node_path);
	return String(str);
}

uint32_t NodePath::hash() const {
	return Pandemonium::api->pandemonium_node_path_hash(&_node_path);
}

NodePath::operator String() const {
	pandemonium_string str = Pandemonium::api->pandemonium_node_path_as_string(&_node_path);
	return String(str);
}

bool NodePath::operator==(const NodePath &other) {
	return Pandemonium::api->pandemonium_node_path_operator_equal(&_node_path, &other._node_path);
}

void NodePath::operator=(const NodePath &other) {
	Pandemonium::api->pandemonium_node_path_destroy(&_node_path);

	String other_string = (String)other;

	Pandemonium::api->pandemonium_node_path_new(&_node_path, (pandemonium_string *)&other_string);
}

NodePath::~NodePath() {
	Pandemonium::api->pandemonium_node_path_destroy(&_node_path);
}
