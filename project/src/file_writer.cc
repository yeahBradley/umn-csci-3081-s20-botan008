/**
 * @file file_writer.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/file_writer.h"

FileWriter *FileWriter::file_writer_ = NULL;

FileWriter::FileWriter() {
    bus_data_log_.open("BusData.csv");
    pass_data_log_.open("PassData.csv");
}

FileWriter::~FileWriter() {
    bus_data_log_.close();
    pass_data_log_.close();
}

FileWriter* FileWriter::GetInstance() {
    if (!file_writer_) {
        file_writer_ = new FileWriter;
    }
    return file_writer_;
}

void FileWriter::WriteStream(std::string file_name,
std::ostringstream& output) {
    if (file_name == "BusData.csv") {
        bus_data_log_ << output.str() << std::endl;
    } else if (file_name == "PassData.csv") {
        pass_data_log_ << output.str() << std::endl;
    }
}

std::ostringstream FileWriter::ProcessOutputStream(std::ostringstream& out) {
    std::string temp = out.str();
    out.str("");

    std::ostringstream csv_formatted;

    std::string delim_space = " ";
    std::string delim_tab = "\t";
    std::string delim_newline = "\n";
    std::string token;
    size_t pos = 0;

    while ((pos = temp.find(delim_newline)) != std::string::npos) {
        token = temp.substr(0, pos);
        csv_formatted << token << " ";
        temp.erase(0, pos + delim_newline.length());
    }
    csv_formatted << temp;

    temp = csv_formatted.str();
    csv_formatted.str("");

    pos = 0;
    while ((pos = temp.find(delim_tab)) != std::string::npos) {
        token = temp.substr(0, pos);
        csv_formatted << token;
        temp.erase(0, pos + delim_tab.length());
    }
    csv_formatted << temp;

    temp = csv_formatted.str();
    csv_formatted.str("");

    pos = 0;
    while ((pos = temp.find(delim_space)) != std::string::npos) {
        token = temp.substr(0, pos);
        csv_formatted << token << ",";
        temp.erase(0, pos + delim_space.length());
    }
    csv_formatted << temp;

    return csv_formatted;
}
