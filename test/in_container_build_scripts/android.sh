#!/bin/bash
set -e

# Currently the test project is inside the bindings project
# If you put the bindings project inside your library project, comment this out
cd test


scons platform=android android_arch=armv7 target=release "$@"
scons platform=android android_arch=armv7 target=debug "$@"

scons platform=android android_arch=arm64v8 target=release "$@"
scons platform=android android_arch=arm64v8 target=debug "$@"

scons platform=android android_arch=x86 target=release "$@"
scons platform=android android_arch=x86 target=debug "$@"

scons platform=android android_arch=x86_64 target=release "$@"
scons platform=android android_arch=x86_64 target=debug "$@"


