#include <string>
#include <fstream>
#include <vector>

class FileManager
{
public:
	static std::vector<std::string> readFile(std::string path);
	static void writeFile(std::string path, std::vector<std::string> strs);
	static std::vector<std::string> split(std::string str, char sep);
};