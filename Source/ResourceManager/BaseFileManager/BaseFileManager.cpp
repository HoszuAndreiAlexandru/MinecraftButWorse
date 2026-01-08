#pragma once
#include "pch.h"
#include "BaseFileManager.hpp"

#pragma region Base file stream handlers
void BaseFileManager::throwFileException(std::string filePath, StreamType streamAction)
{
	std::string streamActionStr = (streamAction == StreamType::READ) ? "read" : "write";
	throw std::runtime_error("Failed to " + streamActionStr + " file : " + filePath);
}

template<typename Stream>
void BaseFileManager::checkFileStream(const Stream& file, std::string filePath, StreamType type)
{
	if (!file.is_open())
	{
		this->throwFileException(filePath, type);
	}
}

std::ifstream BaseFileManager::readFileStream(std::string filePath, std::ios::openmode mode)
{
	std::ifstream file(filePath, mode);

	checkFileStream(file, filePath, StreamType::READ);

	return file;
}

std::ofstream BaseFileManager::writeFileStream(std::string filePath, std::ios::openmode mode)
{
	std::ofstream file(filePath, mode);

	checkFileStream(file, filePath, StreamType::WRITE);

	return file;
}
#pragma endregion

#pragma region String File I/O
void BaseFileManager::readFileAsString(std::string filePath, std::string& output)
{
	std::ifstream file = this->readFileStream(filePath, std::ios::binary);

	output.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

void BaseFileManager::writeStringAsFile(std::string filePath, std::string fileContent)
{
	std::ofstream file = this->writeFileStream(filePath, std::ios::out);

	file << fileContent;
}
#pragma endregion

#pragma region Binary File I/O
void BaseFileManager::readFileAsBinary(std::string filePath, std::vector<char>& output)
{
	std::ifstream file = this->readFileStream(filePath, std::ios::binary);

	file.seekg(0, std::ios::end);
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	output.resize(static_cast<size_t>(size));
	file.read(output.data(), size);
}

void BaseFileManager::writeBinaryAsFile(std::string filePath, const std::vector<char>& data)
{
	std::ofstream file = this->writeFileStream(filePath, std::ios::binary);

	file.write(data.data(), data.size());
}
#pragma endregion

#pragma region File utilities
bool BaseFileManager::fileExists(const std::string& filePath) const
{
	return fs::exists(filePath);
}

bool BaseFileManager::isReadable(const std::string& filePath) const
{
	std::ifstream file(filePath);
	return file.good();
}
bool BaseFileManager::isWritable(const std::string& filePath)  const
{
	std::ofstream file(filePath, std::ios::app);
	return file.good();
}
size_t BaseFileManager::getFileSize(const std::string& filePath)  const
{
	if (!fs::exists(filePath))
	{
		return 0;
	}

	return static_cast<size_t>(fs::file_size(filePath));
}

std::string BaseFileManager::getFileExtension(const std::string& filePath) const
{
	return fs::path(filePath).extension().string();
}

std::string BaseFileManager::getFileName(const std::string& filePath) const
{
	return fs::path(filePath).filename().string();
}
#pragma endregion

#pragma region Directory utilities
bool BaseFileManager::createDirectory(const std::string& dirPath) const
{
	if (fs::exists(dirPath))
	{
		return true;
	}

	return fs::create_directories(dirPath);
}

std::vector<std::string> BaseFileManager::listFilesInDirectory(const std::string& dirPath) const
{
	std::vector<std::string> files;

	if (!fs::exists(dirPath) || !fs::is_directory(dirPath))
	{
		return files;
	}

	for (const auto& entry : fs::directory_iterator(dirPath))
	{
		if (fs::is_regular_file(entry))
		{
			files.push_back(entry.path().string());
		}
	}
	return files;
}
#pragma endregion