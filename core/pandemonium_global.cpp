/*************************************************************************/
/*  PandemoniumGlobal.cpp                                                      */
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

#include "pandemonium_global.h"

#include "array.h"
#include "ustring.h"

#include "wrapped.h"

static GDCALLINGCONV void *wrapper_create(void *data, const void *type_tag, pandemonium_object *instance) {
	_Wrapped *wrapper_memory = (_Wrapped *)Pandemonium::api->pandemonium_alloc(sizeof(_Wrapped));

	if (!wrapper_memory)
		return NULL;
	wrapper_memory->_owner = instance;
	wrapper_memory->_type_tag = (size_t)type_tag;

	return (void *)wrapper_memory;
}

static GDCALLINGCONV void wrapper_destroy(void *data, void *wrapper) {
	if (wrapper)
		Pandemonium::api->pandemonium_free(wrapper);
}

void *_RegisterState::nativescript_handle;
int _RegisterState::language_index;

const pandemonium_gdnative_core_api_struct *Pandemonium::api = NULL;

const pandemonium_gdnative_ext_nativescript_api_struct *Pandemonium::nativescript_api = NULL;
const pandemonium_gdnative_ext_pluginscript_api_struct *Pandemonium::pluginscript_api = NULL;
const pandemonium_gdnative_ext_android_api_struct *Pandemonium::android_api = NULL;
const pandemonium_gdnative_ext_videodecoder_api_struct *Pandemonium::videodecoder_api = NULL;
const pandemonium_gdnative_ext_net_api_struct *Pandemonium::net_api = NULL;

const void *Pandemonium::gdnlib = NULL;

void Pandemonium::print(const String &message) {
	Pandemonium::api->pandemonium_print((pandemonium_string *)&message);
}

void Pandemonium::print_warning(const String &description, const String &function, const String &file, int line) {
	int len;

	char *c_desc = description.alloc_c_string();
	char *c_func = function.alloc_c_string();
	char *c_file = file.alloc_c_string();

	if (c_desc != nullptr && c_func != nullptr && c_file != nullptr) {
		Pandemonium::api->pandemonium_print_warning(c_desc, c_func, c_file, line);
	};

	if (c_desc != nullptr)
		Pandemonium::api->pandemonium_free(c_desc);
	if (c_func != nullptr)
		Pandemonium::api->pandemonium_free(c_func);
	if (c_file != nullptr)
		Pandemonium::api->pandemonium_free(c_file);
}

void Pandemonium::print_error(const String &description, const String &function, const String &file, int line) {
	int len;

	char *c_desc = description.alloc_c_string();
	char *c_func = function.alloc_c_string();
	char *c_file = file.alloc_c_string();

	if (c_desc != nullptr && c_func != nullptr && c_file != nullptr) {
		Pandemonium::api->pandemonium_print_error(c_desc, c_func, c_file, line);
	};

	if (c_desc != nullptr)
		Pandemonium::api->pandemonium_free(c_desc);
	if (c_func != nullptr)
		Pandemonium::api->pandemonium_free(c_func);
	if (c_file != nullptr)
		Pandemonium::api->pandemonium_free(c_file);
}

void ___register_types();
void ___init_method_bindings();

void Pandemonium::gdnative_init(pandemonium_gdnative_init_options *options) {
	Pandemonium::api = options->api_struct;
	Pandemonium::gdnlib = options->gd_native_library;

	const pandemonium_gdnative_api_struct *core_extension = Pandemonium::api->next;

	/*
	while (core_extension) {
		if (core_extension->version.major == 1 && core_extension->version.minor == 1) {
			Pandemonium::core_1_1_api = (const pandemonium_gdnative_core_1_1_api_struct *)core_extension;
		} else if (core_extension->version.major == 1 && core_extension->version.minor == 2) {
			Pandemonium::core_1_2_api = (const pandemonium_gdnative_core_1_2_api_struct *)core_extension;
		}
		core_extension = core_extension->next;
	}
	*/

	// now find our extensions
	for (int i = 0; i < Pandemonium::api->num_extensions; i++) {
		switch (Pandemonium::api->extensions[i]->type) {
			case GDNATIVE_EXT_NATIVESCRIPT: {
				Pandemonium::nativescript_api = (const pandemonium_gdnative_ext_nativescript_api_struct *)Pandemonium::api->extensions[i];

				/*
				const pandemonium_gdnative_api_struct *extension = Pandemonium::nativescript_api->next;

				while (extension) {
					if (extension->version.major == 1 && extension->version.minor == 1) {
						//Pandemonium::nativescript_1_1_api = (const pandemonium_gdnative_ext_nativescript_1_1_api_struct *)extension;
					}

					extension = extension->next;
				}
				*/
			} break;
			case GDNATIVE_EXT_PLUGINSCRIPT: {
				Pandemonium::pluginscript_api = (const pandemonium_gdnative_ext_pluginscript_api_struct *)Pandemonium::api->extensions[i];
			} break;
			case GDNATIVE_EXT_ANDROID: {
				Pandemonium::android_api = (const pandemonium_gdnative_ext_android_api_struct *)Pandemonium::api->extensions[i];
			} break;
			case GDNATIVE_EXT_VIDEODECODER: {
				Pandemonium::videodecoder_api = (const pandemonium_gdnative_ext_videodecoder_api_struct *)Pandemonium::api->extensions[i];
			} break;
			case GDNATIVE_EXT_NET: {
				Pandemonium::net_api = (const pandemonium_gdnative_ext_net_api_struct *)Pandemonium::api->extensions[i];

				/*
				const pandemonium_gdnative_api_struct *extension = Pandemonium::net_api->next;

				while (extension) {
					if (extension->version.major == 3 && extension->version.minor == 2) {
						Pandemonium::net_3_2_api = (const pandemonium_gdnative_ext_net_3_2_api_struct *)extension;
					}

					extension = extension->next;
				}
				*/
			} break;

			default:
				break;
		}
	}

	// Initialize the `language_index` here since `__register_types()` makes use of it.
	pandemonium_instance_binding_functions binding_funcs = {};
	binding_funcs.alloc_instance_binding_data = wrapper_create;
	binding_funcs.free_instance_binding_data = wrapper_destroy;

	_RegisterState::language_index = Pandemonium::nativescript_api->pandemonium_nativescript_register_instance_binding_data_functions(binding_funcs);

	// register these now
	___register_types();
	___init_method_bindings();
}

void Pandemonium::gdnative_terminate(pandemonium_gdnative_terminate_options *options) {
	// reserved for future use.
}

void Pandemonium::gdnative_profiling_add_data(const char *p_signature, uint64_t p_time) {
	Pandemonium::nativescript_api->pandemonium_nativescript_profiling_add_data(p_signature, p_time);
}

void Pandemonium::nativescript_init(void *handle) {
	_RegisterState::nativescript_handle = handle;
}

void Pandemonium::nativescript_terminate(void *handle) {
	Pandemonium::nativescript_api->pandemonium_nativescript_unregister_instance_binding_data_functions(_RegisterState::language_index);
}
