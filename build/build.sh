#!/bin/sh
export BUILD=`pwd`
export SRC_DIR=${BUILD}/..
export LIBRARY_PATH=${LIBRARY_PATH}:${SRC_DIR}/stack:${SRC_DIR}/string:${SRC_DIR}/common
export LIBRARY_PATH=${LIBRARY_PATH}:${SRC_DIR}/stack:${SRC_DIR}/string:${SRC_DIR}/common
echo ${BUILD}
echo ${SRC_DIR}
echo "LIBRARY_PATH:"
echo ${LIBRARY_PATH}
echo "---------------start cmake---------------"
cmake ..

echo "---------------start make---------------"
make

