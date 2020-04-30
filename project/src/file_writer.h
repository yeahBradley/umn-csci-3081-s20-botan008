/**
 * @file file_writer.h
 *
 * @copyright 2020 3081 Staff, All rights reserved.
 */

#ifndef SRC_FILE_WRITER_H_
#define SRC_FILE_WRITER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class FileWriter {
    static FileWriter* file_writer_;
    std::ofstream bus_data_log_;
    std::ofstream pass_data_log_;

    /**
     * @brief FileWriter: Private constructor that opens two ofstream objects for logging data
     * 
     */
    FileWriter();

 public:
    /**
     * @brief GetInstance: This method ensures that only a single FileWriter object is created and returns it.
     * 
     * @return FileWriter*: Returns a pointer to the singleton FileWriter object
     * 
     */
    static FileWriter* GetInstance();
    /**
     * @brief WriteStream: This Stream version of the Write method takes a stream object as input instead of a vector
     * 
     * @param[in] std::string file_name: This string decides the log file to print the output to
     * @param[in] std::ostringstream& output: This is a stream container of the output for the log file.
     * 
     */
    void WriteStream(std::string file_name, std::ostringstream& output);
    /**
     * @brief ProccessOutputStream: This parses a stream to remove tabs, newlines, and spaces. Then inserts commas to separate the data
     * 
     * @param[in] std::ostringstream& out: The ostringstream object contains the data to be parsed.
     * 
     * @return std::ostringstream: This stream type is used to contain the data to be sent to the file writer.
     */
    std::ostringstream ProcessOutputStream(std::ostringstream& out);
    /**
     * @brief ~FileWriter: Deconstructor that closes both of the ofstream objects
     * 
     */
    virtual ~FileWriter();
};

#endif  // SRC_FILE_WRITER_H_
