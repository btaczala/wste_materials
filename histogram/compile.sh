#!/bin/bash

extra_flags="-Wno-error=return-local-addr"
debug_flags="-g -O2"
release_flags="-O2"

#flags="-std=c++14 -Wall -Wextra -Werror $extra_flags $release_flags"
flags="-std=c++14 -Wall -Wextra -Werror $extra_flags $debug_flags"
out_dir="build"
number_of_files=`find . -name "*.cxx" | wc -l`
extra_link_libraries='-lstdc++fs'
iterator=1
compiler=""

function really_compile() {
    file=$1
    find $out_dir -name "$file.o" -delete
    echo "[$iterator]/[$number_of_files] Compiling $file.cxx to $out_dir/$file.o"
    echo "  $compiler -c $flags $file.cxx -o $out_dir/$file.o"
    $compiler -c $flags $file.cxx -o $out_dir/$file.o > $out_dir/compile_$file.out 2>&1
    if [ ! "$?" == "0" ]; then
        echo "Compilation error"
        cat $out_dir/compile_$file.out
        exit
    else
        sha256sum $file.cxx > $out_dir/$file.sha256
    fi
}

function compile() {
    file=`basename $1 .cxx`
    if [ ! -e $out_dir/$file.sha256 ]; then
        really_compile $file
    else 
        sha_result=`sha256sum --quiet --status -c $out_dir/$file.sha256`
        if [ ! $? -eq 0 ]; then
            really_compile $file
        fi
    fi

    iterator=$((iterator + 1))
}

function link {
    echo "Linking histogram"
    echo " $compiler -m32 $out_dir/*.o -o $out_dir/histogram $extra_link_libraries"
    $compiler -m32 $out_dir/*.o -o $out_dir/histogram $extra_link_libraries
}

mkdir -p $out_dir
compiler=$CXX

if [ "$compiler" == "" ]; then
    echo "Compiler not specified, defaulting to clang++"
    compiler="g++ -m32"
fi

for file in `find . -name "*.cxx"`; do
    compile `basename $file`
done

link

