##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=harkov
ConfigurationName      :=Debug
WorkspacePath          := "D:\home\sdkfz000\trunk\harkov"
ProjectPath            := "D:\home\sdkfz000\trunk\harkov"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=kevx
Date                   :=6/24/2013
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="harkov.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)wininet $(LibrarySwitch)iphlpapi 
ArLibs                 :=  "libwininet" "libiphlpapi" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -Wall -O0  $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall  $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/file_walker$(ObjectSuffix) $(IntermediateDirectory)/utils$(ObjectSuffix) $(IntermediateDirectory)/http_gateway$(ObjectSuffix) $(IntermediateDirectory)/crypto$(ObjectSuffix) $(IntermediateDirectory)/unittest$(ObjectSuffix) $(IntermediateDirectory)/log4c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/home/sdkfz000/trunk/harkov/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/file_walker$(ObjectSuffix): file_walker.cpp $(IntermediateDirectory)/file_walker$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/home/sdkfz000/trunk/harkov/file_walker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/file_walker$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/file_walker$(DependSuffix): file_walker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/file_walker$(ObjectSuffix) -MF$(IntermediateDirectory)/file_walker$(DependSuffix) -MM "file_walker.cpp"

$(IntermediateDirectory)/file_walker$(PreprocessSuffix): file_walker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/file_walker$(PreprocessSuffix) "file_walker.cpp"

$(IntermediateDirectory)/utils$(ObjectSuffix): utils.cpp $(IntermediateDirectory)/utils$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/home/sdkfz000/trunk/harkov/utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils$(DependSuffix): utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils$(ObjectSuffix) -MF$(IntermediateDirectory)/utils$(DependSuffix) -MM "utils.cpp"

$(IntermediateDirectory)/utils$(PreprocessSuffix): utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils$(PreprocessSuffix) "utils.cpp"

$(IntermediateDirectory)/http_gateway$(ObjectSuffix): http_gateway.cpp $(IntermediateDirectory)/http_gateway$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/home/sdkfz000/trunk/harkov/http_gateway.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_gateway$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_gateway$(DependSuffix): http_gateway.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_gateway$(ObjectSuffix) -MF$(IntermediateDirectory)/http_gateway$(DependSuffix) -MM "http_gateway.cpp"

$(IntermediateDirectory)/http_gateway$(PreprocessSuffix): http_gateway.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_gateway$(PreprocessSuffix) "http_gateway.cpp"

$(IntermediateDirectory)/crypto$(ObjectSuffix): crypto.cpp $(IntermediateDirectory)/crypto$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/home/sdkfz000/trunk/harkov/crypto.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/crypto$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/crypto$(DependSuffix): crypto.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/crypto$(ObjectSuffix) -MF$(IntermediateDirectory)/crypto$(DependSuffix) -MM "crypto.cpp"

$(IntermediateDirectory)/crypto$(PreprocessSuffix): crypto.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/crypto$(PreprocessSuffix) "crypto.cpp"

$(IntermediateDirectory)/unittest$(ObjectSuffix): unittest.cpp $(IntermediateDirectory)/unittest$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/home/sdkfz000/trunk/harkov/unittest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/unittest$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/unittest$(DependSuffix): unittest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/unittest$(ObjectSuffix) -MF$(IntermediateDirectory)/unittest$(DependSuffix) -MM "unittest.cpp"

$(IntermediateDirectory)/unittest$(PreprocessSuffix): unittest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/unittest$(PreprocessSuffix) "unittest.cpp"

$(IntermediateDirectory)/log4c$(ObjectSuffix): log4c.cpp $(IntermediateDirectory)/log4c$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/home/sdkfz000/trunk/harkov/log4c.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/log4c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/log4c$(DependSuffix): log4c.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/log4c$(ObjectSuffix) -MF$(IntermediateDirectory)/log4c$(DependSuffix) -MM "log4c.cpp"

$(IntermediateDirectory)/log4c$(PreprocessSuffix): log4c.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/log4c$(PreprocessSuffix) "log4c.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/file_walker$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/file_walker$(DependSuffix)
	$(RM) $(IntermediateDirectory)/file_walker$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/utils$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/utils$(DependSuffix)
	$(RM) $(IntermediateDirectory)/utils$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/http_gateway$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/http_gateway$(DependSuffix)
	$(RM) $(IntermediateDirectory)/http_gateway$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/crypto$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/crypto$(DependSuffix)
	$(RM) $(IntermediateDirectory)/crypto$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/unittest$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/unittest$(DependSuffix)
	$(RM) $(IntermediateDirectory)/unittest$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/log4c$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/log4c$(DependSuffix)
	$(RM) $(IntermediateDirectory)/log4c$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/harkov"


