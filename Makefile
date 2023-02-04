CC = clang++
CPPFLAGS = -O3 -std=c++11 -Wall
all:
	$(CC) $(CPPFLAGS) -o iostream iostream.cc
	$(CC) $(CPPFLAGS) -o stdio stdio.cc
	rustc -C opt-level=3 rust_io.rs -o rust_io

	$(CC) $(CPPFLAGS) -o sort_c sort_c.cc
	$(CC) $(CPPFLAGS) -o sort_cc sort_cc.cc
	rustc -C opt-level=3 sort_rust.rs -o sort_rust
