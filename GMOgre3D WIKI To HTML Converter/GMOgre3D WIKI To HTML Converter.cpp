// GMOger3D GEX Import File Creator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>


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


std::string ReplaceSummary(std::string line)
{
   std::size_t index1 = std::string::npos;

   index1 = line.find("#summary");

   if (index1 == 0)
      line = line.replace(0, 9, "<div style=""font-style:italic; margin-top: 3px"">") + "</div>" ;

   return line;
}


std::string ReplaceHeaderTags(std::string line, std::string wiki_tag1, std::string html_tag1, std::string wiki_tag2, std::string html_tag2)
{
   std::size_t index1 = std::string::npos;
   std::size_t index2 = std::string::npos;

   index1 = line.find(wiki_tag1);
   if (index1 != 0)
      return line;

   line = line.replace(index1, wiki_tag1.length(), html_tag1);

   index2 = line.find(wiki_tag2);

   if (index2 != std::string::npos)
      line = line.replace(index2, wiki_tag2.length(), html_tag2);

   index1 = line.find(html_tag1);
   index2 = line.find(html_tag2);
   std::string header_text = line.substr(index1 + html_tag1.length(), index2 - (index1 + html_tag1.length()));

   if (header_text[header_text.length()-1] == ' ')
      header_text = header_text.erase(header_text.length() - 1, 1);

   if (header_text[0] == ' ')
      header_text = header_text.erase(0, 1);

   line = html_tag1 + "<a name=\"" + header_text + "\"/>" + header_text + "<a href=\"#" + header_text + "\"></a>" + html_tag2;

   return line;
}


std::string ReplaceTags(std::string line, std::string wiki_tag1, std::string html_tag1, std::string wiki_tag2, std::string html_tag2)
{
   std::size_t index1;
   std::size_t index2;

   do
   {
      index1 = std::string::npos;
      index2 = std::string::npos;

      index1 = line.find(wiki_tag1);
      if (index1 != std::string::npos)
         line = line.replace(index1, wiki_tag1.length(), html_tag1);

      if (wiki_tag2.length() > 0)
      {
         index2 = line.find(wiki_tag2);

         if (index2 != std::string::npos)
            line = line.replace(index2, wiki_tag2.length(), html_tag2);
      }
   }
   while (index1 != std::string::npos && (index2 != std::string::npos || wiki_tag2.length() == 0));

   return line;
}


std::string ReplaceUnderscoreTags(std::string line)
{
   std::size_t index1;
   std::size_t index2;

   do
   {
      index1 = std::string::npos;
      index2 = std::string::npos;

      index1 = line.find(" _");
      if (index1 == std::string::npos)
         return line;

      line = line.replace(index1, 2, " <i>");

      index2 = 0;
      do
      {
         index2 = line.find("_", index2 + 1);

         if (index2 != std::string::npos)
         {
            // Check end of line
            if (index2 + 1 == line.length())
               break;
            // Check space or comma or quote
            if (line[index2 + 1] == ' ' || line[index2 + 1] == ','|| line[index2 + 1] == '\'')
               break;
         }
      } while (index2 != std::string::npos);

      if (index2 != std::string::npos)
         line = line.replace(index2, 1, "</i>");
   }
   while (index1 != std::string::npos && index2 != std::string::npos);

   return line;
}


std::string ReplaceHyperlinks(std::string line)
{
   std::size_t index1 = std::string::npos;
   std::size_t index2 = std::string::npos;

   index1 = line.find("[#");

   if (index1 != std::string::npos)
   {
      index2 = line.find("]", index1);

      if (index2 != std::string::npos)
      {
         std::size_t hyperlink_index = line.find(" ", index1);

         std::string hyperlink = line.substr(index1 + 2, hyperlink_index - (index1 + 2));
         std::string text = line.substr(hyperlink_index + 1, index2 - hyperlink_index - 1);
         line = line.replace(index1, index2 - index1 + 1, "<a href=\"#" + hyperlink + "\">" + text + "</a>");
      }
   }
   else
   {
      index1 = line.find("[http");

      if (index1 != std::string::npos)
      {
         index2 = line.find("]", index1);

         if (index2 != std::string::npos)
         {
            std::size_t hyperlink_index = line.find(" ", index1);

            std::string hyperlink = line.substr(index1 + 5, hyperlink_index - (index1 + 5));
            std::string text = line.substr(hyperlink_index + 1, index2 - hyperlink_index - 1);
            line = line.replace(index1, index2 - index1 + 1, "<a href=\"http" + hyperlink + "\">" + text + "</a>");
         }
      }
      //<a href="/p/gmogre3d/wiki/MaterialScripts">Material Scripts</a>
   }
   /*
   else
   {
      index1 = line.find("[");

      if (index1 != std::string::npos)
      {
         index2 = line.find("]", index1);

         if (index2 != std::string::npos)
         {
            std::size_t hyperlink_index = line.find(" ", index1);

            std::string hyperlink = line.substr(index1 + 2, hyperlink_index - (index1 + 2));
            std::string text = line.substr(hyperlink_index + 1, index2 - hyperlink_index - 1);
            line = line.replace(index1, index2 - index1 + 1, "<a href=\"" + hyperlink + ".html\">" + text + "</a>");
         }
      }
      //<a href="/p/gmogre3d/wiki/MaterialScripts">Material Scripts</a>
   }
   */
   return line;
}

