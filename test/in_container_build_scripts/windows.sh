#!/bin/bash
set -e

# Currently the test project is inside the bindings project
# If you put the bindings project inside your library project, comment this out
cd test

scons platform=windows target=release bits=64 "$@"
scons platform=windows target=debug bits=64 "$@"

scons platform=windows target=release bits=32 "$@"
scons platform=windows target=debug bits=32 "$@"

