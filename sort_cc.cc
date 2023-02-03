#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/**
 * sort
 * Usage: io [INPUT [OUTPUT]]
 * If INPUT/OUTPUT is omitted, stdin/stdout is assumed
 */
int main(int argc, const char** argv) {
  std::ios::sync_with_stdio(false);
  std::string input = "-";
  std::string output = "-";

  if (argc >= 2) input = argv[1];
  if (argc >= 3) output = argv[2];
  if (input == "-") input = "/dev/stdin";
  if (output == "-") output = "/dev/stdout";

  std::ifstream ifs{input};
  std::ofstream ofs{output};

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(ifs, line)) {
    lines.push_back(std::move(line));
  }

  std::sort(std::begin(lines), std::end(lines));
  for (auto &line : lines) {
    ofs << line << "\n";
  }

  return 0;
}