#!/bin/bash
set -e

# Currently the test project is inside the bindings project
# If you put the bindings project inside your library project, comment this out
cd test

export PATH="${PANDEMONIUN_SDK_LINUX_X86_64}/bin:${BASE_PATH}"

scons platform=linux target=release custom_arch_suffix="x86_64" "$@"
scons platform=linux target=debug custom_arch_suffix="x86_64" "$@"

export PATH="${PANDEMONIUN_SDK_LINUX_X86_32}/bin:${BASE_PATH}"

scons platform=linux target=release custom_arch_suffix="x86_32" "$@"
scons platform=linux target=debug custom_arch_suffix="x86_32" "$@"

export PATH="${PANDEMONIUN_SDK_LINUX_ARM64}/bin:${BASE_PATH}"

scons platform=linux target=release custom_arch_suffix="arm64v8" "$@"
scons platform=linux target=debug custom_arch_suffix="arm64v8" "$@"

export PATH="${PANDEMONIUN_SDK_LINUX_ARMV7}/bin:${BASE_PATH}"

scons platform=linux target=release custom_arch_suffix="arm32v7" "$@"
scons platform=linux target=debug custom_arch_suffix="arm32v7" "$@"

export PATH="${PANDEMONIUN_SDK_LINUX_ARMV6}/bin:${BASE_PATH}"

scons platform=linux target=release custom_arch_suffix="arm32v6" "$@"
scons platform=linux target=debug custom_arch_suffix="arm32v6" "$@"
