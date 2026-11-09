#!/bin/bash
set -e

basedir=$(pwd)/

lib_name=libgdexample
output_folder=test/bin/

# Currently the test project is inside the bindings project
# If you put the bindings project inside your library project, comment this out
cd ..

project_root=$(pwd)/
img_version=pe

mkdir -p logs

custom_envvars=''

#export OFFICIAL=1;./build_all.sh

if [[ ! -z "${OFFICIAL}" ]]; then
	echo "OFFICIAL BUILD SET"
  custom_envvars='-e BUILD_NAME=official'
fi

#export NIGHTLY=1;./build_all.sh

if [[ ! -z "${NIGHTLY}" ]]; then
	echo "NIGHTLY BUILD SET"
  custom_envvars='-e BUILD_NAME=nightly'
fi

# Linux Build
docker run ${custom_envvars} \
        -v ${basedir}/in_container_build_scripts:/root/in_container_build_scripts \
        -v ${project_root}:/root/project \
        -w /root/project pandemonium-linux:${img_version} \
        bash /root/in_container_build_scripts/linux.sh "$@" 2>&1 | tee logs/linux.log

# Windows Build
docker run ${custom_envvars} \
	      -v ${basedir}/in_container_build_scripts:/root/in_container_build_scripts \
	      -v ${project_root}:/root/project \
	      -w /root/project pandemonium-windows:${img_version} \
	      bash /root/in_container_build_scripts/windows.sh "$@" 2>&1 | tee logs/windows.log

# TODO
# Javascript Build
#docker run ${custom_envvars} \
#        -v ${basedir}/in_container_build_scripts:/root/in_container_build_scripts \
#        -v ${project_root}:/root/project \
#        -w /root/project pandemonium-javascript:${img_version} \
#        bash /root/in_container_build_scripts/javascript.sh "$@" 2>&1 | tee logs/javascript.log

# TODO
# Android Build
#docker run ${custom_envvars} \
#        -v ${basedir}/in_container_build_scripts:/root/in_container_build_scripts \
#        -v ${project_root}:/root/project \
#        -w /root/project pandemonium-android:${img_version} \
#        bash /root/in_container_build_scripts/android.sh "$@" 2>&1 | tee logs/android.log
 
# TODO
# OSX Build
#docker run ${custom_envvars} \
#        -v ${basedir}/in_container_build_scripts:/root/in_container_build_scripts \
#        -v ${project_root}:/root/project \
#        -w /root/project pandemonium-osx:${img_version} \
#        bash /root/in_container_build_scripts/osx.sh "$@" 2>&1 | tee logs/osx.log

# TODO
# iOS Build
#docker run ${custom_envvars} \
#        -v ${basedir}/in_container_build_scripts:/root/in_container_build_scripts \
#        -v ${project_root}:/root/project \
#        -w /root/project pandemonium-appleembedded:${img_version} \
#        bash /root/in_container_build_scripts/ios.sh "$@" 2>&1 | tee logs/ios.log

# Check files

cd $output_folder

files=(
  # Windows
  "$lib_name.windows.debug.32.dll"
  "$lib_name.windows.release.32.dll"
  
  "$lib_name.windows.debug.32.dll"
  "$lib_name.windows.release.32.dll"

  # Linux
  "$lib_name.linux.debug.arm32v6.so"
  "$lib_name.linux.release.arm32v6.so"

  "$lib_name.linux.debug.arm32v7.so"
  "$lib_name.linux.release.arm32v7.so"

  "$lib_name.linux.debug.arm64v8.so"
  "$lib_name.linux.release.arm64v8.so"

  "$lib_name.linux.debug.x86_32.so"
  "$lib_name.linux.release.x86_32.so"

  "$lib_name.linux.debug.x86_64.so"
  "$lib_name.linux.release.x86_64.so"
)

error=0

for f in ${files[*]} 
do
if [ ! -e $f ]; then
  error=1
  echo "$f is not present!"
fi
done

if [ $error -eq 0 ]; then
  echo "All files are present!"
fi

cd ..
