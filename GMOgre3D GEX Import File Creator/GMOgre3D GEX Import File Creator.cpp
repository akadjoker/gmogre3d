// GMOger3D GEX Import File Creator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


void Tokenize(const std::string &str, std::vector<std::string> &tokens, const std::string& delimiters = " ")
{
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}


int _tmain(int argc, _TCHAR* argv[])
{
   std::string scripts_filename;
   std::string constants_filename;
   std::string gexscripts_filename;
   std::string gexconstants_filename;
   std::string line;

   if (argc <= 4)
   {
      std::cout << "Usage: GEXCreator scripts.gml constants.gml gexscripts.txt gexconstants.txt" << std::endl;
      return -1;
   }

   if (argc >= 1)
      scripts_filename = argv[1];
   if (argc >= 2)
      constants_filename = argv[2];
   if (argc >= 3)
      gexscripts_filename = argv[3];
   if (argc >= 4)
      gexconstants_filename = argv[4];

   std::ifstream scripts_file(scripts_filename.c_str());
   std::ifstream constants_file(constants_filename.c_str());
   std::ofstream gexscripts_file(gexscripts_filename.c_str());
   std::ofstream gexconstants_file(gexconstants_filename.c_str());

   if (!scripts_file.is_open())
   {
      std::cout << "Error: Cannot find the specified GML scripts file." << std::endl;
      return -1;
   }

   if (!constants_file.is_open())
   {
      std::cout << "Error: Cannot find the specified GML constants file." << std::endl;
      return -1;
   }

   if (!gexscripts_file.is_open())
   {
      std::cout << "Error: Cannot create the specified GEX scripts import file." << std::endl;
      return -1;
   }

   if (!gexconstants_file.is_open())
   {
      std::cout << "Error: Cannot create the specified GEX constants import file." << std::endl;
      return -1;
   }

   while(std::getline(scripts_file, line))
   {
      if (line.find("#define ") == 0)
      {
         // Parse out our function name
         std::string function = line.replace(0, 8, "");

         gexscripts_file << "kind dll-cdecl" << std::endl;
         gexscripts_file << "function " << function;

         int count = 0;
         bool found = false;
         while(std::getline(scripts_file, line))
         {
            // See if this is a value funtion definition
            if (line.find("(") != std::string::npos && line.find(")") != std::string::npos)
            {
               found = true;
               break;
            }

            // If we parsed more than 10 lines without finding our function definition, then
            // we just ain't gonna find it.
            if (count > 10)
               break;

            count++;
         }

         if (found)
         {
            std::vector<std::string> tokens;

            // Remove function parens
            line.replace(0, line.find("(") + 1, "");
            line.replace(line.find(")"), 1, "");

            // Tokenize our parameters
            Tokenize(line, tokens);
            std::string var_type = "unknown";
            count = 0;

            gexscripts_file << "(";
            for (int x = 0; x < tokens.size(); x++)
            {
               // Remove any commas
               if (tokens[x].find(",") != std::string::npos)
                  tokens[x] = tokens[x].replace(tokens[x].find(","), 1, "");
               
               // Either save type or...
               if (tokens[x] == "real" || tokens[x] == "string")
                  var_type = tokens[x];
               else
               {
                  // Write parameter and type
                  if (count > 0)
                     gexscripts_file << ",";

                  gexscripts_file << tokens[x] << ":" << var_type;
                  var_type = "unknown";
                  count++;
               }
            }
            gexscripts_file << ")" << std::endl;
         }
         else
         {
            gexscripts_file << "()" << std::endl;
         }
      }
   }

   scripts_file.close();
   gexscripts_file.close();

   while(std::getline(constants_file, line))
   {
      if (line.find("global.") != std::string::npos)
      {
         if (line.find("=") != std::string::npos)
         {
            std::string constant = line.replace(0, line.find("global.") + 7, "");
            constant = constant.substr(0, constant.find("="));

            std::string value = line.replace(0, line.find("=") + 1, "");

            // Replace double quotes with single quots
            while (value.find("\"") != std::string::npos)
               value = value.replace(value.find("\""), 1, "'");

            // Remove ;
            value = value.replace(value.find(";"), 1, "");

            gexconstants_file << "const " << constant << " = ";
            gexconstants_file << value << std::endl;
         }
      }
   }

   gexconstants_file.close();

	return 0;
}

