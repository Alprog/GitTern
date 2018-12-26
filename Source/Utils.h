
#pragma once

#include <string>
#include <vector>

std::vector<std::string> split(std::string string, std::string separator);
std::string join(std::vector<std::string> vector, std::string separator);
void replace(std::string& string, std::string oldValue, std::string newValue);
bool startsWith(const std::string& string, const std::string& pattern);
bool endsWith(const std::string& string, const std::string& pattern);
