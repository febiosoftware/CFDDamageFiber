call "%ONEAPI_ROOT%\setvars.bat"
set /a "PROC=%NUMBER_OF_PROCESSORS%"
cmake --version

SET STARTDIR=%cd%
SET SCRIPTDIR=%~dp0

cd %SCRIPTDIR%\..\..\

if not defined FEBIO_SDK set "FEBIO_SDK=%STARTDIR%\febio4-sdk"
set "FEBIO_SDK=%FEBIO_SDK:\=/%"      :: convert backslashes to forward slashes
set "BUILD_DIR=%CD%/cmbuild"

cmake -S . -B "%BUILD_DIR%" -DFEBio_SDK=%FEBIO_SDK%

cd "%BUILD_DIR%"
msbuild /P:Configuration=Release /P:WarningLevel=0 /m:%PROC% ALL_BUILD.vcxproj

cd "%STARTDIR%"
exit 0
