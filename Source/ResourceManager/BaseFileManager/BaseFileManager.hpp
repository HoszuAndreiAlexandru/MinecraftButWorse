#pragma once
namespace fs = std::filesystem;

enum StreamType {
	READ,
	WRITE
};

class BaseFileManager {
private:
	#pragma region Base file stream handlers
	void throwFileException(std::string filePath, StreamType streamType);
	template<typename Stream>
	void checkFileStream(const Stream& file, std::string filePath, StreamType type);
	std::ifstream readFileStream(std::string filePath, std::ios::openmode mode);
	std::ofstream writeFileStream(std::string filePath, std::ios::openmode mode);
	#pragma endregion
public:
	BaseFileManager() = default;
	~BaseFileManager() = default;

	#pragma region String File I/O
	void readFileAsString(std::string filePath, std::string& output);
	void writeStringAsFile(std::string filePath, std::string fileContent);
	#pragma endregion

	#pragma region Binary File I/O
	void readFileAsBinary(std::string filePath, std::vector<char>& output);
	void writeBinaryAsFile(std::string filePath, const std::vector<char>& data);
	#pragma endregion

	#pragma region File utilities
	bool fileExists(const std::string& filePath) const;
	bool isReadable(const std::string& filePath) const;
	bool isWritable(const std::string& filePath) const;
	size_t getFileSize(const std::string& filePath) const;
	std::string getFileExtension(const std::string& filePath) const;
	std::string getFileName(const std::string& filePath) const;
	#pragma endregion

	#pragma region Directory utilities
	bool createDirectory(const std::string& dirPath) const;
	std::vector<std::string> listFilesInDirectory(const std::string& dirPath) const;
	#pragma endregion

	#pragma region Abstract Methods
	virtual bool loadFromFile(const std::string& filePath) = 0;
	virtual bool saveToFile(const std::string& filePath) = 0;
	#pragma endregion
};