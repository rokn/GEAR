##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=OpenGIne
ConfigurationName      :=Debug
WorkspacePath          := "F:\Google Drive\Programming\OpenGL\CodeLite"
ProjectPath            := "F:\Google Drive\Programming\OpenGL\CodeLite\OpenGIne"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=amind
Date                   :=03/02/2016
CodeLitePath           :="F:\Programs\CodeLite"
LinkerName             :=F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/g++.exe
SharedObjectLinkerName :=F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)SFML_STATIC $(PreprocessorSwitch)GLEW_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="OpenGIne.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/windres.exe
LinkOptions            :=  -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d -lwinmm -lgdi32 -ljpeg -lfreetype -lglew32s -lopengl32
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../../Dependencies/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../../Dependencies/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/ar.exe rcu
CXX      := F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/g++.exe
CC       := F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=F:\Programs\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IntermediateDirectory)/shader.cpp$(ObjectSuffix) $(IntermediateDirectory)/camera.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/OpenGIne/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix): Engine.cpp $(IntermediateDirectory)/Engine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/OpenGIne/Engine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Engine.cpp$(DependSuffix): Engine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Engine.cpp$(DependSuffix) -MM "Engine.cpp"

$(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix): Engine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix) "Engine.cpp"

$(IntermediateDirectory)/shader.cpp$(ObjectSuffix): shader.cpp $(IntermediateDirectory)/shader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/OpenGIne/shader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/shader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/shader.cpp$(DependSuffix): shader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/shader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/shader.cpp$(DependSuffix) -MM "shader.cpp"

$(IntermediateDirectory)/shader.cpp$(PreprocessSuffix): shader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/shader.cpp$(PreprocessSuffix) "shader.cpp"

$(IntermediateDirectory)/camera.cpp$(ObjectSuffix): camera.cpp $(IntermediateDirectory)/camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/OpenGIne/camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/camera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/camera.cpp$(DependSuffix): camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/camera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/camera.cpp$(DependSuffix) -MM "camera.cpp"

$(IntermediateDirectory)/camera.cpp$(PreprocessSuffix): camera.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/camera.cpp$(PreprocessSuffix) "camera.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


