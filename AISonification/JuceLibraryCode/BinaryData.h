/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   Frog_7_png_png;
    const int            Frog_7_png_pngSize = 240;

    extern const char*   Fish_L_png;
    const int            Fish_L_pngSize = 381;

    extern const char*   Fish_R_png;
    const int            Fish_R_pngSize = 369;

    extern const char*   Fish_1_png;
    const int            Fish_1_pngSize = 372;

    extern const char*   Frog3_png_png;
    const int            Frog3_png_pngSize = 252;

    extern const char*   Frog5_png_png;
    const int            Frog5_png_pngSize = 237;

    extern const char*   Frog6_png_png;
    const int            Frog6_png_pngSize = 252;

    extern const char*   Frog1_png_png;
    const int            Frog1_png_pngSize = 264;

    extern const char*   Frog2_png_png;
    const int            Frog2_png_pngSize = 237;

    extern const char*   Log_3_png;
    const int            Log_3_pngSize = 270;

    extern const char*   Log_2_png;
    const int            Log_2_pngSize = 270;

    extern const char*   Log_1_png;
    const int            Log_1_pngSize = 270;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 12;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
