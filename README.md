# pandemonium-cpp

This repository contains the  *C++ bindings* for the [**Pandemonium Engine**](https://github.com/pandemoniumengine/pandemonium)'s GDNative API.

- [**Versioning**](#versioning)
- [**Contributing**](#contributing)
- [**Getting Started**](#getting-started)
- [**Creating a simple class**](#creating-a-simple-class)

## Versioning

This repositories follows the same branch versioning as the main [Pandemonium Engine
repository](https://github.com/pandemoniumengine/pandemonium):

- `master` tracks the current development branch.
- `3.x` tracks the development of the next 3.x minor release.
- Other versioned branches (e.g. `3.3`, `3.2`) track the latest stable release
  in the corresponding branch.

Stable releases are also tagged on this repository:
[**Tags**](https://github.com/pandemoniumengine/pandemonium-cpp/tags).

**For any project built against a stable release of Pandemonium, we recommend using
this repository as a Git submodule, checking out the specific tag matching your
Pandemonium version.**

> As the `master` and `3.x` branches are constantly getting updates, if you are
> using `pandemonium-cpp` against a more current version of Pandemonium, see the instructions
> in [**pandemonium_headers**](https://github.com/pandemoniumengine/pandemonium_headers) for
> updating the relevant files.

## Contributing

We greatly appreciate help in maintaining and extending this project. If you
wish to help out, ensure you have an account on GitHub and create a "fork" of
this repository. Rémi "Akien" Verschelde wrote an excellent bit of documentation
for the main Pandemonium project on this:
[Pull request workflow](https://docs.pandemoniumengine.org/en/stable/community/contributing/pr_workflow.html)

Please install clang-format and copy the files in `misc/hooks` into `.git/hooks`
so formatting is done before your changes are submitted.

## Getting Started

| **Build latest version of Pandemonium** | [**GitHub**](https://github.com/pandemoniumengine/pandemonium) | [**Docs**](https://pandemonium.readthedocs.io/en/latest/development/compiling/index.html) |
| --- | --- | --- |

### Setting up a new project

We recommend using Git for managing your project. The instructions below assume
you're using Git. Alternatively, you can download the source code directly from
GitHub. In this case, you need to download both
[pandemonium-cpp](https://github.com/pandemoniumengine/pandemonium-cpp) and
[pandemonium_headers](https://github.com/pandemoniumengine/pandemonium_headers).

```bash
mkdir SimpleLibrary
cd SimpleLibrary
mkdir bin
mkdir src
git clone --recursive https://github.com/pandemoniumengine/pandemonium-cpp
```

If you wish to use a specific branch, add the -b option to the clone command:

```bash
git clone --recursive https://github.com/pandemoniumengine/pandemonium-cpp -b 3.0
```

If your project is an existing repository, use a Git submodule instead:

```bash
git submodule add https://github.com/pandemoniumengine/pandemonium-cpp
git submodule update --init --recursive
```

Right now, our directory structure should look like this:

```text
SimpleLibrary/
├─pandemonium-cpp/
| └─pandemonium_headers/
├─bin/
└─src/
```

### Updating the `api.json` file

Our `api.json` file contains metadata for all the classes that are part of the
Pandemonium core. This metadata is required to generate the C++ binding classes for
use in GDNative modules.

This file is supplied with our
[pandemonium_headers](https://github.com/pandemoniumengine/pandemonium_headers) repository
for your convenience. However, if you're running a custom build of Pandemonium and
need access to classes that have recent changes, you must generate a new
`api.json` file. You do this by starting your Pandemonium executable with the
following parameters:

```bash
pandemonium --gdnative-generate-json-api api.json
```

Now copy the `api.json` file into your folder structure to make it easier to
access.

See the remark below for the extra ```custom_api_file``` SCons argument, which
is required to tell SCons where to find your file.

### Compiling the C++ bindings library

The final step is to compile our C++ bindings library:

```bash
cd pandemonium-cpp
scons platform=<your platform> generate_bindings=yes
cd ..
```

Replace `<your platform>` with either `windows`, `linux`, `osx` or `android`. If
you leave out `platform`, the target platform will automatically be detected
from the host platform.

The resulting library will be created in `pandemonium-cpp/bin/`, take note of its name
as it'll differ depending on the target platform.

#### Compiling for Android

Download the latest [Android NDK](https://developer.android.com/ndk/downloads)
and set the NDK path.

```bash
scons platform=android generate_bindings=yes ANDROID_NDK_ROOT="/PATH-TO-ANDROID-NDK/" android_arch=<arch>
```

The value of `android_arch` can be `armv7, arm64v8, x86, x86_64`. Most Android
devices in use nowadays use an ARM architecture, so compiling for `armv7` and
`arm64v8` is often enough when distributing an application.

`ANDROID_NDK_ROOT` can also be set in the environment variables of your PC if
you don't want to include it in your SCons call.

#### Compilation options

You can optionally add the following options to the SCons command line:

- When targeting Linux, add `use_llvm=yes` to use Clang instead of GCC.
- When targeting Windows, add `use_mingw=yes` to use MinGW instead of MSVC.
- When targeting Windows, include `target=runtime` to build a runtime build.
- To use an alternative `api.json` file, add `use_custom_api_file=yes
  custom_api_file=../api.json`. Be sure to specify the correct location where
  you placed your file (it can be a relative or absolute path).

## Creating a simple class

Create `init.cpp` under `SimpleLibrary/src/` and add the following code:

```cpp
#include <pandemonium.h>
#include <Reference.h>

using namespace pandemonium;

class SimpleClass : public Reference {
    PANDEMONIUM_CLASS(SimpleClass, Reference);
public:
    SimpleClass() { }

    /** `_init` must exist as it is called by Pandemonium. */
    void _init() { }

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
         *     export var _name = "SimpleClass"
         **/
        register_property<SimpleClass, String>("base/name", &SimpleClass::_name, String("SimpleClass"));

        /** Alternatively, with getter and setter methods: */
        register_property<SimpleClass, int>("base/value", &SimpleClass::set_value, &SimpleClass::get_value, 0);

        /** Registering a signal: **/
        // register_signal<SimpleClass>("signal_name");
        // register_signal<SimpleClass>("signal_name", "string_argument", PANDEMONIUM_VARIANT_TYPE_STRING)
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
    pandemonium::Pandemonium::gdnative_init(o);
}

/** GDNative Terminate **/
extern "C" void GDN_EXPORT pandemonium_gdnative_terminate(pandemonium_gdnative_terminate_options *o) {
    pandemonium::Pandemonium::gdnative_terminate(o);
}

/** NativeScript Initialize **/
extern "C" void GDN_EXPORT pandemonium_nativescript_init(void *handle) {
    pandemonium::Pandemonium::nativescript_init(handle);

    pandemonium::register_class<SimpleClass>();
}
```

### Compiling the GDNative library

Once you've compiled the GDNative C++ bindings (see above), you can compile the GDNative library we've just created.

#### Linux

```bash
cd SimpleLibrary
clang++ -fPIC -o src/init.o -c src/init.cpp -g -O3 -std=c++14 -Ipandemonium-cpp/include -Ipandemonium-cpp/include/core -Ipandemonium-cpp/include/gen -Ipandemonium-cpp/pandemonium_headers
clang++ -o bin/libtest.so -shared src/init.o -Lpandemonium-cpp/bin -l<name of the pandemonium-cpp>
```

You'll need to replace `<name of the pandemonium-cpp>` with the file that was created in [**Compiling the cpp bindings library**](#compiling-the-cpp-bindings-library).

This creates the file `libtest.so` in your `SimpleLibrary/bin` directory.

#### Windows

```bash
cd SimpleLibrary
cl /Fosrc/init.obj /c src/init.cpp /nologo -EHsc -DNDEBUG /MDd /Ipandemonium-cpp\include /Ipandemonium-cpp\include\core /Ipandemonium-cpp\include\gen /Ipandemonium-cpp\pandemonium_headers
link /nologo /dll /out:bin\libtest.dll /implib:bin\libsimple.lib src\init.obj pandemonium-cpp\bin\<name of the pandemonium-cpp>
```

You'll need to replace `<name of the pandemonium-cpp>` with the file that was created
in [**Compiling the cpp bindingslibrary**](#compiling-the-cpp-bindings-library).
Replace `/MDd` with `/MD` to create a release build, which will run faster and
be smaller.

This creates the file `libtest.dll` in your `SimpleLibrary/bin` directory.

#### macOS

For macOS, you'll need to find out which compiler flags need to be used. These
are likely similar to Linux when using Clang, but may not be identical.

If you find suitable compiler flags for this example library, feel free to
submit a pull request :slightly_smiling_face:

#### Android

```bash
cd SimpleLibrary
aarch64-linux-android29-clang++ -fPIC -o src/init.o -c src/init.cpp -g -O3 -std=c++14 -Ipandemonium-cpp/include -Ipandemonium-cpp/include/core -Ipandemonium-cpp/include/gen -Ipandemonium-cpp/pandemonium_headers
aarch64-linux-android29-clang++ -o bin/libtest.so -shared src/init.o -Lpandemonium-cpp/bin -l<name of the pandemonium-cpp>
```

You'll need to replace `<name of the pandemonium-cpp>` with the file that was created in [**Compiling the cpp bindings library**](#compiling-the-cpp-bindings-library). The command above targets `arm64v8`. To target `armv7`, use `armv7a-linux-androideabi29-clang++` instead of `aarch64-linux-android29-clang++`.

This creates the file `libtest.so` in your `SimpleLibrary/bin` directory.

#### iOS

GDNative isn't supported on iOS yet. This is because iOS only allows linking
static libraries, not dynamic libraries. In theory, it would be possible to link
a GDNative library statically, but some of GDNative's convenience would be lost
in the process as one would have to recompile the engine on every change. See
[issue #30](https://github.com/pandemoniumengine/pandemonium_headers/issues/30) in the
Pandemonium headers repository for more information.

#### HTML5

GDNative is supported on [specific exports](https://docs.pandemoniumengine.org/en/latest/tutorials/export/exporting_for_web.html#export-options) for the HTML5 platform since Pandemonium `3.3`. Linking webassembly modules is currently underspecified in the standard, but [emscripten](https://emscripten.org/), which Pandemonium uses to build the HTML5 version, implements its own linking system.

To build GDNative libraries, you will need a recent version of [Emscripten](https://emscripten.org/).

```bash
cd SimpleLibrary
emcc  -o bin/libtest.wasm -g -O3 -s SIDE_MODULE=1 src/init.cpp pandemonium-cpp/bin/<name of the pandemonium-cpp> -Ipandemonium-cpp/include -Ipandemonium-cpp/include/core -Ipandemonium-cpp/include/gen -Ipandemonium-cpp/pandemonium_headers
```

You'll need to replace `<name of the pandemonium-cpp>` with the file that was created in [**Compiling the cpp bindings library**](#compiling-the-cpp-bindings-library).

This creates the file `libtest.so` in your `SimpleLibrary/bin` directory.

### Creating `.gdnlib` and `.gdns` files

Follow the instructions in
[pandemonium_headers/README.md](https://github.com/pandemoniumengine/pandemonium_headers/blob/master/README.md#how-do-i-use-native-scripts-from-the-editor)
to create the `.gdns` file. This file contains paths to GDNative libraries for
various platforms. This makes the library usable from Pandemonium in a
platform-independent manner.

### Implementing with GDScript

Once your GDNative library is compiled and referenced in a `.gdns` file, you can use it in GDScript or C#. Here's an example with GDScript:

```gdscript
var simpleclass = load("res://simpleclass.gdns").new()
simpleclass.method("Test argument")
```

### Using Pandemonium classes in C++

Pandemonium expects you to manage its classes the same way the engine does. These rules apply to all Pandemonium classes, including your NativeScripts, but not to any normal C++ classes used in your library.

- Instantiate Objects using `_new()`, not C++'s `new` operator.

```cpp
Sprite *sprite = Sprite::_new();
```

- Destroy Nodes using `queue_free()`, not C++'s `delete` operator.

```cpp
some_old_node->queue_free();
```

- Wrap References in `Ref` instead of passing around raw pointers. They are reference-counted and don't need to be freed manually.

```cpp
Ref<Texture> texture = resource_loader->load("res://icon.png");
```

- Pass core types that do *not* inherit Object by value. The containers (Array, Dictionary, PoolArray, String) manage their own memory and do not need to be explicitly initialized or freed.

```cpp
Array ints;
ints.append(123);
return ints;
```

- Initialize your NativeScript classes in their `_init()` method, not their constructor. The constructor can't access the base class's methods.

- Cast objects using `Object::cast_to`, not unsafe C-style casts or `static_cast`.

```cpp
MeshInstance *m = Object::cast_to<MeshInstance>(get_node("ChildNode"));
// `m` will be null if it's not a MeshInstance
if (m) { ... }
```

- **Never** use Pandemonium types in static or global variables. The Pandemonium API isn't loaded until after their constructors are called.

```cpp
String s; // crashes
class SomeClass {
    static Dictionary d; // crashes

    static Node *node_a = NULL; // fine, it's just a pointer
    static Node *node_b = Node::_new(); // crashes
};
```
