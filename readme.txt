Thanks for downloading the source to GMOgre3D!

GMOgre3D is built using Microsoft Visual Studio 9.  There are no included Visual Studio 8 solution or project files, but there are free tools that will convert the current solution/project files to Microsoft Visual Studio 8.

I recommend compiling using the ReleaseStaticLib configuration as it compiles everything into a single DLL (except for the cg.dll which is an NVIDIA DLL).  The Release configuration can be used to compile into separate DLLs which is useful if you don't plan on using all the options that GMOgre3D needs, such as OpenGL support, particles, shaders, etc.  If you do this you must include a plugins.cfg file, and modify the SetOgre3DOptions() GM script function to specify the plugins.cfg and the new name of the GMOgre3D DLL.
