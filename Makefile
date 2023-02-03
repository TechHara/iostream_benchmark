CC = clang++
all:
	$(CC) -O3 -std=c++11 -o iostream iostream.cc
	$(CC) -O3 -std=c++11 -o stdio stdio.cc

	$(CC) -O3 -std=c++11 -o sort_c sort_c.cc
	$(CC) -O3 -std=c++11 -o sort_cc sort_cc.cc

	rustc -C opt-level=3 rust_io.rs -o rust_io
	rustc -C opt-level=3 sort_rust.rs -o sort_rust
