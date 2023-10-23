/*************************************************************************/
/*  RID.cpp                                                              */
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

#include "rid.h"

#include <gdn/rid.h>

#include "pandemonium_global.h"

namespace pandemonium {

RID::RID() {
	pandemonium::api->pandemonium_rid_new(&_pandemonium_rid);
}

RID::RID(Object *p) {
	pandemonium::api->pandemonium_rid_new_with_resource(&_pandemonium_rid, (const pandemonium_object *)p);
}

pandemonium_rid RID::_get_pandemonium_rid() const {
	return _pandemonium_rid;
}

int32_t RID::get_id() const {
	return pandemonium::api->pandemonium_rid_get_id(&_pandemonium_rid);
}

bool RID::operator==(const RID &p_other) const {
	return pandemonium::api->pandemonium_rid_operator_equal(&_pandemonium_rid, &p_other._pandemonium_rid);
}

bool RID::operator!=(const RID &p_other) const {
	return !(*this == p_other);
}

bool RID::operator<(const RID &p_other) const {
	return pandemonium::api->pandemonium_rid_operator_less(&_pandemonium_rid, &p_other._pandemonium_rid);
}

bool RID::operator>(const RID &p_other) const {
	return !(*this < p_other) && *this != p_other;
}

bool RID::operator<=(const RID &p_other) const {
	return (*this < p_other) || *this == p_other;
}

bool RID::operator>=(const RID &p_other) const {
	return !(*this < p_other);
}

} // namespace pandemonium
