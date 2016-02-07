##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=GEAR
ConfigurationName      :=Debug
WorkspacePath          := "F:\Google Drive\Programming\OpenGL\CodeLite"
ProjectPath            := "F:\Google Drive\Programming\OpenGL\CodeLite\GEAR"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=amind
Date                   :=07/02/2016
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
ObjectsFileList        :="GEAR.txt"
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
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/engine.cpp$(ObjectSuffix) $(IntermediateDirectory)/shader.cpp$(ObjectSuffix) $(IntermediateDirectory)/camera.cpp$(ObjectSuffix) $(IntermediateDirectory)/glrenderer.cpp$(ObjectSuffix) $(IntermediateDirectory)/scene.cpp$(ObjectSuffix) $(IntermediateDirectory)/mesh.cpp$(ObjectSuffix) $(IntermediateDirectory)/model.cpp$(ObjectSuffix) $(IntermediateDirectory)/lightscene.cpp$(ObjectSuffix) $(IntermediateDirectory)/cube.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/resourcemanager.cpp$(ObjectSuffix) 



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

PostBuild:
	@echo Executing Post Build commands ...
	rm ./Debug/*.o
	rm ./Debug/*.d
	rm ./Debug/.d
	C:\Ruby22-x64\bin\ruby.exe F:/RubyScripts/copyToOutput.rb Content ./Debug GEAR.project
	@echo Done

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/engine.cpp$(ObjectSuffix): engine.cpp $(IntermediateDirectory)/engine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/engine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/engine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/engine.cpp$(DependSuffix): engine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/engine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/engine.cpp$(DependSuffix) -MM "engine.cpp"

$(IntermediateDirectory)/engine.cpp$(PreprocessSuffix): engine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/engine.cpp$(PreprocessSuffix) "engine.cpp"

$(IntermediateDirectory)/shader.cpp$(ObjectSuffix): shader.cpp $(IntermediateDirectory)/shader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/shader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/shader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/shader.cpp$(DependSuffix): shader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/shader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/shader.cpp$(DependSuffix) -MM "shader.cpp"

$(IntermediateDirectory)/shader.cpp$(PreprocessSuffix): shader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/shader.cpp$(PreprocessSuffix) "shader.cpp"

$(IntermediateDirectory)/camera.cpp$(ObjectSuffix): camera.cpp $(IntermediateDirectory)/camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/camera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/camera.cpp$(DependSuffix): camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/camera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/camera.cpp$(DependSuffix) -MM "camera.cpp"

$(IntermediateDirectory)/camera.cpp$(PreprocessSuffix): camera.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/camera.cpp$(PreprocessSuffix) "camera.cpp"

$(IntermediateDirectory)/glrenderer.cpp$(ObjectSuffix): glrenderer.cpp $(IntermediateDirectory)/glrenderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/glrenderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/glrenderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/glrenderer.cpp$(DependSuffix): glrenderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/glrenderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/glrenderer.cpp$(DependSuffix) -MM "glrenderer.cpp"

$(IntermediateDirectory)/glrenderer.cpp$(PreprocessSuffix): glrenderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/glrenderer.cpp$(PreprocessSuffix) "glrenderer.cpp"

$(IntermediateDirectory)/scene.cpp$(ObjectSuffix): scene.cpp $(IntermediateDirectory)/scene.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/scene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scene.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scene.cpp$(DependSuffix): scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scene.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scene.cpp$(DependSuffix) -MM "scene.cpp"

$(IntermediateDirectory)/scene.cpp$(PreprocessSuffix): scene.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scene.cpp$(PreprocessSuffix) "scene.cpp"

$(IntermediateDirectory)/mesh.cpp$(ObjectSuffix): mesh.cpp $(IntermediateDirectory)/mesh.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/mesh.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mesh.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mesh.cpp$(DependSuffix): mesh.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mesh.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mesh.cpp$(DependSuffix) -MM "mesh.cpp"

$(IntermediateDirectory)/mesh.cpp$(PreprocessSuffix): mesh.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mesh.cpp$(PreprocessSuffix) "mesh.cpp"

$(IntermediateDirectory)/model.cpp$(ObjectSuffix): model.cpp $(IntermediateDirectory)/model.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/model.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/model.cpp$(DependSuffix): model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/model.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/model.cpp$(DependSuffix) -MM "model.cpp"

$(IntermediateDirectory)/model.cpp$(PreprocessSuffix): model.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/model.cpp$(PreprocessSuffix) "model.cpp"

$(IntermediateDirectory)/lightscene.cpp$(ObjectSuffix): lightscene.cpp $(IntermediateDirectory)/lightscene.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/lightscene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lightscene.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lightscene.cpp$(DependSuffix): lightscene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lightscene.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/lightscene.cpp$(DependSuffix) -MM "lightscene.cpp"

$(IntermediateDirectory)/lightscene.cpp$(PreprocessSuffix): lightscene.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lightscene.cpp$(PreprocessSuffix) "lightscene.cpp"

$(IntermediateDirectory)/cube.cpp$(ObjectSuffix): cube.cpp $(IntermediateDirectory)/cube.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/cube.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cube.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cube.cpp$(DependSuffix): cube.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cube.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/cube.cpp$(DependSuffix) -MM "cube.cpp"

$(IntermediateDirectory)/cube.cpp$(PreprocessSuffix): cube.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cube.cpp$(PreprocessSuffix) "cube.cpp"

$(IntermediateDirectory)/resourcemanager.cpp$(ObjectSuffix): resourcemanager.cpp $(IntermediateDirectory)/resourcemanager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/CodeLite/GEAR/resourcemanager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/resourcemanager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/resourcemanager.cpp$(DependSuffix): resourcemanager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/resourcemanager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/resourcemanager.cpp$(DependSuffix) -MM "resourcemanager.cpp"

$(IntermediateDirectory)/resourcemanager.cpp$(PreprocessSuffix): resourcemanager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/resourcemanager.cpp$(PreprocessSuffix) "resourcemanager.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


