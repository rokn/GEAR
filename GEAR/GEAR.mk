##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=GEAR
ConfigurationName      :=Release
WorkspacePath          := "F:\Google Drive\Programming\OpenGL\GEAR"
ProjectPath            := "F:\Google Drive\Programming\OpenGL\GEAR\GEAR"
IntermediateDirectory  :=./Release
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
Preprocessors          :=$(PreprocessorSwitch)NDEBUG $(PreprocessorSwitch)SFML_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="GEAR.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/windres.exe
LinkOptions            :=  -lsfml-graphics -lsfml-window -lsfml-system -lwinmm -lgdi32 -ljpeg -lfreetype -lglew32 -lglew32mx -lopengl32
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)./Dependencies/include $(IncludeSwitch)../HelperLibrary/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)./Dependencies/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/ar.exe rcu
CXX      := F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/g++.exe
CC       := F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/gcc.exe
CXXFLAGS :=  -O2 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := F:/Programs/MinGW4.9.2/CodeBlocks/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=F:\Programs\CodeLite
Objects0=$(IntermediateDirectory)/src_camera.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_cube.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_engine.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_glrenderer.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_lightscene.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_mesh.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_model.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_resourcemanager.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_scene.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_shader.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "./Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_camera.cpp$(ObjectSuffix): src/camera.cpp $(IntermediateDirectory)/src_camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_camera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_camera.cpp$(DependSuffix): src/camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_camera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_camera.cpp$(DependSuffix) -MM "src/camera.cpp"

$(IntermediateDirectory)/src_camera.cpp$(PreprocessSuffix): src/camera.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_camera.cpp$(PreprocessSuffix) "src/camera.cpp"

$(IntermediateDirectory)/src_cube.cpp$(ObjectSuffix): src/cube.cpp $(IntermediateDirectory)/src_cube.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/cube.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_cube.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_cube.cpp$(DependSuffix): src/cube.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_cube.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_cube.cpp$(DependSuffix) -MM "src/cube.cpp"

$(IntermediateDirectory)/src_cube.cpp$(PreprocessSuffix): src/cube.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_cube.cpp$(PreprocessSuffix) "src/cube.cpp"

$(IntermediateDirectory)/src_engine.cpp$(ObjectSuffix): src/engine.cpp $(IntermediateDirectory)/src_engine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/engine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_engine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_engine.cpp$(DependSuffix): src/engine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_engine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_engine.cpp$(DependSuffix) -MM "src/engine.cpp"

$(IntermediateDirectory)/src_engine.cpp$(PreprocessSuffix): src/engine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_engine.cpp$(PreprocessSuffix) "src/engine.cpp"

$(IntermediateDirectory)/src_glrenderer.cpp$(ObjectSuffix): src/glrenderer.cpp $(IntermediateDirectory)/src_glrenderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/glrenderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_glrenderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_glrenderer.cpp$(DependSuffix): src/glrenderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_glrenderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_glrenderer.cpp$(DependSuffix) -MM "src/glrenderer.cpp"

$(IntermediateDirectory)/src_glrenderer.cpp$(PreprocessSuffix): src/glrenderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_glrenderer.cpp$(PreprocessSuffix) "src/glrenderer.cpp"

$(IntermediateDirectory)/src_lightscene.cpp$(ObjectSuffix): src/lightscene.cpp $(IntermediateDirectory)/src_lightscene.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/lightscene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lightscene.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lightscene.cpp$(DependSuffix): src/lightscene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lightscene.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lightscene.cpp$(DependSuffix) -MM "src/lightscene.cpp"

$(IntermediateDirectory)/src_lightscene.cpp$(PreprocessSuffix): src/lightscene.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lightscene.cpp$(PreprocessSuffix) "src/lightscene.cpp"

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM "src/main.cpp"

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) "src/main.cpp"

$(IntermediateDirectory)/src_mesh.cpp$(ObjectSuffix): src/mesh.cpp $(IntermediateDirectory)/src_mesh.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/mesh.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_mesh.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_mesh.cpp$(DependSuffix): src/mesh.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_mesh.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_mesh.cpp$(DependSuffix) -MM "src/mesh.cpp"

$(IntermediateDirectory)/src_mesh.cpp$(PreprocessSuffix): src/mesh.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_mesh.cpp$(PreprocessSuffix) "src/mesh.cpp"

$(IntermediateDirectory)/src_model.cpp$(ObjectSuffix): src/model.cpp $(IntermediateDirectory)/src_model.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_model.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_model.cpp$(DependSuffix): src/model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_model.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_model.cpp$(DependSuffix) -MM "src/model.cpp"

$(IntermediateDirectory)/src_model.cpp$(PreprocessSuffix): src/model.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_model.cpp$(PreprocessSuffix) "src/model.cpp"

$(IntermediateDirectory)/src_resourcemanager.cpp$(ObjectSuffix): src/resourcemanager.cpp $(IntermediateDirectory)/src_resourcemanager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/resourcemanager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_resourcemanager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_resourcemanager.cpp$(DependSuffix): src/resourcemanager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_resourcemanager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_resourcemanager.cpp$(DependSuffix) -MM "src/resourcemanager.cpp"

$(IntermediateDirectory)/src_resourcemanager.cpp$(PreprocessSuffix): src/resourcemanager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_resourcemanager.cpp$(PreprocessSuffix) "src/resourcemanager.cpp"

$(IntermediateDirectory)/src_scene.cpp$(ObjectSuffix): src/scene.cpp $(IntermediateDirectory)/src_scene.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/scene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_scene.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_scene.cpp$(DependSuffix): src/scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_scene.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_scene.cpp$(DependSuffix) -MM "src/scene.cpp"

$(IntermediateDirectory)/src_scene.cpp$(PreprocessSuffix): src/scene.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_scene.cpp$(PreprocessSuffix) "src/scene.cpp"

$(IntermediateDirectory)/src_shader.cpp$(ObjectSuffix): src/shader.cpp $(IntermediateDirectory)/src_shader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Google Drive/Programming/OpenGL/GEAR/GEAR/src/shader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_shader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_shader.cpp$(DependSuffix): src/shader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_shader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_shader.cpp$(DependSuffix) -MM "src/shader.cpp"

$(IntermediateDirectory)/src_shader.cpp$(PreprocessSuffix): src/shader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_shader.cpp$(PreprocessSuffix) "src/shader.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