//<a href="#scheme">scheme</a>

int _tmain(int argc, _TCHAR* argv[])
{
   std::string wiki_folder;
   std::string html_folder;
   std::string line;

   if (argc < 3)
   {
      std::cout << "Usage: WikiToHtmlConverter.exe sourcefolder targetfolder" << std::endl;
      return -1;
   }

   if (argc >= 2)
      wiki_folder = argv[1];
   if (argc >= 3)
      html_folder = argv[2];

   WIN32_FIND_DATA FindFileData;
   HANDLE hFind = INVALID_HANDLE_VALUE;
   bool found_file = false;

   wiki_folder += "\\";
   html_folder += "\\";

   hFind = FindFirstFile(std::string(wiki_folder + "*.wiki").c_str(), &FindFileData);
   if (hFind != INVALID_HANDLE_VALUE)
      found_file = true;

   while (found_file)
   {
      std::string wiki_filename = wiki_folder + FindFileData.cFileName;
      std::string html_filename = html_folder + FindFileData.cFileName;

      html_filename = html_filename.replace(html_filename.find(".wiki"), 5, ".html");

      std::ifstream wiki_file(wiki_filename.c_str());
      std::ofstream html_file(html_filename.c_str());

      if (!wiki_file.is_open())
      {
         std::cout << "Error: Cannot open the the WIKI file." << wiki_filename << std::endl;
         return -1;
      }

      if (!html_file.is_open())
      {
         std::cout << "Error: Cannot create the HTML file." << html_filename << std::endl;
         return -1;
      }

      bool start_first_list = false;
      bool start_second_list = false;
      bool start_code = false;

      html_file << "<html>" << std::endl;
      html_file << "<body>" << std::endl;
      html_file << "<font size=""2"" face=""sans-serif"">" << std::endl;

      while(std::getline(wiki_file, line))
      {
         if (line.find("{{{") != std::string::npos)
         {
            start_code = true;
            line = ReplaceTags(line, "{{{", "<code><BR>", "", "");

            if (start_second_list == true)
            {
               line = "</ul>" + line;
               start_second_list = false;
            }
            if (start_first_list == true)
            {
               line = "</ul>" + line;
               start_first_list = false;
            }
         }
         if (line.find("}}}") != std::string::npos)
         {
            start_code = false;
            line = ReplaceTags(line, "}}}", "</code><BR>", "", "");
         }

         if (!start_code)
         {
            line = ReplaceHeaderTags(line, "======", "<h6>", "======", "</h6>");
            line = ReplaceHeaderTags(line, "=====", "<h5>", "=====", "</h5>");
            line = ReplaceHeaderTags(line, "====", "<h4>", "====", "</h4>");
            line = ReplaceHeaderTags(line, "===", "<h3>", "===", "</h3>");
            line = ReplaceHeaderTags(line, "==", "<h2>", "==", "</h2>");
            line = ReplaceHeaderTags(line, "=", "<h1>", "=", "</h1>");

            line = ReplaceHyperlinks(line);

            line = ReplaceTags(line, "!", "", "", "");
            line = ReplaceTags(line, "----", "<hr/>", "", "");
            
            line = ReplaceUnderscoreTags(line);

            if (line.find("  *") != std::string::npos)
            {
               bool start_list = false;

               // Check if we're starting our first list
               if (line.find("  *") <= 2)
               {
                  if (start_second_list == true)
                  {
                     html_file << "</ul>" << std::endl;
                     start_second_list = false;
                  }
                  if (start_first_list == false)
                  {
                     start_list = true;
                     start_first_list = true;
                  }
               }
               else
               {
                  if (start_second_list == false)
                  {
                     start_list = true;
                     start_second_list = true;
                  }
               }

               if (start_list == true)
                  line = "<ul><li>" + line.replace(0, line.find("*") + 1, "") + "</li>";
               else
                  line = "<li>" + line.replace(0, line.find("*") + 1, "") + "</li>";
            }
            else if (start_second_list == true)
            {
               line = "</ul>" + line;
               start_second_list = false;
            }
            else if (start_first_list == true)
            {
               line = "</ul>" + line;
               start_first_list = false;
            }

            if (line.empty())
               line = "<p></p>";

            line = ReplaceTags(line, "*", "<b>", "*", "</b>");

            line = ReplaceSummary(line);
         }
         else
            line += "<BR>";


         html_file << line << std::endl;
      }

      html_file << "</font>" << std::endl;
      html_file << "</html>" << std::endl;
      html_file << "</body>" << std::endl;

      wiki_file.close();
      html_file.close();

      if (FindNextFile(hFind, &FindFileData) == 0)
         found_file = false;
   }

   FindClose(hFind);

	return 0;
}

