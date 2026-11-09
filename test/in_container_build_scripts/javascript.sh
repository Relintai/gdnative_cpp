#!/bin/bash
set -e

# Currently the test project is inside the bindings project
# If you put the bindings project inside your library project, comment this out
cd test

source /root/emsdk/emsdk_env.sh


scons platform=javascript target=release "$@"
scons platform=javascript target=debug "$@"


