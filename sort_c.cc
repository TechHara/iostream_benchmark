#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

int comp(const void* a, const void* b) {
  return std::strcmp(*(const char**)a, *(const char**)b);
}

/**
 * sort
 * Usage: io [INPUT [OUTPUT]]
 * If INPUT/OUTPUT is omitted, stdin/stdout is assumed
 */
int main(int argc, const char** argv) {
  std::string input = "-";
  std::string output = "-";

  if (argc >= 2) input = argv[1];
  if (argc >= 3) output = argv[2];
  if (input == "-") input = "/dev/stdin";
  if (output == "-") output = "/dev/stdout";

  FILE* ifs = fopen(input.data(), "r");
  FILE* ofs = fopen(output.data(), "w");

  std::vector<char*> lines;
  while (true) {
    char* line = nullptr;
    size_t capacity;
    auto n = getline(&line, &capacity, ifs);
    if (n <= 0) break;
    lines.push_back(line);
  }

  std::sort(std::begin(lines), std::end(lines), [](char* a, char* b) {
    return std::strcmp(a, b) < 0;
  });

  for (auto &line : lines) {
    fprintf(ofs, "%s", line);
    free(line);
  }
  fclose(ifs);
  fclose(ofs);

  return 0;
}
