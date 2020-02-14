### Style Feedback for Lab 07

Run on February 14, 15:54:11 PM.


#### Necessary Files and Structure

+ Pass: Check that directory "cpplint" exists.

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab07_style_doxy" exists.

+ Pass: Change into directory "labs/lab07_style_doxy".

+ Pass: Check that directory "docs" exists.

+ Pass: Check that file "docs/Doxyfile" exists.


#### .gitignore configured properly

+ Pass: Check that file/directory "html" does not exist.

+ Pass: Check that file/directory "latex" does not exist.


#### Google Style Compliance

+ Pass: Check that file "src/mainpage.h" exists.

+ Pass: Ignoring mainpage.h



+ Fail: Cpplint checking for for Google C++ compliance

/export/scratch/cpplint-sherv029/./src/passenger.cc:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
/export/scratch/cpplint-sherv029/./src/passenger.cc:1:  Include the directory when naming .h files  [build/include] [4]
/export/scratch/cpplint-sherv029/./src/passenger.cc:9:  Should have a space between // and comment  [whitespace/comments] [4]
/export/scratch/cpplint-sherv029/./src/passenger.cc:10:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
/export/scratch/cpplint-sherv029/./src/passenger_factory.cc:58:  Redundant blank line at the start of a code block should be deleted.  [whitespace/blank_line] [2]
/export/scratch/cpplint-sherv029/./src/passenger_factory.cc:61:  Should have a space between // and comment  [whitespace/comments] [4]
/export/scratch/cpplint-sherv029/./src/passenger_factory.cc:71:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
/export/scratch/cpplint-sherv029/./src/passenger_factory.cc:71:  Extra space before ( in function call  [whitespace/parens] [4]
/export/scratch/cpplint-sherv029/./src/passenger.h:7:  #ifndef header guard has wrong style, please use: SRC_PASSENGER_H_  [build/header_guard] [5]
/export/scratch/cpplint-sherv029/./src/passenger.h:77:  #endif line should be "#endif  // SRC_PASSENGER_H_"  [build/header_guard] [5]
/export/scratch/cpplint-sherv029/./src/passenger.h:24:  At least two spaces is best between code and comments  [whitespace/comments] [2]
/export/scratch/cpplint-sherv029/./src/passenger.h:32:  Constructors callable with one argument should be marked explicit.  [runtime/explicit] [5]
/export/scratch/cpplint-sherv029/./src/passenger.h:63:  "private:" should be preceded by a blank line  [whitespace/blank_line] [3]
/export/scratch/cpplint-sherv029/./src/passenger.h:75:  Line ends in whitespace.  Consider deleting these extra spaces.  [whitespace/end_of_line] [4]
/export/scratch/cpplint-sherv029/./src/passenger.h:75:  Redundant blank line at the end of a code block should be deleted.  [whitespace/blank_line] [3]
/export/scratch/cpplint-sherv029/./src/passenger.h:77:  Could not find a newline character at the end of the file.  [whitespace/ending_newline] [5]

+ Skip: Getting mainpage.h back

  This test was not run because of an earlier failing test.


#### Doxygen

+ Pass: Change into directory "docs".

+ Pass: Generating documentation by running doxygen

+ Pass: Check that file "html/classPassenger.html" exists.

+ Pass: Check that file "html/classPassengerFactory.html" exists.

