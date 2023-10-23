/*************************************************************************/
/*  init.cpp                                                             */
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

#include <pandemonium.h>
#include <Reference.h>



class SimpleClass : public Reference {
	PANDEMONIUM_CLASS(SimpleClass, Reference);

public:
	SimpleClass() {}

	/** `_init` must exist as it is called by Pandemonium. */
	void _init() {
		_name = String("SimpleClass");
		_value = 0;
	}

	void test_void_method() {
		Pandemonium::print("This is test");
	}

	Variant method(Variant arg) {
		Variant ret;
		ret = arg;

		return ret;
	}

	static void _register_methods() {
		register_method("method", &SimpleClass::method);

		/**
		 * The line below is equivalent to the following GDScript export:
		 *	 export var _name = "SimpleClass"
		 **/
		register_property<SimpleClass, String>("name", &SimpleClass::_name, String("SimpleClass"));

		/** Alternatively, with getter and setter methods: */
		register_property<SimpleClass, int>("value", &SimpleClass::set_value, &SimpleClass::get_value, 0);

		/** Registering a signal: **/
		register_signal<SimpleClass>("signal_name0"); // windows: error C2668: 'Pandemonium::register_signal': ambiguous call to overloaded function
		register_signal<SimpleClass>("signal_name1", "string_argument", PANDEMONIUM_VARIANT_TYPE_STRING);
	}

	String _name;
	int _value;

	void set_value(int p_value) {
		_value = p_value;
	}

	int get_value() const {
		return _value;
	}
};

/** GDNative Initialize **/
extern "C" void GDN_EXPORT pandemonium_gdnative_init(pandemonium_gdnative_init_options *o) {
	Pandemonium::gdnative_init(o);
}

/** GDNative Terminate **/
extern "C" void GDN_EXPORT pandemonium_gdnative_terminate(pandemonium_gdnative_terminate_options *o) {
	Pandemonium::gdnative_terminate(o);
}

/** NativeScript Initialize **/
extern "C" void GDN_EXPORT pandemonium_nativescript_init(void *handle) {
	Pandemonium::nativescript_init(handle);

	Pandemonium::register_class<SimpleClass>();
}
