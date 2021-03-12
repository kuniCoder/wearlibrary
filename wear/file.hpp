#pragma once
#include <fstream>
#include <string>

namespace wear {

    namespace file {
        using namespace wear;
        using namespace std;


        class FILE
        {
        public:
            enum FILESTAT
            {
                ERROR_OPENING   = 0x001A,
                UNKNOWN         = 0x002B,
                OK              = 0x003C,
                ADVENCED        = 0x004D,
            };


            string read(string directFile)
            {
                ifstream file;
                string read;
                file.open(directFile);
                if (file.is_open() && file.good()) {
                    while (getline(file, read));
                        statusFILE = FILESTAT::OK;
                }

                else if (!file.is_open())
                    statusFILE = FILESTAT::ERROR_OPENING;
                else if (!file.good())
                    statusFILE = FILESTAT::UNKNOWN;
                else if (!file.good() && !file.is_open())
                    statusFILE = FILESTAT::ADVENCED;

                

                file.close();   
                return read;
            } // reading file


            size_t status(string directFile) {
                return statusFILE;
            }


            void write(std::string directFile, std::string contentFile)
            {
                ofstream file;
                file.open(directFile);
                    if (file.is_open() && file.good()) 
                        file << contentFile;
                file.close();
            } // writing content file

            void append(std::string directFile, std::string contentFile)
            {
                ofstream file(directFile);
                file << read(directFile) + contentFile;
                file.close();
            } // additional file content

            bool Fdelete(string filename)
            {
                return remove(filename.c_str());
            } // delete file
        private:
            size_t statusFILE  = NULL;
        };
    } // namespace file
} // namespace wear