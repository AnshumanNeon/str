compiler = gcc-9
libtool = libtool

compiler_flags = -Wall -Werror -Wpedantic -Wextra

build_dir = build
target = libstr.a

$(build_dir)/$(target): $(build_dir)/str.o
	$(libtool) -static $(build_dir)/str.o -o $@

$(build_dir)/str.o:
	mkdir -p build/
	$(compiler) $(compiler_flags) -c str.c -o $(build_dir)/str.o

.PHONY: $(obj_files) $(build_dir)/$(target) clean

clean:
	rm -rf build/
